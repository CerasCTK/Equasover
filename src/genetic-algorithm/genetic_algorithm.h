#pragma once

#ifndef GENETICALGORITHM_GENETIC_ALGORITHM_H
#define GENETICALGORITHM_GENETIC_ALGORITHM_H

#include <cstdint>

#include "polish_notation/polish_notation.h"

class genetic_algorithm {
private:
    /**
     * Polish notation system
     */
    util::polish_notation *po_no = util::polish_notation::get_polish();

    /**
     * Number of variables
     */
    int32_t num_var;

    /**
     * Size of population
     */
    int32_t population_size;

    /**
     * Number of evolutions
     */
    int32_t num_evo;

    /**
     *
     */
    double lower_threshold;

    /**
     *
     */
    double upper_threshold;

    /**
     * Array containing the set of values
     */
    double **generation;

    /**
     * Array to filter maximum value
     */
    double *max_sto;
    /**
     * Array to filter minimum value
     */
    double *min_sto;

    /**
     * Constructor
     */
    genetic_algorithm() = default;

public:
    /**
     * Destructor
     */
    ~genetic_algorithm();

    /**
     * Get genetic algorithm object
     * @return genetic_algorithm object
     */
    static genetic_algorithm *init_ga();

    /**
     * Add function to genetic algorithm
     * @param function
     */
    void add_function(da_ty::string function);

    /**
     * Add variables to genetic algorithm
     * @param variables
     */
    void add_variable(da_ty::string variables);

    /**
     *
     * @param size
     */
    void set_population_size(double size);

    /**
     *
     * @param nums
     */
    void set_num_evo(double nums);

    /**
     *
     * @param threshold
     */
    void set_lower_threshold(double threshold);

    /**
     *
     * @param threshold
     */
    void set_upper_threshold(double threshold);

    /**
     * Population initialization
     */
    void init_population();

    /**
     *
     */
    void evaluate();

    /**
     *
     */
    void selection();

    /**
     *
     */
    void cross_over();
};

#endif
