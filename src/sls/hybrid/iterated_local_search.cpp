#include "iterated_local_search.hpp"
#include "../rules/initial_solution.hpp"
#include "../rules/local_search.hpp"
#include "../rules/criterion.hpp"

IteratedLocalSearch::IteratedLocalSearch(InitialSolution initial_solution_rule, LocalSearch local_search_rule, Perturbation perturbation_rule) 
{
    this->initial_solution_rule = initial_solution_rule;
    this->local_search_rule = local_search_rule;
    this->perturbation_rule = perturbation_rule;
}

void
IteratedLocalSearch::run(Instance& instance)
{
    Solution solution = initial_solution(initial_solution_rule, instance);
    // solution = local_search(instance, solution, local_search_rule);
    auto max_runtime = instance.max_runtime();
    auto start_time = std::chrono::high_resolution_clock::now();
    double elapsed_time = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::high_resolution_clock::now() - start_time).count();
    
    while (terminal_criterion_is_not_satisfied(elapsed_time, max_runtime))
    {
    
        elapsed_time = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::high_resolution_clock::now() - start_time).count();
    }
}