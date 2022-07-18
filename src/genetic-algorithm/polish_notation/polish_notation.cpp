#include "polish_notation.h"

#include "../../core/exception/my_exception.h"

#include "../../util/string_helper/string_helper.h"

#define TEST std::cout << "test" << std::endl;

namespace util {
    void polish_notation::str_to_polish_form() {
        using namespace da_st;
        using namespace da_ty;

        array_list<string> *all_part_calculation = this->function_string->split(' ');
        int32_t size_of_pc_list = all_part_calculation->size();

        stack<string> sign_stack(size_of_pc_list);

        this->function_polish_form = new stack<string>(size_of_pc_list);

        for (int32_t i{0}; i < size_of_pc_list; i++) {
            if (this->sign_list.contains(all_part_calculation->get(i))) {
//                if (all_part_calculation->get(i) == ((uint8_t *) (")"))) {
//                    int32_t temp{i - 1};
//                    while (all_part_calculation->get(temp) != ((uint8_t *) ("("))) {
//                        this->function_polish_form->push(all_part_calculation->get(temp));
//                        temp--;
//                    }
//                } else {
                std::cout << "if: " << all_part_calculation->get(i) << std::endl;
                    sign_stack.push(all_part_calculation->get(i));
//                }
            } else {
                std::cout << "else: " << all_part_calculation->get(i) << std::endl;
                this->function_polish_form->push(all_part_calculation->get(i));
            }
        }

        while (!sign_stack.empty()) {
            this->function_polish_form->push(sign_stack.top());
            sign_stack.pop();
        }

        std::cout << "list: ";
        for (int i{0}; i < this->function_polish_form->size(); i++) {
            std::cout << this->function_polish_form->top() << " ";
            this->function_polish_form->pop();
        }
        std::cout << std::endl;
    }

    polish_notation::~polish_notation() {
        if (this->function_string != nullptr)
            delete this->function_string;

        if (this->variable_list != nullptr)
            delete this->variable_list;

        if (this->function_polish_form != nullptr)
            delete this->function_polish_form;
    }

    polish_notation *polish_notation::get_polish() {
        return new polish_notation;
    }

    polish_notation *polish_notation::add_function(const uint8_t *function) {
        this->function_string = new da_ty::string(function);
        this->str_to_polish_form();
        return this;
    }

    polish_notation *polish_notation::init_variable_list(const uint8_t *variables) {
        this->variable_list = new da_ty::string(variables);
        return this;
    }

    void polish_notation::print_polish_form() {
        da_ty::string polish_form_str;

        std::cout << "size: " << this->function_polish_form->size() << std::endl;

        for (int32_t i{0}; i < this->function_polish_form->size(); i++) {
            polish_form_str += this->function_polish_form->top();
            polish_form_str += ((uint8_t) ' ');
            this->function_polish_form->pop();
        }

        std::cout << "Polish form str: " << polish_form_str << std::endl;
    }

    double polish_notation::calculate() {
        if (this->function_string == nullptr)
            throw my_exception((uint8_t *) ("The function is null"));

        if (this->variable_list == nullptr)
            throw my_exception((uint8_t *) ("The variable list is null"));

        return 0;
    }
}