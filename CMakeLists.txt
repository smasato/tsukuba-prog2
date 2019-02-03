cmake_minimum_required(VERSION 3.13)
set(CMAKE_C_EXTENSIONS OFF)

project(prog2 C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Wno-deprecated -std=c11")

add_executable(main main.c)
