#include <chrono>
#include <iostream>

#include "memetic_algorithm.hpp"
#include "../../lop/population.hpp"
#include "initialisations/initialisation.hpp"
#include "operators.hpp"
#include "../rules/criterion.hpp"
#include "../utils/utils.hpp"

/**
 * Constructor for the MemeticAlgorithm class.
 * 
 * @param initial_solution_rule The rule to use for generating the initial solution.
 * @param local_search_rule The rule to use for the local search.
 * @param recombination_rule The rule to use for the recombination.
 * @param mutation_rule The rule to use for the mutation.
 * @param selection_rule The rule to use for the selection.
 */
MemeticAlgorithm::MemeticAlgorithm(InitialSolution initial_solution_rule, LocalSearch local_search_rule, Recombination recombination_rule, Mutation mutation_rule, Selection selection_rule)
{
    this->population_size = 25;
    this->mutation_rate = 0.4;
    this->initial_solution_rule = initial_solution_rule;
    this->local_search_rule = local_search_rule;
    this->recombination_rule = recombination_rule;
    this->mutation_rule = mutation_rule;
    this->selection_rule = selection_rule;
}

/**
 * Runs the memetic algorithm.
 * 
 * @param instance The instance for which to run the algorithm.
 */
void
MemeticAlgorithm::run(Instance& instance)
{
    auto start_time = std::chrono::high_resolution_clock::now();
    double elapsed_time = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::high_resolution_clock::now() - start_time).count();

    Population sp = initialisation(initial_solution_rule, instance, population_size);

    sp = subsidiary_local_search(local_search_rule, instance, sp);

    Population spr = Population(population_size);
    Population spm = Population(population_size);

    auto iteration = 1;
    auto max_runtime = instance.max_runtime();

    while (termination_criterion_is_not_satisfied(elapsed_time, max_runtime))
    {
        spr = recombination(recombination_rule, instance, sp);
        
        spr = subsidiary_local_search(local_search_rule, instance, spr);

        spm = mutation(mutation_rule, instance, spr, mutation_rate);

        spm = subsidiary_local_search(local_search_rule, instance, spm);

        sp = selection(selection_rule, instance, sp, spr, spm);

        elapsed_time = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::high_resolution_clock::now() - start_time).count();
        std::cerr << "Iteration: " << iteration << " - Best solution: " << sp.best_solution().score() << " - Elapsed time: " << elapsed_time << "s" << std::endl;
        iteration++;
    }
    
    instance.set_solution(sp.best_solution());
}