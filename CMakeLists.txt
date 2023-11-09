cmake_minimum_required(VERSION 3.26)
project(VS C)

set(CMAKE_C_STANDARD 11)

add_executable(VS
        main.c
        cpr.h
        cpr.c
        cJSON.h
        cJSON.c
        "patient information.h"
        "patient information.c")
