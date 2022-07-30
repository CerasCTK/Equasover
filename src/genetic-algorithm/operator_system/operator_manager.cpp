#include "operator_manager.h"

#include <cmath>

double plus_sign(da_st::array_list<da_ty::string> *polish_stack);
double minus_sign(da_st::array_list<da_ty::string> *polish_stack);
double multiple_sign(da_st::array_list<da_ty::string> *polish_stack);
double divide_sign(da_st::array_list<da_ty::string> *polish_stack);
double exponential_sign(da_st::array_list<da_ty::string> *polish_stack);

double sin(da_st::array_list<da_ty::string> *polish_stack);
double cos(da_st::array_list<da_ty::string> *polish_stack);
double tan(da_st::array_list<da_ty::string> *polish_stack);

void operator_manager::init_operator_list() {
    operator_list.clear();

    operator_list.add(base_ope((uint8_t *) ("("), -1, 0, nullptr));
    operator_list.add(base_ope((uint8_t *) (")"), 9999, 0, nullptr));

    operator_list.add(base_ope((uint8_t *) ("+"), 1, 2, plus_sign));
    operator_list.add(base_ope((uint8_t *) ("-"), 1, 2, minus_sign));
    operator_list.add(base_ope((uint8_t *) ("*"), 2, 2, multiple_sign));
    operator_list.add(base_ope((uint8_t *) ("/"), 2, 2, divide_sign));
    operator_list.add(base_ope((uint8_t *) ("^"), 2, 2, exponential_sign));

    operator_list.add(base_ope((uint8_t *) ("sin"), 1, 1, sin));
    operator_list.add(base_ope((uint8_t *) ("cos"), 1, 1, cos));
    operator_list.add(base_ope((uint8_t *) ("tan"), 1, 1, tan));
}

operator_manager *operator_manager::get_operator_manager() {
    return new operator_manager();
}

base_ope operator_manager::get_operator(da_ty::string sign) {
    if (operator_list.is_empty())
        init_operator_list();

    for (int32_t i{0}; i < operator_list.size(); i++) {
        if (sign == operator_list.get(i).get_ope_str())
            return operator_list.get(i);
    }

    return DEFAULT_OPERATOR;
}

da_st::array_list<da_ty::string> *operator_manager::get_sign_list() {
    if (operator_list.is_empty())
        init_operator_list();

    da_st::array_list<da_ty::string> *sign_list{new da_st::array_list<da_ty::string>};

    for (int32_t i{0}; i < operator_list.size(); i++)
        sign_list->add(operator_list.get(i).get_ope_str());

    return sign_list;
}

double plus_sign(da_st::array_list<da_ty::string> *polish_stack) {

    return polish_stack->size();
}

double minus_sign(da_st::array_list<da_ty::string> *polish_stack) {
    return polish_stack->size();
}

double multiple_sign(da_st::array_list<da_ty::string> *polish_stack) {
    return polish_stack->size();
}

double divide_sign(da_st::array_list<da_ty::string> *polish_stack) {
    return polish_stack->size();
}

double exponential_sign(da_st::array_list<da_ty::string> *polish_stack) {
    return polish_stack->size();
}

double sin(da_st::array_list<da_ty::string> *polish_stack) {
    return polish_stack->size();
}

double cos(da_st::array_list<da_ty::string> *polish_stack) {
    return polish_stack->size();
}

double tan(da_st::array_list<da_ty::string> *polish_stack) {
    return polish_stack->size();
}
