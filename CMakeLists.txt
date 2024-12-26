cmake_minimum_required(VERSION 3.27)
project(mamat C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(mamat
        common.h
        main.c
        stack.c
        stack.h
        student.c
)