#include <iostream>
#include <cassert>
#include <chrono>

#include "../configuration.hpp"
#include "algorithm.hpp"
#include "initial_solution.hpp"
#include "pivoting.hpp"


void
iterative_improvement_algorithm(Pivoting pivoting_rule, Neighbourhood neighbourhood_rule, Instance& instance)
{
    improvement(pivoting_rule, neighbourhood_rule, instance);
}

void
variable_neighborhood_descent_algorithm(Pivoting pivoting_rule, Neighbourhood neighborhood_rule, Instance& instance)
{
    improvement(pivoting_rule, neighborhood_rule, instance);
}

void
algorithm(Algorithm algorithm_rule, InitialSolution initial_solution_rule, Pivoting pivoting_rule, Neighbourhood neighbourhood_rule, Instance& instance)
{
    initial_solution(initial_solution_rule, instance);
    switch (algorithm_rule)
    {
    case II:
        iterative_improvement_algorithm(pivoting_rule, neighbourhood_rule, instance);
        break;
    case VND:
        variable_neighborhood_descent_algorithm(pivoting_rule, neighbourhood_rule, instance);
        break;
    default:
        assert(false);
        break;
    }
}