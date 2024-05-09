#include <cassert>
#include <iostream>

#include "subsidiary_local_search.hpp"
#include "../../rules/local_search.hpp"
#include "../../rules/neighbourhood.hpp"
#include "../../rules/pivoting.hpp"

/**
 * @brief Applies the insert local search operator to a population
 * 
 * @param instance The instance for which to apply the operator.
 * @param population The population to apply the operator to.
 * @return Population The mutated population.
 */
Population& insert(Instance& instance, Population& population) {
    int i = 0; // Add an index variable if you need it
    for (Solution& solution : population.solutions()) {
        // std::cout << "First improvement for solution " << i << std::endl;
        first_improvement(Neighbourhood::INSERT, instance, solution);
        i++; // Increment index variable if you're using it
    }
    return population;
}


/**
 * @brief Applies subsidiary local search operator to a population
 * 
 * @param instance The instance for which to apply the operator.
 * @param population The population to apply the operator to.
 * @return Population The mutated population.
 */
Population& subsidiary_local_search(LocalSearch local_search_rule, Instance& instance, Population& population) {
    switch (local_search_rule) {
        case LocalSearch::INSERT:
            return insert(instance, population);
        default:
            assert(false);
    }
}
    