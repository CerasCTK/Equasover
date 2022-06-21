cmake_minimum_required(VERSION 3.22)
project(GeneticAlgorithm)

set(CMAKE_CXX_STANDARD 20)

add_executable(GeneticAlgorithm src/main.cpp src/genetic-algorithm/genetic_algorithm.cpp src/genetic-algorithm/genetic_algorithm.h  src/core/data_structure/stack.cpp src/core/data_structure/stack.h src/util/polish_notation/polish_notation.cpp src/util/polish_notation/polish_notation.h src/core/exception/my_exception.cpp src/core/exception/my_exception.h src/util/string_helper/string_helper.cpp src/util/string_helper/string_helper.h)
