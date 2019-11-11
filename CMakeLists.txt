cmake_minimum_required(VERSION 3.15)
project(customer_strategy_02 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(customer_strategy_02
        customerModule.c
        customerModule.h
        main.c)
