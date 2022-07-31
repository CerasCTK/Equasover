#include "polish_notation.h"

#include "../../core/exception/my_exception.h"

#include "../../util/string_helper/string_helper.h"

namespace util {
    void polish_notation::str_to_polish_form() {
        using namespace da_st;
        using namespace da_ty;

        array_list<string> *all_part_calculation = this->function_string->split(' ');
        int32_t size_of_pc_list = all_part_calculation->size();

        stack<string> sign_stack(size_of_pc_list);

        this->function_polish_form = new array_list<string>();

        for (int32_t i{0}; i < size_of_pc_list; i++) {
            if (this->sign_list->contains(all_part_calculation->get(i))) {
                if (all_part_calculation->get(i) == ((uint8_t *) ("("))) {
                    sign_stack.push(all_part_calculation->get(i));
                } else if (all_part_calculation->get(i) == ((uint8_t *) (")"))) {
                    while (sign_stack.top() != (uint8_t *) ("(")) {
                        this->function_polish_form->add(sign_stack.top());
                        sign_stack.pop();
                    }
                    sign_stack.pop();
                } else if (!sign_stack.empty() &&
                           op_manager->get_operator(all_part_calculation->get(i)).get_priority() <
                           op_manager->get_operator(sign_stack.top()).get_priority()) {
                    while (!sign_stack.empty() && sign_stack.top() != (uint8_t *) ("(")) {
                        this->function_polish_form->add(sign_stack.top());
                        sign_stack.pop();
                    }
                    sign_stack.push(all_part_calculation->get(i));
                } else
                    sign_stack.push(all_part_calculation->get(i));
            } else {
                this->function_polish_form->add(all_part_calculation->get(i));
            }
        }

        while (!sign_stack.empty()) {
            this->function_polish_form->add(sign_stack.top());
            sign_stack.pop();
        }
    }

    void polish_notation::replace_value(std::initializer_list<double> const &list_val) {
        std::initializer_list<double>::iterator it;

        it = list_val.begin();

        for (int32_t i{0}; i < this->function_polish_form->size(); i++) {
            if (this->variable_arraylist->contains(this->function_polish_form->get(i))) {
                this->function_polish_form->get(i) = string_helper::num_to_string(
                        *(it + this->variable_arraylist->index_of(this->function_polish_form->get(i))));
            }
        }
    }

    void polish_notation::variable_list_to_array() {
        using namespace da_st;
        using namespace da_ty;

        this->variable_arraylist = this->variable_list_str->split(' ');
    }

    polish_notation::~polish_notation() {
        if (this->function_string != nullptr)
            delete this->function_string;

        if (this->variable_list_str != nullptr)
            delete this->variable_list_str;

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
        this->variable_list_str = new da_ty::string(variables);
        this->variable_list_to_array();
        return this;
    }

    double polish_notation::calculate(std::initializer_list<double> const &list_val) {
        if (this->function_string == nullptr)
            throw my_exception((uint8_t *) ("The function is null"));

        if (this->variable_list_str == nullptr)
            throw my_exception((uint8_t *) ("The variable list is null"));

        if (list_val.size() < this->variable_arraylist->size())
            throw my_exception((uint8_t *) ("Insufficient number of values passed"));

        this->replace_value(list_val);

        int32_t scanner{0};
        while (this->function_polish_form->size() > 1) {
            if (this->sign_list->contains(this->function_polish_form->get(scanner))) {
                base_ope ope = op_manager->get_operator(this->function_polish_form->get(scanner));
                ope.get_calculator()(this->function_polish_form, scanner);
                scanner = 0;
            } else scanner++;
        }

        return string_helper::text_to_num(const_cast<uint8_t *>(this->function_polish_form->get(0).c_str()));
    }
}