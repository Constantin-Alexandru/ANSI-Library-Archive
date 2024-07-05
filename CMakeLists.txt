cmake_minimum_required(VERSION "3.26.2")

project(ANSI-Library)
add_library(ANSI-Library INTERFACE)
target_include_directories(ANSI-Library INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})