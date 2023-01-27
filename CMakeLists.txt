cmake_minimum_required(VERSION 3.24)
project(PP_WORK C)

set(CMAKE_C_STANDARD 99)

add_executable(PP_WORK main.c langton.c langton.h visualiser.c)
