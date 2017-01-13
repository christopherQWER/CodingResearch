cmake_minimum_required(VERSION 3.6)
project(CodingResearch)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp
                    Generators/Geometric.cpp
                    Generators/Arithmetical.cpp
                    Generators/Markov.cpp
                    Coders/Golomb.cpp
                    Coders/Huffman.cpp
                    Utils.cpp
                    Tests/Test.cpp)

set(HEADER_FILES Generators/Geometric.h
                    Generators/Arithmetical.h
                    Generators/Markov.h
                    Coders/Golomb.h
                    Coders/Huffman.h
                    Utils.h
                    Tests/Test.h)

add_executable(CodingResearch ${SOURCE_FILES})