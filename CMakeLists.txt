cmake_minimum_required(VERSION 3.22)
project(GeneticAlgorithm)

set(CMAKE_CXX_STANDARD 20)

add_executable(
        GeneticAlgorithm

        src/main.cpp

        src/genetic-algorithm/genetic_algorithm.cpp
        src/genetic-algorithm/genetic_algorithm.h

        src/core/data_structure/stack.cpp
        src/core/data_structure/stack.h

        src/genetic-algorithm/polish_notation/polish_notation.cpp
        src/genetic-algorithm/polish_notation/polish_notation.h

        src/core/exception/my_exception.cpp
        src/core/exception/my_exception.h

        src/util/string_helper/string_helper.cpp
        src/util/string_helper/string_helper.h

        src/core/data_structure/array_list.cpp
        src/core/data_structure/array_list.h

        src/core/data_type/string.cpp
        src/core/data_type/string.h

        src/util/math_helper/math_helper.cpp
        src/util/math_helper/math_helper.h

        src/core/data_type/config/cloneable.h

        src/genetic-algorithm/operator_system/operator_manager.cpp
        src/genetic-algorithm/operator_system/operator_manager.h

        src/genetic-algorithm/operator_system/base/base_ope.cpp
        src/genetic-algorithm/operator_system/base/base_ope.h)
