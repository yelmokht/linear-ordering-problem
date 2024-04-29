#include <cassert>

#include "initialisation.hpp"
#include "../../../lop/population.hpp"
#include "../../rules/initial_solution.hpp"

Population random_initialisation(Instance& instance, int population_size) {
    Population population(population_size);

    for (int i = 0; i < population_size; i++) {
        Solution solution(instance.size());
        solution = random_solution(instance);
        population.set_solution(i, solution);
    }

    return population;
}


Population bi_initialisation(Instance& instance, int population_size) {
    Population population(population_size);

    for (int i = 0; i < population_size; i++) {
        Solution solution(instance.size());
        solution = bi_solution(instance);
        population.set_solution(i, solution);
    }

    return population;
}

Population initialisation(InitialSolution initial_solution_rule, Instance& instance, int population_size) {
    switch (initial_solution_rule) {
        case InitialSolution::RANDOM:
            return random_initialisation(instance, population_size);
        case InitialSolution::BI:
            return bi_initialisation(instance, population_size);
        default:
            assert(false);
    }
}
