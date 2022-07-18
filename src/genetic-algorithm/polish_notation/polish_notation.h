#pragma once

#ifndef GENETICALGORITHM_POLISH_NOTATION_H
#define GENETICALGORITHM_POLISH_NOTATION_H

#include <cstdint>

#include "../../core/data_type/string.h"

#include "../../core/data_structure/array_list.h"
#include "../../core/data_structure/stack.h"

namespace util {
    class polish_notation {
    private:
        da_ty::string *function_string;
        da_ty::string *variable_list;

        da_st::stack<da_ty::string> *function_polish_form;

        da_st::array_list<da_ty::string> sign_list = {
                da_ty::string((uint8_t *) "("),
                da_ty::string((uint8_t *) ")"),

                da_ty::string((uint8_t *) "+"),
                da_ty::string((uint8_t *) "-"),
                da_ty::string((uint8_t *) "*"),
                da_ty::string((uint8_t *) "/"),
                da_ty::string((uint8_t *) "^")
        };

        polish_notation() = default;

        void str_to_polish_form();

    public:
        ~polish_notation();

        static polish_notation *get_polish();

        polish_notation *add_function(const uint8_t *function);

        polish_notation *init_variable_list(const uint8_t *variables);

        void print_polish_form();

        double calculate();
    };
}

#endif
