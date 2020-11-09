skip = [
        'MuSR_td_PSI_bin',
        '~MuSR_td_PSI_bin'
        ]

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
                    description = description.replace('\n','\\n').replace('"','\\"').replace('\<','<').replace('\>','>')
                    print("  .def(\"{name}\", &MuSR_td_PSI_bin::{name}, \"{desc}\")".format(name=name,desc=description))

                    break
                else:
                    description += line

