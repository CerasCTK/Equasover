#pragma once

#ifndef GENETICALGORITHM_POLISH_NOTATION_H
#define GENETICALGORITHM_POLISH_NOTATION_H

namespace util {
    class polish_notation {
    private:
        char *function_string;
        char *variable_list;
        char *function_polish_form;

        polish_notation() = default;

    public:
        static polish_notation *get_polish();

        polish_notation *add_function(const char *function);

        polish_notation *init_variable_list(const char *variables);

        double calculate();

        ~polish_notation();
    };
}

#endif
