cmake_minimum_required(VERSION 3.6)
project(Golomb)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Generator.cpp Coder.cpp Utils.cpp)
set(HEADER_FILES Generator.h Coder.h Utils.h)

add_executable(Golomb ${SOURCE_FILES})