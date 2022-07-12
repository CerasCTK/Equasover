#include "genetic_algorithm.h"

genetic_algorithm *genetic_algorithm::init_ga() {
    return new genetic_algorithm;
}

genetic_algorithm *genetic_algorithm::init_population() {
    return this;
}

genetic_algorithm::~genetic_algorithm() {

}
