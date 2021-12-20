# musr2py

Reads PSI bin data in python. Actually just a wrapper around [MuSR_td_PSI_bin](http://lmu.web.psi.ch/docu/manuals/bulk_manuals/software/Class_MuSR_PSI/main.html).

# Example

    
    import musr2py
    bin_reader = musr2py.MuSR_td_PSI_bin()
    bin_reader.get_asymmetry_vector(0,1,1.0,1,10,10,1,1,0,0.0)    

# License
GPLv3
