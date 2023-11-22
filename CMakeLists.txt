cmake_minimum_required(VERSION 3.11)
project(musr2py LANGUAGES CXX)

include(FetchContent)

# when installing directly in CMake, redirect its intall root to dist dir
if (CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    set (CMAKE_INSTALL_PREFIX "${CMAKE_SOURCE_DIR}/dist" CACHE PATH "default install path" FORCE )
endif()

# Download PyBind11 as a dependency
# to use system  package the option below should be uncommented
#find_package(pybind11 REQUIRED)

FetchContent_Declare(
  pybind11
  URL https://github.com/pybind/pybind11/archive/v2.11.1.zip
)
FetchContent_GetProperties(pybind11)
FetchContent_MakeAvailable(pybind11)

# Add current directory to include path to make MuSR_td_PSI_bin.h visible
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Finally create the module
pybind11_add_module(musr2py MuSR_td_PSI_bin.cpp pybind.cpp)
