cmake_minimum_required(VERSION 2.6)
project(madgwick)

add_executable(madgwick main.cpp)

install(TARGETS madgwick RUNTIME DESTINATION bin)
