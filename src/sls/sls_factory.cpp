#include <cassert>

#include "sls_factory.hpp"
#include "simple/iterative_improvement.hpp"
#include "simple/variable_neighbourhood_descent.hpp"
#include "hybrid/iterated_local_search.hpp"
#include "genetic/memetic_algorithm.hpp"

void
sls_algorithm(Configuration& configuration, Instance& instance)
{
    auto algorithm_rule = configuration.algorithm();
    auto initial_solution_rule = configuration.initial_solution();
    auto neighbourhood_rule = configuration.neighbourhood();
    auto pivoting_rule = configuration.pivoting();
    auto local_search_rule = configuration.local_search();
    auto perturbation_rule = configuration.perturbation();
    auto recombination_rule = configuration.recombination();
    auto mutation_rule = configuration.mutation();
    auto selection_rule = configuration.selection();

    switch (algorithm_rule)
    {
    case Algorithm::II:
        IterativeImprovement(initial_solution_rule, neighbourhood_rule, pivoting_rule).run(instance);
        break;
    case Algorithm::VND:
        VariableNeighbourhoodDescent(initial_solution_rule, neighbourhood_rule, pivoting_rule).run(instance);
        break;
    case Algorithm::ILS:
        instance.save_max_runtime();
        // IteratedLocalSearch(initial_solution_rule, local_search_rule, perturbation_rule).run(instance);
        break;
    case Algorithm::MA:
        instance.save_max_runtime();
        // MemeticAlgorithm(initial_solution_rule, local_search_rule, recombination_rule, mutation_rule, selection_rule).run(instance);
        break;
    default:
        assert(false);
        break;
    }
}