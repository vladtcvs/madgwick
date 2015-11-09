cmake_minimum_required(VERSION 2.6)
project(madgwick)

include_directories(${CMAKE_SOURCE_DIR})

add_library(madgwick STATIC main.c quaternion.c)

target_link_libraries(madgwick m)