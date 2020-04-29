cmake_minimum_required(VERSION 3.15)
project(showboat)

set(CMAKE_CXX_STANDARD 14)

add_executable(showboat main.cpp showData.h showData.cpp sqlite3.h sqlite3.c)