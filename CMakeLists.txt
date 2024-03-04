cmake_minimum_required(VERSION "3.26.2")

project(ANSI-Library)
add_library(ANSI-Library INTERFACE)
target_include_directories(ANSI-Library INTERFACE 'ansi_lib.h')