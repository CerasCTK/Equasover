#pragma once

#ifndef GENETICALGORITHM_POLISH_NOTATION_H
#define GENETICALGORITHM_POLISH_NOTATION_H

#include <cstdint>

namespace util {
    class polish_notation {
    private:
        uint8_t *function_string;
        uint8_t *variable_list;
        uint8_t *function_polish_form;

        polish_notation() = default;

    public:
        static polish_notation *get_polish();

        polish_notation *add_function(const uint8_t *function);

        polish_notation *init_variable_list(const uint8_t *variables);

        double calculate();

        ~polish_notation();
    };
}

#endif
