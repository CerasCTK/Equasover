#include "polish_notation.h"

#include "../../core/exception/my_exception.h"

#include "../string_helper/string_helper.h"

namespace util {
    polish_notation* polish_notation::get_polish() {
        polish_notation* po_no = new polish_notation;

        return po_no;
    }

    polish_notation* polish_notation::add_function(const char* function) {
        const int function_length = string_helper::strlen(function);

        this->function_string = new char[function_length + 1];

        string_helper::strcpy(this->function_string, function);

        return this;
    }

    polish_notation* polish_notation::init_variable_list(const char* variables) {
        int variablesa {0};

        return this;
    }

    double polish_notation::calculate() {
        if (this->function_string == nullptr) throw my_exception("The function is null");
        if (this->variable_list == nullptr) throw my_exception("The variable list is null");

        return 0;
    }
}