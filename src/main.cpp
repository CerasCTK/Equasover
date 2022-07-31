#include <iostream>

#include "util/string_helper/string_helper.h"
#include "util/math_helper/math_helper.h"
#include "core/data_type/string.h"
#include "core/data_structure/stack.h"
#include "core/data_structure/array_list.h"
#include "core/exception/my_exception.h"

#include "genetic-algorithm/polish_notation/polish_notation.h"
#include "genetic-algorithm/genetic_algorithm.h"

#include "genetic-algorithm/operator_system/operator_manager.h"

using namespace da_ty;
using namespace da_st;

using namespace string_helper;
using namespace math_helper;

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

    return 0;
}
//polish_notation *po = polish_notation::get_polish();
//
//    po->add_function((uint8_t *) "x + y + z");
//    po->init_variable_list((uint8_t *) "x y z");
//
//    array_list<double> temp = {1, 2, 3};
//
//    std::cout << po->calculate(temp);


/*
     * CODE TEST REMOVE ALL (ERROR)
     *
        array_list<int> test = {1, 2, 3, 1, 4, 5, 1, 3, 5};

        for (int sign_index{0}; sign_index < test.size(); sign_index++) {
            std::cout << test.get(sign_index) << std::endl;
        }

        std::cout << std::endl;

        test.remove_all(1);

        for (int sign_index{0}; sign_index < test.size(); sign_index++) {
            std::cout << test.get(sign_index) << std::endl;
    }
*/


