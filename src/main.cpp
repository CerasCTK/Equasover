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
    polish_notation *po = polish_notation::get_polish();
    po->add_function((uint8_t *) ("( x * y ) + sin ( z * 5 ^ t + 7 * 6 )"));
    po->init_variable_list((uint8_t *) ("x y z t"));

    std::cout << po->calculate({3, 5, 6, 7});

    return 0;
}

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


