cmake_minimum_required(VERSION 2.8.12)
project(psi_bin LANGUAGES CXX)

#add_subdirectory(pybind11)
find_package(pybind11 REQUIRED)
pybind11_add_module(psi_bin MuSR_td_PSI_bin.cpp pybind.cpp)
