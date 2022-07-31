#include <iostream>

#include "genetic-algorithm/genetic_algorithm.h"

#include "core/data_type/string.h"

using namespace da_ty;

using namespace util;

int main() {
    string function, variables;

    std::cout << "Input function: ";
    function.get_line();
    std::cout << "Input variables: ";
    variables.get_line();

    genetic_algorithm *genetic_algorithm{genetic_algorithm::init_ga()};

    genetic_algorithm->add_function(function);
    genetic_algorithm->add_variable(variables);

    double lower_threshold, upper_threshold;

    std::cout << "Input lower and upper threshold: ";
    std::cin >> lower_threshold >> upper_threshold;

    genetic_algorithm->set_lower_threshold(lower_threshold);
    genetic_algorithm->set_upper_threshold(upper_threshold);

    genetic_algorithm->run_algorithm();
    genetic_algorithm->show_output();

    return 0;
}



