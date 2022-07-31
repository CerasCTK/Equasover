#include "operator_manager.h"

#include <cmath>

#include "../../util/string_helper/string_helper.h"

#include "../../core/exception/my_exception.h"

double plus_sign(da_st::array_list<da_ty::string> *polish_list, int32_t sign_index);
double minus_sign(da_st::array_list<da_ty::string> *polish_list, int32_t sign_index);
double multiple_sign(da_st::array_list<da_ty::string> *polish_list, int32_t sign_index);
double divide_sign(da_st::array_list<da_ty::string> *polish_list, int32_t sign_index);
double exponential_sign(da_st::array_list<da_ty::string> *polish_list, int32_t sign_index);

double sin(da_st::array_list<da_ty::string> *polish_list, int32_t sign_index);
double cos(da_st::array_list<da_ty::string> *polish_list, int32_t sign_index);
double tan(da_st::array_list<da_ty::string> *polish_list, int32_t sign_index);

void operator_manager::init_operator_list() {
    operator_list->clear();


    operator_list->add(base_ope((uint8_t *) ("("), -1, 0, nullptr));
    operator_list->add(base_ope((uint8_t *) (")"), 9999, 0, nullptr));

    operator_list->add(base_ope((uint8_t *) ("+"), 1, 2, plus_sign));
    operator_list->add(base_ope((uint8_t *) ("-"), 1, 2, minus_sign));
    operator_list->add(base_ope((uint8_t *) ("*"), 2, 2, multiple_sign));
    operator_list->add(base_ope((uint8_t *) ("/"), 2, 2, divide_sign));
    operator_list->add(base_ope((uint8_t *) ("^"), 2, 2, exponential_sign));

    operator_list->add(base_ope((uint8_t *) ("sin"), 1, 1, sin));
    operator_list->add(base_ope((uint8_t *) ("cos"), 1, 1, cos));
    operator_list->add(base_ope((uint8_t *) ("tan"), 1, 1, tan));
}

base_ope get_ope_from_fun(calculator cal) {
    operator_manager *op_manager = operator_manager::get_operator_manager();

    int32_t ope_list_size{op_manager->get_ope_list()->size()};

    for (int32_t i{0}; i < ope_list_size; i++) {
        if (cal == op_manager->get_ope_list()->get(i).get_calculator())
            return op_manager->get_ope_list()->get(i);
    }

    return DEFAULT_OPERATOR;
}

operator_manager *operator_manager::get_operator_manager() {
    operator_manager *op_manager = new operator_manager();
    op_manager->init_operator_list();
    return op_manager;
}

base_ope operator_manager::get_operator(da_ty::string sign) {
    if (operator_list->is_empty())
        init_operator_list();

    for (int32_t i{0}; i < operator_list->size(); i++) {
        if (sign == operator_list->get(i).get_ope_str())
            return operator_list->get(i);
    }

    return DEFAULT_OPERATOR;
}

da_st::array_list<da_ty::string> *operator_manager::get_sign_list() {
    if (operator_list->is_empty())
        init_operator_list();

    da_st::array_list<da_ty::string> *sign_list{new da_st::array_list<da_ty::string>};

    for (int32_t i{0}; i < operator_list->size(); i++)
        sign_list->add(operator_list->get(i).get_ope_str());

    return sign_list;
}

da_st::array_list<base_ope> *operator_manager::get_ope_list() {
    return this->operator_list;
}

double plus_sign(da_st::array_list<da_ty::string> *polish_list, int32_t sign_index) {
    base_ope this_ope = get_ope_from_fun(plus_sign);

    if (polish_list->size() < this_ope.get_influence() + 1)
        throw my_exception((uint8_t *) ("Not enough data to calculate"));

    double num[this_ope.get_influence()];

    for (int32_t i{0}; i < this_ope.get_influence(); i++) {
        num[i] = string_helper::text_to_num((uint8_t *) polish_list->get(sign_index - 1).c_str());
        polish_list->remove(sign_index - 1);
        sign_index--;
    }

    polish_list->get(sign_index) = string_helper::num_to_string(num[1] + num[0]);

    return num[0] + num[1];
}

double minus_sign(da_st::array_list<da_ty::string> *polish_list, int32_t sign_index) {
    base_ope this_ope = get_ope_from_fun(minus_sign);

    if (polish_list->size() < this_ope.get_influence() + 1)
        throw my_exception((uint8_t *) ("Not enough data to calculate"));

    double num[this_ope.get_influence()];

    for (int32_t i{0}; i < this_ope.get_influence(); i++) {
        num[i] = string_helper::text_to_num((uint8_t *) polish_list->get(sign_index - 1).c_str());
        polish_list->remove(sign_index - 1);
        sign_index--;
    }

    polish_list->get(sign_index) = string_helper::num_to_string(num[1] - num[0]);

    return num[1] - num[0];
}

