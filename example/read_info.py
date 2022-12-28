# coding: utf-8
import musr2py
bin_reader = musr2py.MuSR_td_PSI_bin()
bin_reader.read('./tdc_hifi_2022_01000.mdu')
print( bin_reader.get_sample(),
       bin_reader.get_comment(),
       bin_reader.get_field(),
       bin_reader.get_temp(),
       bin_reader.get_orient() )

