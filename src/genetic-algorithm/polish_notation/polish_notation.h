#pragma once

#ifndef GENETICALGORITHM_POLISH_NOTATION_H
#define GENETICALGORITHM_POLISH_NOTATION_H

#include <cstdint>

#include "../../core/data_type/string.h"

#include "../../core/data_structure/array_list.h"
#include "../../core/data_structure/stack.h"

#include "../operator_system/operator_manager.h"

namespace util {
    class polish_notation {
    private:
        /**
         * Function
         */
        da_ty::string *function_string;
        /**
         * Variables of function_string
         */
        da_ty::string *variable_list_str;

        /**
         * Function (Polish notation form)
         */
        da_st::array_list<da_ty::string> *function_polish_form;
        /**
         * List of variables
         */
        da_st::array_list<da_ty::string> *variable_arraylist;

        /**
         * Operator manager
         */
        operator_manager *op_manager{operator_manager::get_operator_manager()};

        /**
         * List of available operator
         */
        da_st::array_list<da_ty::string> *sign_list{op_manager->get_sign_list()};

        /**
         * Constructor
         */
        polish_notation() = default;

        /**
         * Convert function from string to Polish notation
         */
        void str_to_polish_form();

        /**
         * Replace variables with values
         * @param list_val - list of values
         */
        void replace_value(da_st::array_list<double> &list_val);

        /**
         * Convert variables string to array
         */
        void variable_list_to_array();

    public:
        /**
         * Destructor
         */
        ~polish_notation();

        /**
         * Get polish_notation object
         * @return polish_notation object
         */
        static polish_notation *get_polish();

        /**
         * Add function to polish_notation object
         * @param function
         * @return polish_notation object
         */
        polish_notation *add_function(const uint8_t *function);

        /**
         * Add variables to polish_notation object
         * @param variables
         * @return polish_notation object
         */
        polish_notation *init_variable_list(const uint8_t *variables);

        /**
         * Get number of variables
         * @return number of variables
         */
        int32_t get_number_of_variables();

        /**
         * Calculate function with values
         * @param list_val - list of values
         * @return value of function
         */
        double calculate(da_st::array_list<double> &list_val);
    };
}

#endif
