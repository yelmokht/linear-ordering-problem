#include <cassert>
#include <iostream>

#include "subsidiary_local_search.hpp"
#include "../../rules/local_search.hpp"
#include "../../rules/neighbourhood.hpp"
#include "../../rules/pivoting.hpp"

Population& insert(Instance& instance, Population& population) {
    int i = 0; // Add an index variable if you need it
    for (Solution& solution : population.solutions()) {
        // std::cout << "First improvement for solution " << i << std::endl;
        first_improvement(Neighbourhood::INSERT, instance, solution);
        i++; // Increment index variable if you're using it
    }
    return population;
}


Population& subsidiary_local_search(LocalSearch local_search_rule, Instance& instance, Population& population) {
    switch (local_search_rule) {
        case LocalSearch::INSERT:
            return insert(instance, population);
        default:
            assert(false);
    }
}
    