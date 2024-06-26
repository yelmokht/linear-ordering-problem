#include <iostream>

#include "iterated_local_search.hpp"
#include "../rules/initial_solution.hpp"
#include "../rules/local_search.hpp"
#include "../rules/perturbation.hpp"
#include "../rules/criterion.hpp"

/**
 * Constructor for the IteratedLocalSearch class.
 * 
 * @param initial_solution_rule The rule to use for generating the initial solution.
 * @param local_search_rule The rule to use for the local search.
 * @param perturbation_rule The rule to use for the perturbation.
 * @param acceptance_criterion The rule to use for the acceptance criterion.
 */
IteratedLocalSearch::IteratedLocalSearch(InitialSolution initial_solution_rule, LocalSearch local_search_rule, Perturbation perturbation_rule) 
{
    this->initial_solution_rule = initial_solution_rule;
    this->local_search_rule = local_search_rule;
    this->perturbation_rule = perturbation_rule;
}

/**
 * Runs the iterated local search algorithm.
 * 
 * @param instance The instance for which to run the algorithm.
 */
void
IteratedLocalSearch::run(Instance& instance)
{
    Solution solution = initial_solution(initial_solution_rule, instance);
    solution = local_search(local_search_rule, instance, solution);
    auto iteration = 1;
    auto max_runtime = instance.max_runtime();
    auto start_time = std::chrono::high_resolution_clock::now();
    double elapsed_time = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::high_resolution_clock::now() - start_time).count();
    
    while (termination_criterion_is_not_satisfied(elapsed_time, max_runtime))
    {
        Solution last_solution = solution;
        solution = perturbation(perturbation_rule, instance, solution);
        solution = local_search(local_search_rule, instance, solution);
        if (acceptance_criterion_is_not_satisfied(last_solution, solution)) {
            solution = last_solution;
        }

        elapsed_time = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::high_resolution_clock::now() - start_time).count();
        std::cerr << "Iteration: " << iteration << " Score: " << solution.score() << " Elapsed time: " << elapsed_time << std::endl;
        iteration++;
    }

    instance.set_solution(solution);
}