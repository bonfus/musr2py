from string import Template

# These are already dealt with by pybind11
skip = [
        'MuSR_td_PSI_bin',
        '~MuSR_td_PSI_bin'
        ]

# == Remove type info when collecting arguments names
def replace_dict(where, what):
    for word, rword in what.items():
        where = where.replace(word, rword)
    return where

type_dict = {'int': '',
             'char': '',
             '*': '',
             '&': '',
             'double': '',
             'const' : ''
             }
# ==

code = ""
with open('MuSR_td_PSI_bin.cpp','r') as f:
    while True:
        line = f.readline()
        if line == '':
            break
        
        if '\\brief' in line:
            description = line
            while True:
                line = f.readline()
                if 'MuSR_td_PSI_bin::' in line:
                    retval, function = line.split('::')
                    if '*' in retval:
                        break
                    name = function.split('(')[0].strip()
                    if name in skip:
                        break
                    while not ( ')' in function):
                        function += f.readline()
                    params = function.split('(')[1].split(')')[0].split(',')
                    params = [replace_dict(x.replace('\n',''), type_dict).strip() for x in params]
                    params = [x for x in params if x!='']



                    description = description.replace('\n','\\n').replace('"','\\"').replace('\<','<').replace('\>','>')
                    if params:
                        params = ','.join(['py::arg("{}")'.format(x) for x in params]) + ','
                    else:
                        params = ''
                    code += "  .def(\"{name}\", &MuSR_td_PSI_bin::{name}, {params} \"{desc}\")\n".format(name=name,params=params, desc=description)

                    break
                else:
                    description += line


with open('pybind.tmpl', 'r') as f:
    src = Template(f.read())
    result = src.substitute({'generatedcode':code})
    print(result)
