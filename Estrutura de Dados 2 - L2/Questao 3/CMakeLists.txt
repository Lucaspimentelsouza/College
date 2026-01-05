cmake_minimum_required(VERSION 3.30)
project(untitled)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(untitled
        arvavl.c
        arvavl.h
        main.c)
