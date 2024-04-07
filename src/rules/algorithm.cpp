#include <iostream>
#include <cassert>
#include <chrono>

#include "../configuration.hpp"
#include "algorithm.hpp"
#include "initial_solution.hpp"
#include "neighbourhood.hpp"


void
iterative_improvement_algorithm(Neighbourhood neighbourhood_rule, Pivoting pivoting_rule, Instance& instance)
{
    neighbourhood(neighbourhood_rule, pivoting_rule, instance);
}

void
variable_neighborhood_descent_algorithm(Neighbourhood neighbourhood_rule, Pivoting pivoting_rule, Instance& instance)
{
    neighbourhood(neighbourhood_rule, pivoting_rule, instance);
}

void
algorithm(Algorithm algorithm_rule, InitialSolution initial_solution_rule, Neighbourhood neighbourhood_rule, Pivoting pivoting_rule, Instance& instance)
{
    initial_solution(initial_solution_rule, instance);
    switch (algorithm_rule)
    {
    case II:
        iterative_improvement_algorithm(neighbourhood_rule, pivoting_rule, instance);
        break;
    case VND:
        variable_neighborhood_descent_algorithm(neighbourhood_rule, pivoting_rule, instance);
        break;
    default:
        assert(false);
        break;
    }
}