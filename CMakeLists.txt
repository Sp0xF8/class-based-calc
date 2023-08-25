cmake_minimum_required(VERSION 3.15)

project(ClassCalculator)

set(CMAKE_CXX_STANDARD 20)


include_directories(inc/)



add_executable(ClassCalculator src/main.cpp src/baseCalc.cpp inc/baseCalc.h)