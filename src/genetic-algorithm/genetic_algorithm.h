#pragma once

#ifndef GENETICALGORITHM_GENETIC_ALGORITHM_H
#define GENETICALGORITHM_GENETIC_ALGORITHM_H

class genetic_algorithm {
private:
    genetic_algorithm() = default;

public:
    static genetic_algorithm *init_ga();

    genetic_algorithm *init_population();

    ~genetic_algorithm();
};

#endif
