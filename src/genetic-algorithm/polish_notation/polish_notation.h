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
         *
         */
        da_ty::string *function_string;
        /**
         *
         */
        da_ty::string *variable_list_str;

        /**
         *
         */
        da_st::array_list<da_ty::string> *function_polish_form;
        /**
         *
         */
        da_st::array_list<da_ty::string> *variable_arraylist;

        /**
         *
         */
        operator_manager *op_manager{operator_manager::get_operator_manager()};

        /**
         *
         */
        da_st::array_list<da_ty::string> *sign_list{op_manager->get_sign_list()};

        /**
         *
         */
        polish_notation() = default;

        /**
         *
         */
        void str_to_polish_form();

        /**
         *
         * @param list_val
         */
        void replace_value(std::initializer_list<double> const &list_val);

        /**
         *
         */
        void variable_list_to_array();

    public:
        /**
         *
         */
        ~polish_notation();

        /**
         *
         * @return
         */
        static polish_notation *get_polish();

        /**
         *
         * @param function
         * @return
         */
        polish_notation *add_function(const uint8_t *function);

        /**
         *
         * @param variables
         * @return
         */
        polish_notation *init_variable_list(const uint8_t *variables);

        /**
         *
         * @param list_val
         * @return
         */
        double calculate(std::initializer_list<double> const &list_val);
    };
}

#endif
