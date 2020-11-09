#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "MuSR_td_PSI_bin.h"

// ----------------
// Python interface
// ----------------

namespace py = pybind11;

PYBIND11_MODULE(psi_bin,m)
{
  m.doc() = "pybind11 example plugin";

  py::class_<MuSR_td_PSI_bin>(m, "MuSR_td_PSI_bin")
  .def(py::init<>())
  // autogenerated by parse.py
  .def("read", &MuSR_td_PSI_bin::read, "/*! \brief Method to read a PSI-bin or an MDU file\n *\n *  This method gives back:\n *    - 0 for succesful reading\n *    - 1 if the open file action or the reading of the header failed\n *    - 2 for an unsupported version of the data\n *    - 3 for an error when allocating data buffer\n *    - 4 if number of histograms per record not equals 1\n *    - 5 if the number of histograms is less than 1\n *    - 6 if reading data failed\n *\n *  The parameter of the method is a const char * representing the name of the file to \n *  be opened.\n */\n\n")
  .def("readbin", &MuSR_td_PSI_bin::readbin, "/*! \brief Method to read a PSI-bin file\n *\n *  This method gives back:\n *    - 0 for succesful reading\n *    - 1 if the open file action or the reading of the header failed\n *    - 2 for an unsupported version of the data\n *    - 3 for an error when allocating data buffer\n *    - 4 if number of histograms per record not equals 1\n *    - 5 if the number of histograms is less than 1\n *    - 6 if reading data failed\n *\n *  The parameter of the method is a const char * representing the name of the file to \n *  be opened.\n */\n\n")
  .def("readmdu", &MuSR_td_PSI_bin::readmdu, "/*! \brief Method to read a MuSR MDU file\n *\n *  This method gives back:\n *    - 0 for succesful reading\n *    - 1 if the open file action or the reading of the header failed\n *    - 2 for an unsupported version of the data\n *    - 3 for an error when allocating data buffer\n *    - 5 if the number of histograms is less than 1\n *    - 6 if reading data failed\n *\n *  The parameter of the method is a const char * representing the name of the \n *  file to be opened.\n */\n\n")
  .def("readingOK", &MuSR_td_PSI_bin::readingOK, "/*! \brief Method to obtain if reading and processing of the data file was OK.\n *\n *  This method gives back:\n *    - true if reading was OK\n *    - false if reading was NOT OK\n */\n")
  .def("ReadStatus", &MuSR_td_PSI_bin::ReadStatus, "/*! \brief Method to obtain error/success information after reading.\n *\n *  This method gives back:\n *    - \"SUCCESS\"         if reading was OK\n *    - \"ERROR <message>\" if reading was NOT OK\n */\n")
  .def("Filename", &MuSR_td_PSI_bin::Filename, "/*! \brief Method to obtain the file name.\n *\n *  This method gives back:\n *    - <filename>\n */\n")
  .def("get_histo_int", &MuSR_td_PSI_bin::get_histo_int, "/*! \brief Method to return the value of a single bin as integer.\n *\n *  This method gives back:\n *    - bin value as int\n *    - 0 if an invalid histogram number or bin is choosen\n */\n")
  .def("get_histo", &MuSR_td_PSI_bin::get_histo, "/*! \brief Method to return the value of a single bin as double.\n *\n *  This method gives back:\n *    - bin value as double\n *    - 0 if an invalid histogram number or bin is choosen\n */\n")
  .def("get_histo_vector", &MuSR_td_PSI_bin::get_histo_vector, "/*! \brief Method to obtain a vector of double containing the values of the histogram \n      <histo_num> with binning <binning>\n *\n *  This method gives back:\n *    - a vector of double\n *    - an empty vector of double if an invalid number or binning is choosen\n *\n *  The parameters of the method are the integers <histo_num> and <binning> \n    representing the desired histogram number and binning.\n */\n\n")
  .def("get_histo_vector_no0", &MuSR_td_PSI_bin::get_histo_vector_no0, "/*! \brief Method to obtain a vector of double containing the values of the \n *   histogram <histo_num> with binning <binning> but where the bins with \n *   zero counts are replaced by a count 0.1\n *\n *  This method gives back:\n *    - a vector of double\n *    - an empty vector of double if an invalid number or binning is choosen\n *\n *  The parameters of the method are the integers <histo_num> and <binning> \n *  representing the desired histogram number and binning.\n */\n\n")
  .def("get_histo_fromt0_vector", &MuSR_td_PSI_bin::get_histo_fromt0_vector, "/*! \brief Method to obtain a vector of double containing the values of the histogram \n *   <histo_num> with binning <binning> from the point t0.  An <offset> can also \n *   be specified (otherwise = 0).\n *\n *  This method gives back:\n *    - a vector of double\n *    - an empty vector of double if an invalid histogram number or binning is choosen\n *\n *  The parameters of the method are the integers <histo_num> and <binning> \n *  representing the desired histogram number and binning.\n */\n\n")
  .def("get_histo_goodBins_vector", &MuSR_td_PSI_bin::get_histo_goodBins_vector, "/*! \brief Method to obtain a vector of double containing the values of the \n *   histogram <histo_num> with binning <binning> from the point first_good until \n *   last_good\n *\n *  This method gives back:\n *    - a vector of double\n *    - an empty vector of double if an invalid histogram number or binning is choosen\n *\n *  The parameters of the method are the integers <histo_num> and <binning> \n *  representing the desired histogram number and binning.\n */\n\n")
  .def("get_histo_fromt0_minus_bckgrd_vector", &MuSR_td_PSI_bin::get_histo_fromt0_minus_bckgrd_vector, "/*! \brief Method to obtain a vector of double containing the values of the \n *   histogram <histo_num> with binning <binning> from the point t0. A background \n *   calculated from the points <lower_bckgrd> and <higher_bckgrd> is subtracted. \n *   An <offset> can also be specified (otherwise = 0).\n *\n *  This method gives back:\n *    - a vector of double\n *    - an empty vector of double if one provides\n *       - an invalid histogram number\n *       - a binning smaller than 1\n *       - invalid background limits\n *\n *  The first parameters of the method are the integers <histo_num> and <binning> \n *  representing the desired histogram number and binning.\n *  Also the parameters <lower_bckgrd> and <higher_bckgrd> define the limits \n *  between which the background is calculated.\n */\n\n")
  .def("get_histo_goodBins_minus_bckgrd_vector", &MuSR_td_PSI_bin::get_histo_goodBins_minus_bckgrd_vector, "/*! \brief Method to obtain a vector of double containing the values of the histogram <histo_num>\n *   with binning <binning> from the point first_good until the point last_good. \n *   A background calculated from the points <lower_bckgrd> and <higher_bckgrd> \n *   is subtracted\n *\n *  This method gives back:\n *    - a vector of double\n *    - an empty vector of double if one provides\n *       - an invalid histogram number\n *       - a binning smaller than 1\n *       - invalid background limits\n *\n *  The first parameters of the method are the integers <histo_num> and <binning> \n *  representing the desired histogram number and binning.\n *  Also the parameters <lower_bckgrd> and <higher_bckgrd> define the limits \n *  between which the background is calculated.\n */\n\n")
  .def("get_asymmetry_vector", &MuSR_td_PSI_bin::get_asymmetry_vector, "/*! \brief Method to obtain a vector of double containing the values of the asymmetry between 2 histograms.\n *\n *  The asymmetry is calculated between the histograms <histo_num_plus> and <histo_num_minus> with an alpha parameter\n *  <alpha_param>. This method requires also a binning value <binning>, as well as the background limits for both histograms.\n *  An <offset> value from t_0 can also be specified (otherwise = 0).\n *  Also an <y_offset> can be given to shift artificially the curve on the y-axis (otherwise = 0).\n *\n *  This method gives back:\n *    - a vector of double\n *    - an empty vector of double if one provides\n *       - an invalid histogram number\n *       - a binning smaller than 1\n *       - invalid background limits\n *\n *  The first parameters of the method are the integers <histo_num_plus> and <histo_num_minus>, as well as the double <alpha_param>.\n *  Integers for the binning and for the background limits for both histograms.are also required.\n */\n\n")
  .def("get_error_asymmetry_vector", &MuSR_td_PSI_bin::get_error_asymmetry_vector, "/*! \brief Method to obtain a vector of double containing the values of the error of the asymmetry between 2 histograms.\n *\n *  The error of the asymmetry is calculated with the histograms <histo_num_plus> and <histo_num_minus> with an alpha parameter\n *  <alpha_param>. This method requires also a binning value <binning>, as well as the background limits for both histograms.\n *  An <offset> value from t_0 can also be specified (otherwise = 0)\n *\n *  This method gives back:\n *    - a vector of double\n *    - an empty vector of double if one provides\n *       - an invalid histogram number\n *       - a binning smaller than 1\n *       - invalid background limits\n *\n *  The first parameters of the method are the integers <histo_num_plus> and <histo_num_minus>, as well as the double <alpha_param>.\n *  Integers for the binning and for the background limits for both histograms.are also required.\n */\n\n")
  .def("get_asymmetry_goodBins_vector", &MuSR_td_PSI_bin::get_asymmetry_goodBins_vector, "/*! \brief Method to obtain a vector of double containing the values of the asymmetry between 2 histograms.\n *\n *  The vector has a size corresponding to the minimum interval between first_good and last_good.\n *  It begins at the first_good coming at the latest after the corresponding t_0.\n *  The asymmetry is calculated between the histograms <histo_num_plus> and <histo_num_minus> with an alpha parameter\n *  <alpha_param>. This method requires also a binning value <binning>, as well as the background limits for both histograms.\n *\n *  This method gives back:\n *    - a vector of double\n *    - an empty vector of double if one provides\n *       - an invalid histogram number\n *       - a binning smaller than 1\n *       - invalid background limits\n *\n *  The first parameters of the method are the integers <histo_num_plus> and <histo_num_minus>, as well as the double <alpha_param>.\n *  Integers for the binning and for the background limits for both histograms.are also required.\n */\n\n")
  .def("get_error_asymmetry_goodBins_vector", &MuSR_td_PSI_bin::get_error_asymmetry_goodBins_vector, "/*! \brief Method to obtain a vector of double containing the values of the error of \n *   the asymmetry between 2 histograms.\n *\n *  The size is calculated as the asymmetry array.\n *  The error of the asymmetry is calculated with the histograms <histo_num_plus> and \n *  <histo_num_minus> with an alpha parameter <alpha_param>. This method requires \n *  also a binning value <binning>, as well as the background limits for both \n *  histograms.\n *\n *  This method gives back:\n *    - a vector of double\n *    - an empty vector of double if one provides\n *       - an invalid histogram number\n *       - a binning smaller than 1\n *       - invalid background limits\n *\n *  The first parameters of the method are the integers <histo_num_plus> and \n *  <histo_num_minus>, as well as the double <alpha_param>.\n *  Integers for the binning and for the background limits for both histograms.are also required.\n */\n\n")
  .def("get_numberScaler_int", &MuSR_td_PSI_bin::get_numberScaler_int, "/*! \brief Method returning an integer representing the number of histograms\n */\n\n")
  .def("get_scalers_vector", &MuSR_td_PSI_bin::get_scalers_vector, "/*! \brief Method providing a vector of long containing the values of the scalers\n */\n\n")
  .def("get_max_t0_int", &MuSR_td_PSI_bin::get_max_t0_int, "/*! \brief Method to determine the maximum value of the t0 bins\n */\n\n")
  .def("get_max_2_t0_int", &MuSR_td_PSI_bin::get_max_2_t0_int, "/*! \brief Method to determine the maximum value of the last good bins of 2 histograms\n *\n *  returns -1 if the numbers of the histograms are invalid\n */\n\n")
  .def("get_min_2_t0_int", &MuSR_td_PSI_bin::get_min_2_t0_int, "/*! \brief Method to determine the minimum value of the last good bins of 2 histograms\n *\n *  returns -1 if the numbers of the histograms are invalid\n */\n\n")
  .def("get_min_t0_int", &MuSR_td_PSI_bin::get_min_t0_int, "/*! \brief Method to determine the minimum value of the t0 bins\n */\n\n")
  .def("get_binWidth_ps", &MuSR_td_PSI_bin::get_binWidth_ps, "/*! \brief Method returning a double representing the bin-width in picoseconds\n */\n\n")
  .def("get_binWidth_ns", &MuSR_td_PSI_bin::get_binWidth_ns, "/*! \brief Method returning a double representing the bin-width in nanoseconds\n */\n\n")
  .def("get_binWidth_us", &MuSR_td_PSI_bin::get_binWidth_us, "/*! \brief Method returning a double representing the bin-width in microseconds\n */\n\n")
  .def("get_histoLength_bin", &MuSR_td_PSI_bin::get_histoLength_bin, "/*! \brief Method returning an integer representing the histogram length in bins\n */\n\n")
  .def("get_numberHisto_int", &MuSR_td_PSI_bin::get_numberHisto_int, "/*! \brief Method returning an integer representing the number of histograms\n */\n\n")
  .def("get_totalEvents_long", &MuSR_td_PSI_bin::get_totalEvents_long, "/*! \brief Method returning a long representing the total number of events\n */\n\n")
  .def("get_eventsHisto_long", &MuSR_td_PSI_bin::get_eventsHisto_long, "/*! \brief Method returning a long representing the number of events in a specified histograms\n *\n *  A value of -1 is returned if the value of the histogram <i> specified is invalid.\n */\n\n")
  .def("get_eventsHisto_vector", &MuSR_td_PSI_bin::get_eventsHisto_vector, "/*! \brief Method returning a vector of long containing the number of events in the histograms\n */\n\n")
  .def("get_t0_double", &MuSR_td_PSI_bin::get_t0_double, "/*! \brief Method returning a double representing the t0 point (from the \"real\" t0 in the header) for a specified histogram\n *\n *  A value of -1. is returned if the value of the histogram <i> specified is invalid.\n */\n\n")
  .def("get_default_binning", &MuSR_td_PSI_bin::get_default_binning, "/*! \brief Method returning an integer representing the default binning\n *\n */\n")
  .def("get_t0_int", &MuSR_td_PSI_bin::get_t0_int, "/*! \brief Method returning an integer representing the t0 point (from the \"integer\" t0 in the header) for a specified histogram\n *\n *  A value of -1 is returned if the value of the histogram <i> specified is invalid.\n */\n\n")
  .def("get_t0_vector", &MuSR_td_PSI_bin::get_t0_vector, "/*! \brief Method returning a vector of integer containing the t0 values of the histograms specified in the header\n */\n\n")
  .def("get_firstGood_int", &MuSR_td_PSI_bin::get_firstGood_int, "/*! \brief Method returning an integer representing the first good bin specified in the header for a specified histogram\n *\n *  A value of -1 is returned if the value of the histogram <i> specified is invalid.\n */\n\n")
  .def("get_firstGood_vector", &MuSR_td_PSI_bin::get_firstGood_vector, "/*! \brief Method returning a vector of integer containing the first good bin values of the histograms specified in the header\n */\n\n")
  .def("put_firstGood_int", &MuSR_td_PSI_bin::put_firstGood_int, "/*! \brief Method to modify the first good bin (value <j>) of the histogram <i>\n *\n *  returns -1 if the histogram specified was invalid\n */\n\n")
  .def("get_lastGood_int", &MuSR_td_PSI_bin::get_lastGood_int, "/*! \brief Method returning an integer representing the last good bin specified in the header for a specified histogram\n *\n *  A value of -1 is returned if the value of the histogram <i> specified is invalid.\n */\n\n")
  .def("get_lastGood_vector", &MuSR_td_PSI_bin::get_lastGood_vector, "/*! \brief Method returning a vector of integer containing the last good bin values of the histograms specified in the header\n */\n\n")
  .def("get_max_lastGood_int", &MuSR_td_PSI_bin::get_max_lastGood_int, "/*! \brief Method returning an integer containing the maximum value of the \"last good bins\" of all histograms\n */\n\n")
  .def("get_max_2_lastGood_int", &MuSR_td_PSI_bin::get_max_2_lastGood_int, "/*! \brief Method to determine the maximum value of the \"last good bins\" of 2 histograms\n *\n *  returns -1 if something is invalid\n */\n\n")
  .def("get_min_lastGood_int", &MuSR_td_PSI_bin::get_min_lastGood_int, "/*! \brief Method providing the minimum value of the last good bins\n */\n\n")
  .def("get_min_2_lastGood_int", &MuSR_td_PSI_bin::get_min_2_lastGood_int, "/*! \brief Method to determine the minimum value of the last good bins of 2 histograms\n *\n *  returns -1 if something is invalid\n */\n\n")
  .def("put_lastGood_int", &MuSR_td_PSI_bin::put_lastGood_int, "/*! \brief Method to modify the last good bin (value <j>) of the histogram <i>\n *\n *  returns -1 if the histogram specified was invalid\n */\n\n")
  .def("get_runNumber_int", &MuSR_td_PSI_bin::get_runNumber_int, "/*! \brief Method returning an integer containing the run number\n */\n\n")
  .def("put_runNumber_int", &MuSR_td_PSI_bin::put_runNumber_int, "/*! \brief Method to modify the run number (value <i>)\n *\n *  returns -1 if the integer specified was wrong\n */\n\n")
  .def("get_sample", &MuSR_td_PSI_bin::get_sample, "/*! \brief Method returning a string containing the sample name\n */\n\n")
  .def("get_temp", &MuSR_td_PSI_bin::get_temp, "/*! \brief Method returning a string containing the temperature specified in the title\n */\n\n")
  .def("get_orient", &MuSR_td_PSI_bin::get_orient, "/*! \brief Method returning a string containing the orientation specified in the title\n */\n\n")
  .def("get_field", &MuSR_td_PSI_bin::get_field, "/*! \brief Method returning a string containing the field specified in the title\n */\n\n")
  .def("get_comment", &MuSR_td_PSI_bin::get_comment, "/*! \brief Method returning a string containing the comment specified in the title\n */\n\n")
  .def("get_nameHisto", &MuSR_td_PSI_bin::get_nameHisto, "/*! \brief Method returning a string containing the name of the histogram <i>\n *\n *  returns NULL if the histogram specified is invalid\n */\n\n")
  .def("get_histoNames_vector", &MuSR_td_PSI_bin::get_histoNames_vector, "/*! \brief Method returning a vector of strings containing the names of the histograms\n */\n\n")
  .def("get_scalersNames_vector", &MuSR_td_PSI_bin::get_scalersNames_vector, "/*! \brief Method returning a vector of strings containing the names of the scalers\n */\n\n")
  .def("get_numberTemperature_int", &MuSR_td_PSI_bin::get_numberTemperature_int, "/*! \brief Method returning an integer representing the number of temperatures\n */\n\n")
  .def("get_temperatures_vector", &MuSR_td_PSI_bin::get_temperatures_vector, "/*! \brief Method returning a vector of doubles containing monitored values (usually temperatures)\n */\n\n")
  .def("get_devTemperatures_vector", &MuSR_td_PSI_bin::get_devTemperatures_vector, "/*! \brief Method returning a vector of doubles containing standard deviations of the monitored values (usually temperatures)\n */\n\n")
  .def("get_timeStart_vector", &MuSR_td_PSI_bin::get_timeStart_vector, "/*! \brief Method returning a vector of strings containing 1) the date when the run was \n *   started and 2) the time when the run was started\n */\n\n")
  .def("get_timeStop_vector", &MuSR_td_PSI_bin::get_timeStop_vector, "/*! \brief Method returning a vector of strings containing 1) the date when the run was \n *   stopped and 2) the time when the run was stopped\n */\n\n")
  .def("Clear", &MuSR_td_PSI_bin::Clear, "/*! \brief Method to clear member variables before using instance for next read\n */\n\n")
  .def("Show", &MuSR_td_PSI_bin::Show, "/*! \brief Method to show current values of member variables\n */\n\n")

  .def("__repr__",
    [](const MuSR_td_PSI_bin &a) {
      return "<psi_bin.MuSR_td_PSI_bin>";
    }
  );
}
