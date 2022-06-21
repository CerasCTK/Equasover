cmake_minimum_required(VERSION 3.22)
project(GeneticAlgorithm)

set(CMAKE_CXX_STANDARD 20)

add_executable(GeneticAlgorithm src/main.cpp src/genetic-algorithm/genetic_algorithm.cpp src/genetic-algorithm/genetic_algorithm.h src/util/my_string/my_string.cpp src/util/my_string/my_string.h src/core/data_structure/stack.cpp src/core/data_structure/stack.h)
