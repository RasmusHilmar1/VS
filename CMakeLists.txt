cmake_minimum_required(VERSION 3.26)
project(VS C)

set(CMAKE_C_STANDARD 11)

add_executable(VS
        main.c
        cpr.h
        cpr.c
        login.c
        login.h
        patient information.c
        patient information.h
        cJSON.c
        cJSON.h
        dosage.c
        dosage.h
)