double multiple_sign(da_st::array_list<da_ty::string> *polish_list, int32_t sign_index) {
    base_ope this_ope = get_ope_from_fun(multiple_sign);
    if (polish_list->size() < this_ope.get_influence() + 1)
        throw my_exception((uint8_t *) ("Not enough data to calculate"));

    double num[this_ope.get_influence()];

    for (int32_t i{0}; i < this_ope.get_influence(); i++) {
        num[i] = string_helper::text_to_num((uint8_t *) polish_list->get(sign_index - 1).c_str());

        polish_list->remove(sign_index - 1);

        sign_index--;
    }

    polish_list->get(sign_index) = string_helper::num_to_string(num[1] * num[0]);

    return num[1] * num[0];
}

double divide_sign(da_st::array_list<da_ty::string> *polish_list, int32_t sign_index) {
    base_ope this_ope = get_ope_from_fun(divide_sign);

    if (polish_list->size() < this_ope.get_influence() + 1)
        throw my_exception((uint8_t *) ("Not enough data to calculate"));

    double num[this_ope.get_influence()];

    for (int32_t i{0}; i < this_ope.get_influence(); i++) {
        num[i] = string_helper::text_to_num((uint8_t *) polish_list->get(sign_index - 1).c_str());
        polish_list->remove(sign_index - 1);
        sign_index--;
    }

    polish_list->get(sign_index) = string_helper::num_to_string(num[1] / num[0]);

    return num[1] / num[0];
}

double exponential_sign(da_st::array_list<da_ty::string> *polish_list, int32_t sign_index) {

    base_ope this_ope = get_ope_from_fun(exponential_sign);

    if (polish_list->size() < this_ope.get_influence() + 1)
        throw my_exception((uint8_t *) ("Not enough data to calculate"));

    double num[this_ope.get_influence()];

    for (int32_t i{0}; i < this_ope.get_influence(); i++) {
        num[i] = string_helper::text_to_num((uint8_t *) polish_list->get(sign_index - 1).c_str());
        polish_list->remove(sign_index - 1);
        sign_index--;
    }

    polish_list->get(sign_index) = string_helper::num_to_string(std::pow(num[1], num[0]));

    return pow(num[1], num[0]);
}

double sin(da_st::array_list<da_ty::string> *polish_list, int32_t sign_index) {
    base_ope this_ope = get_ope_from_fun(sin);

    if (polish_list->size() < this_ope.get_influence() + 1)
        throw my_exception((uint8_t *) ("Not enough data to calculate"));

    double num[this_ope.get_influence()];

    for (int32_t i{0}; i < this_ope.get_influence(); i++) {
        num[i] = string_helper::text_to_num((uint8_t *) polish_list->get(sign_index - 1).c_str());
        polish_list->remove(sign_index - 1);
        sign_index--;
    }

    polish_list->get(sign_index) = string_helper::num_to_string(sin(num[0] * std::numbers::pi / 180));

    return sin(num[0]);
}

double cos(da_st::array_list<da_ty::string> *polish_list, int32_t sign_index) {
    base_ope this_ope = get_ope_from_fun(cos);

    if (polish_list->size() < this_ope.get_influence() + 1)
        throw my_exception((uint8_t *) ("Not enough data to calculate"));

    double num[this_ope.get_influence()];

    for (int32_t i{0}; i < this_ope.get_influence(); i++) {
        num[i] = string_helper::text_to_num((uint8_t *) polish_list->get(sign_index - 1).c_str());
        polish_list->remove(sign_index - 1);
        sign_index--;
    }

    polish_list->get(sign_index) = string_helper::num_to_string(cos(num[0]));

    return cos(num[0]);
}

double tan(da_st::array_list<da_ty::string> *polish_list, int32_t sign_index) {
    base_ope this_ope = get_ope_from_fun(tan);

    if (polish_list->size() < this_ope.get_influence() + 1)
        throw my_exception((uint8_t *) ("Not enough data to calculate"));

    double num[this_ope.get_influence()];

    for (int32_t i{0}; i < this_ope.get_influence(); i++) {
        num[i] = string_helper::text_to_num((uint8_t *) polish_list->get(sign_index - 1).c_str());
        polish_list->remove(sign_index - 1);
        sign_index--;
    }

    polish_list->get(sign_index) = string_helper::num_to_string(tan(num[0]));

    return tan(num[0]);
}
