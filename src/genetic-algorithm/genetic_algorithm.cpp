#include "genetic_algorithm.h"

#include <unistd.h>

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

    this->max_generation = new double*[this->population_size];
    this->min_generation = new double*[this->population_size];

    this->max_storage = new double[this->population_size];
    this->min_storage = new double[this->population_size];

    this->num_evo = 100 + 10 * num_var;
    this->num_crosses = this->population_size / 5;
}

void genetic_algorithm::set_population_size(double size) {
    this->population_size = size;

    this->max_generation = new double*[this->population_size];
    this->min_generation = new double*[this->population_size];

    this->max_storage = new double[this->population_size];
    this->min_storage = new double[this->population_size];
}

void genetic_algorithm::set_num_evo(double nums) {
    this->num_evo = nums;
}

void genetic_algorithm::set_num_crosses(double crosses) {
    this->num_crosses = crosses;
}

void genetic_algorithm::set_lower_threshold(double threshold) {
    this->lower_threshold = threshold;
}

void genetic_algorithm::set_upper_threshold(double threshold) {
    this->upper_threshold = threshold;
}

void genetic_algorithm::init_population() {
    for (int32_t i{0}; i < this->population_size; i++) {
        this->max_generation[i] = new double[num_var];
        this->min_generation[i] = new double[num_var];

        for (int32_t j{0}; j < this->num_var; j++) {
            this->max_generation[i][j] = math_helper::random_number(this->lower_threshold, this->upper_threshold);
            sleep(5);
            this->min_generation[i][j] = math_helper::random_number(this->lower_threshold, this->upper_threshold);
        }
    }
}

void genetic_algorithm::evaluate() {
    for (int32_t i{0}; i < this->population_size; i++) {
        da_st::array_list<double> max_values;
        da_st::array_list<double> min_values;

        for (int32_t j{0}; j < this->num_var; j++) {
            max_values.add(this->max_generation[i][j]);
            min_values.add(this->min_generation[i][j]);
        }

        this->max_storage[i] = po_no->calculate(max_values);
        this->min_storage[i] = po_no->calculate(min_values);
    }
}

void genetic_algorithm::selection() {
    double *max_temp_list{new double[this->population_size]};
    double *min_temp_list{new double[this->population_size]};

    int32_t selection_threshold = this->population_size * 80 / 100; // 80%

    for (int32_t i{0}; i < this->population_size; i++)
        *(max_temp_list + i) = *(this->max_storage + i);

    sort(max_temp_list, this->population_size, descending_sort);
    double max_threshold{*(max_temp_list + selection_threshold)};

    for (int32_t i{0}; i < this->population_size; i++)
        *(min_temp_list + i) = *(this->min_storage + i);

    sort(min_temp_list, this->population_size, ascending_sort);
    double min_threshold{*(min_temp_list + selection_threshold)};

    for (int32_t i{0}; i < this->population_size; i++) {
        if (*(this->max_storage + i) < max_threshold) {
            max_generation[i] = max_generation[math_helper::random_int_number(0, this->population_size)];
        }
        if (*(this->min_storage + i) > min_threshold) {
            min_generation[i] = min_generation[math_helper::random_int_number(0, this->population_size)];
        }
    }

}

void genetic_algorithm::cross_over() {
    for (int32_t i{0}; i < this->num_crosses; i++) {
        int32_t dad{math_helper::random_int_number(0, this->population_size)};
        int32_t mom{math_helper::random_int_number(0, this->population_size)};

        for (int32_t j{0}; j < this->num_var; j++) {
            if (math_helper::random_int_number(0, 2)) {
                double temp{this->max_generation[dad][j]};
                this->max_generation[dad][j] = this->max_generation[mom][j];
                this->max_generation[mom][j] = temp;
            }
        }
    }

    for (int32_t i{0}; i < this->num_crosses; i++) {
        int32_t dad{math_helper::random_int_number(0, this->population_size)};
        int32_t mom{math_helper::random_int_number(0, this->population_size)};

        for (int32_t j{0}; j < this->num_var; j++) {
            if (math_helper::random_int_number(0, 2)) {
                double temp{this->min_generation[dad][j]};
                this->min_generation[dad][j] = this->min_generation[mom][j];
                this->min_generation[mom][j] = temp;
            }
        }
    }
}

void genetic_algorithm::mutation() {
    int32_t max_index{math_helper::random_int_number(0, this->population_size)};
    int32_t min_index{math_helper::random_int_number(0, this->population_size)};

    int32_t max_bit{math_helper::random_int_number(0, this->num_var)};
    int32_t min_bit{math_helper::random_int_number(0, this->num_var)};

    this->max_generation[max_index][max_bit] = math_helper::random_number(lower_threshold, upper_threshold);
    this->min_generation[min_index][min_bit] = math_helper::random_number(lower_threshold, upper_threshold);
}

void genetic_algorithm::run_algorithm() {
    this->init_population();

    for (int32_t i{0}; i < this->num_evo; i++) {
        this->evaluate();
        this->selection();
        this->cross_over();
        this->mutation();
    }
}

void genetic_algorithm::show_output() {
    double *max_temp_list{new double[this->population_size]};
    double *min_temp_list{new double[this->population_size]};

    for (int32_t i{0}; i < this->population_size; i++)
        *(max_temp_list + i) = *(this->max_storage + i);

    sort(max_temp_list, this->population_size, descending_sort);

    for (int32_t i{0}; i < this->population_size; i++)
        *(min_temp_list + i) = *(this->min_storage + i);

    sort(min_temp_list, this->population_size, ascending_sort);

    std::cout << "Max: " << max_temp_list[0] << std::endl;
    std::cout << "Min: " << min_temp_list[0] << std::endl;
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
    return first < second;
}
