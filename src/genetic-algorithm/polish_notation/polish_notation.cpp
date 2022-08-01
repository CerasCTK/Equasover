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

    void polish_notation::replace_value(da_st::array_list<da_ty::string> *list, da_st::array_list<double> &list_val) {
        for (int32_t i{0}; i < list->size(); i++) {
            if (this->variable_arraylist->contains(list->get(i))) {
                list->get(i) = string_helper::num_to_string(
                        list_val.get(this->variable_arraylist->index_of(list->get(i))));
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

    int32_t polish_notation::get_number_of_variables() {
        if (this->variable_arraylist == nullptr || this->variable_arraylist->size() == 0)
            throw my_exception((uint8_t *) ("Please init variables list"));

        return this->variable_arraylist->size();
    }

    double polish_notation::calculate(da_st::array_list<double> &list_val) {
        if (this->function_string == nullptr)
            throw my_exception((uint8_t *) ("The function is null"));

        if (this->variable_list_str == nullptr)
            throw my_exception((uint8_t *) ("The variable list is null"));

        if (list_val.size() < this->variable_arraylist->size())
            throw my_exception((uint8_t *) ("Insufficient number of values passed"));

        da_st::array_list<da_ty::string> *list = new da_st::array_list<da_ty::string>;

        for (int32_t i{0}; i < this->function_polish_form->size(); i++)
            list->add(this->function_polish_form->get(i));

        this->replace_value(list, list_val);

        int32_t scanner{0};
        while (list->size() > 1) {
            if (this->sign_list->contains(list->get(scanner))) {
                base_ope ope = op_manager->get_operator(list->get(scanner));
                ope.get_calculator()(list, scanner);
                scanner = 0;
            } else scanner++;
        }

        return string_helper::text_to_num(const_cast<uint8_t *>(list->get(0).c_str()));
    }
}