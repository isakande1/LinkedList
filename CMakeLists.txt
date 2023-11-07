cmake_minimum_required(VERSION 3.26)
project(Linkedlist C)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -ansi -Wall -Wextra -Wpedantic -Werror ")

add_executable(Linkedlist main.c)
