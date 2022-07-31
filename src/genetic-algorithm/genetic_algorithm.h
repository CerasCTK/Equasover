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
     * Number of crosses
     */
    int32_t num_crosses;

    /**
     *
     */
    double lower_threshold;

    /**
     *
     */
    double upper_threshold;

    /**
     * Array containing the set of values (max)
     */
    double **max_generation;

    /**
     * Array containing the set of values (min)
     */
    double **min_generation;

    /**
     * Array to filter maximum value
     */
    double *max_storage;
    /**
     * Array to filter minimum value
     */
    double *min_storage;

    /**
     * Constructor
     */
    genetic_algorithm() = default;

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

    /**
     *
     */
    void mutation();

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
     * @param crosses
     */
    void set_num_crosses(double crosses);

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

    void run_algorithm();
};

#endif
