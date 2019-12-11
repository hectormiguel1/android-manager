cmake_minimum_required(VERSION 2.45)
project(android_manager C)

set(CMAKE_C_STANDARD 11)

add_executable(android_manager main.c adb.c adb.h)