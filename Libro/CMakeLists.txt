cmake_minimum_required(VERSION 3.27)
project(Learning C)

set(CMAKE_C_STANDARD 11)

add_executable(LibroCh1 main.c
        Headers.h
        Pointers.c
        StringFunctions.c
        stack.c
)