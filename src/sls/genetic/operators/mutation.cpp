#include <cassert>

#include "mutation.hpp"
#include "../../rules/neighbourhood.hpp"

Population exchange_mutation(Instance& instance, Population& population, double mutation_rate) {
    Population mutated_population(population.size());

    for (int i = 0; i < population.size(); i++) {
        float rng = static_cast<float>(rand() % 100) / 100.0f; // Use static_cast for type conversion
        if (rng <= mutation_rate) {
            Solution solution = population.solution(i);
            int gene_index_1 = rand() % instance.size();
            int gene_index_2 = rand() % instance.size();
            Solution mutated_solution = exchange(solution, gene_index_1, gene_index_2);
            mutated_population.set_solution(i, mutated_solution);
        } else {
            mutated_population.set_solution(i, population.solution(i));
        }
    }

    return mutated_population;
}




Population insert_mutation(Instance& instance, Population& population, double mutation_rate)
{
    //For future implementation
    return population;
}

Population invert_mutation(Instance& instance, Population& population, double mutation_rate)
{
    //For future implementation
    return population;
}

Population scramble_mutation(Instance& instance, Population& population, double mutation_rate)
{
    //For future implementation
    return population;
}

Population swap_mutation(Instance& instance, Population& population, double mutation_rate)
{
    //For future implementation
    return population;
}

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