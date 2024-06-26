#include <cassert>

#include "mutation.hpp"
#include "../../rules/neighbourhood.hpp"
#include "../../rules/cost.hpp"


/**
 * @brief Applies the exchange mutation operator to a population
 * 
 * @param instance The instance for which to apply the operator.
 * @param population The population to apply the operator to.
 * @param mutation_rate The mutation rate.
 * @return Population The mutated population.
*/
Population exchange_mutation(Instance& instance, Population& population, double mutation_rate) {
    Population mutated_population(population.size());

    for (int i = 0; i < population.size(); i++) {
        float rng = static_cast<float>(rand() % 100) / 100.0f;
        if (rng <= mutation_rate) {
            Solution solution = population.solution(i);
            int gene_index_1 = rand() % instance.size();
            int gene_index_2 = rand() % instance.size();
            while (!neighbourhood_is_valid(Neighbourhood::EXCHANGE, gene_index_1, gene_index_2)) {
                gene_index_1 = rand() % instance.size();
                gene_index_2 = rand() % instance.size();
            }
            Solution mutated_solution = exchange(solution, gene_index_1, gene_index_2);
            // mutated_solution.set_score(solution.score() + exchange_delta(instance, solution, gene_index_1, gene_index_2));
            mutated_solution.set_score(evaluate(instance, mutated_solution));
            mutated_population.set_solution(i, mutated_solution);
        } else {
            mutated_population.set_solution(i, population.solution(i));
        }
    }

    return mutated_population;
}

/**
 * @brief Applies the insert mutation operator to a population
 * 
 * @param instance The instance for which to apply the operator.
 * @param population The population to apply the operator to.
 * @param mutation_rate The mutation rate.
 * @return Population The mutated population.
*/
Population insert_mutation(Instance& instance, Population& population, double mutation_rate)
{
    //For future implementation
    return population;
}

/**
 * @brief Applies the inversion mutation operator to a population
 * 
 * @param instance The instance for which to apply the operator.
 * @param population The population to apply the operator to.
 * @param mutation_rate The mutation rate.
 * @return Population The mutated population.
*/
Population invert_mutation(Instance& instance, Population& population, double mutation_rate)
{
    //For future implementation
    return population;
}

/**
 * @brief Applies the scramble mutation operator to a population
 * 
 * @param instance The instance for which to apply the operator.
 * @param population The population to apply the operator to.
 * @param mutation_rate The mutation rate.
 * @return Population The mutated population.
*/
Population scramble_mutation(Instance& instance, Population& population, double mutation_rate)
{
    //For future implementation
    return population;
}

/**
 * @brief Applies the swap mutation operator to a population
 * 
 * @param instance The instance for which to apply the operator.
 * @param population The population to apply the operator to.
 * @param mutation_rate The mutation rate.
 * @return Population The mutated population.
*/
Population swap_mutation(Instance& instance, Population& population, double mutation_rate)
{
    //For future implementation
    return population;
}

/**
 * @brief Applies a mutation operator to a population
 * 
 * @param mutation_rule The mutation operator to apply.
 * @param instance The instance for which to apply the operator.
 * @param population The population to apply the operator to.
 * @param mutation_rate The mutation rate.
 * @return Population The mutated population.
*/
Population mutation(Mutation mutation_rule, Instance& instance, Population& population, double mutation_rate)
{
    switch (mutation_rule)
    {
        case Mutation::EXCHANGE:
            return exchange_mutation(instance, population, mutation_rate);
        case Mutation::INSERT:
            return insert_mutation(instance, population, mutation_rate);
        case Mutation::INVERSION:
            return invert_mutation(instance, population, mutation_rate);
        case Mutation::SCRAMBLE:
            return scramble_mutation(instance, population, mutation_rate);
        case Mutation::SWAP:
            return swap_mutation(instance, population, mutation_rate);
        default:
            assert(false);
    }
}