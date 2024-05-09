#include <cassert>

#include "initialisation.hpp"
#include "../../../lop/population.hpp"
#include "../../rules/initial_solution.hpp"


/**
 * @brief Generates a random initial population for the given instance.
 * 
 * @param instance The instance for which to generate the initial population.
 * @param population_size The size of the population.
 */
Population random_initialisation(Instance& instance, int population_size) {
    Population population(population_size);

    for (int i = 0; i < population_size; i++) {
        Solution solution(instance.size());
        solution = random_r_solution(instance);
        population.set_solution(i, solution);
    }

    return population;
}

/**
 * @brief Generates an initial population using the Chenery-Watanabe heuristic for the given instance.
 * 
 * @param instance The instance for which to generate the initial population.
 * @param population_size The size of the population.
 */
Population cw_initialisation(Instance& instance, int population_size) {
    Population population(population_size);

    for (int i = 0; i < population_size; i++) {
        Solution solution(instance.size());
        solution = cw_solution(instance);
        population.set_solution(i, solution);
    }

    return population;
}

/**
 * @brief Generates an initial population using the Best Insertion heuristic for the given instance.
 * 
 * @param instance The instance for which to generate the initial population.
 * @param population_size The size of the population.
 */
Population bi_initialisation(Instance& instance, int population_size) {
    Population population(population_size);

    for (int i = 0; i < population_size; i++) {
        Solution solution(instance.size());
        solution = bi_solution(instance);
        population.set_solution(i, solution);
    }

    return population;
}

/**
 * @brief Generates an initial population for the given instance.
 * 
 * @param initial_solution_rule The rule to use for generating the initial population.
 * @param instance The instance for which to generate the initial population.
 * @param population_size The size of the population.
 */
Population initialisation(InitialSolution initial_solution_rule, Instance& instance, int population_size) {
    switch (initial_solution_rule) {
        case InitialSolution::RANDOM:
            return random_initialisation(instance, population_size);
        case InitialSolution::CW:
            return cw_initialisation(instance, population_size);
        case InitialSolution::BI:
            return bi_initialisation(instance, population_size);
        default:
            assert(false);
    }
}
