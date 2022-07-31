#pragma once

#ifndef GENETICALGORITHM_GENETIC_ALGORITHM_H
#define GENETICALGORITHM_GENETIC_ALGORITHM_H

#include <cstdint>

class genetic_algorithm {
private:
    /**
     *
     */
    genetic_algorithm() = default;

public:
    /**
     *
     * @return
     */
    static genetic_algorithm *init_ga();

    /**
     *
     * @return
     */
    genetic_algorithm *init_population();

    /**
     *
     */
    ~genetic_algorithm();
};

#endif
