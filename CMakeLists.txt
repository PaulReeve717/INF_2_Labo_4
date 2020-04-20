cmake_minimum_required(VERSION 3.15)
project(LABO4)

set(CMAKE_CXX_STANDARD 11)

add_executable(LABO4 main.cpp produit.cpp produit.h exceptions.cpp exceptions.h collection_g.h)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wconversion -Wextra -Wsign-conversion -pedantic")