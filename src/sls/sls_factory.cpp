#include <cassert>

#include "sls_factory.hpp"
#include "simple/iterative_improvement.hpp"
#include "simple/variable_neighbourhood_descent.hpp"
#include "hybrid/iterated_local_search.hpp"
#include "genetic/memetic_algorithm.hpp"

void
sls_algorithm(Algorithm algorithm_rule, InitialSolution initial_solution_rule, Neighbourhood neighbourhood_rule, Pivoting pivoting_rule, Instance& instance)
{
    switch (algorithm_rule)
    {
    case II:
        IterativeImprovement(initial_solution_rule, neighbourhood_rule, pivoting_rule).run(instance);
        break;
    case VND:
        VariableNeighbourhoodDescent(initial_solution_rule, neighbourhood_rule, pivoting_rule).run(instance);
        break;
    case ILS:
        IteratedLocalSearch().run(pivoting_rule, instance);
        break;
    case MA:
        MemeticAlgorithm(0.2, 1000).run(instance);
        break;
    default:
        assert(false);
        break;
    }
}