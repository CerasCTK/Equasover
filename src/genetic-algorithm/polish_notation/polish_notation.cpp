#include "polish_notation.h"

#include "../../core/exception/my_exception.h"

#include "../../util/string_helper/string_helper.h"

namespace util {
    polish_notation *polish_notation::get_polish() {
        polish_notation *po_no{new polish_notation};

        return po_no;
    }

    polish_notation *polish_notation::add_function(const uint8_t *function) {
        const int32_t function_length{string_helper::strlen(function)};

        this->function_string = new uint8_t[function_length + 1];

        string_helper::strcpy(this->function_string, function);

        return this;
    }

    polish_notation *polish_notation::init_variable_list(const uint8_t *variables) {


        return this;
    }

    double polish_notation::calculate() {
        if (this->function_string == nullptr)
            throw my_exception((uint8_t *) ("The function is null"));

        if (this->variable_list == nullptr)
            throw my_exception((uint8_t *) ("The variable list is null"));

        return 0;
    }

    polish_notation::~polish_notation() {
        if (this->function_string != nullptr)
            delete this->function_string;

        if (this->variable_list != nullptr)
            delete this->variable_list;

        if (this->function_polish_form != nullptr)
            delete this->function_polish_form;
    }
}