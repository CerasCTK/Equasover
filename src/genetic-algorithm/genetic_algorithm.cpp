#include "genetic_algorithm.h"

#include "../util/math_helper/math_helper.h"

#include "../core/data_structure/array_list.h"

void sort(double *list, int32_t num_of_values, bool (*type)(double, double));
bool ascending_sort(double first, double second);
bool descending_sort(double first, double second);

genetic_algorithm::~genetic_algorithm() {

}

genetic_algorithm *genetic_algorithm::init_ga() {
    return new genetic_algorithm;
}

void genetic_algorithm::add_function(da_ty::string function) {
    this->po_no->add_function(function.data());
}

void genetic_algorithm::add_variable(da_ty::string variables) {
    this->po_no->init_variable_list(variables.data());

    this->num_var = po_no->get_number_of_variables();

    this->population_size = 100 + 10 * this->num_var;
    this->generation = new double*[this->population_size];
    this->max_sto = new double[this->population_size];
    this->min_sto = new double[this->population_size];

    this->num_evo = 100 + 10 * num_var;
}

void genetic_algorithm::set_population_size(double size) {
    this->population_size = size;

    this->generation = new double*[this->population_size];
    this->max_sto = new double[this->population_size];
    this->min_sto = new double[this->population_size];
}

void genetic_algorithm::set_num_evo(double nums) {
    this->num_evo = nums;
}

void genetic_algorithm::set_lower_threshold(double threshold) {
    this->lower_threshold = threshold;
}

void genetic_algorithm::set_upper_threshold(double threshold) {
    this->upper_threshold = threshold;
}

void genetic_algorithm::init_population() {
    for (int32_t i{0}; i < this->population_size; i++) {
        this->generation[i] = new double[num_var];

        for (int32_t j{0}; j < this->num_var; j++)
            this->generation[i][j] = math_helper::random_number(this->lower_threshold, this->upper_threshold);
    }
}

void genetic_algorithm::evaluate() {
    for (int32_t i{0}; i < this->population_size; i++) {
        da_st::array_list<double> values;

        for (int32_t j{0}; j < this->num_var; j++)
            values.add(this->generation[i][j]);

        this->max_sto[i] = po_no->calculate(values);
        this->min_sto[i] = po_no->calculate(values);
    }
}

void genetic_algorithm::selection() {

}

void genetic_algorithm::cross_over() {

}

void sort(double *list, int32_t num_of_values, bool (*type)(double, double)) {
    for (int32_t i{0}; i < num_of_values - 1; i++)
        for (int32_t j{i + 1}; j < num_of_values; j++)
            if (type(*(list + i), *(list + j)))
                *(list + i) = (*(list + i) + *(list + j)) - (*(list + j) = *(list + i));
}

bool ascending_sort(double first, double second) {
    return first > second;
}

bool descending_sort(double first, double second) {
    return first < second
}
