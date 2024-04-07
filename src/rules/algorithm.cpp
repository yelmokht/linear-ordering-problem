#include <iostream>
#include <cassert>
#include <chrono>

#include "../configuration.hpp"
#include "algorithm.hpp"
#include "initial_solution.hpp"
#include "neighbourhood.hpp"


/**
 * Executes the iterative improvement algorithm to solve the linear ordering problem.
 *
 * @param neighbourhood_rule The neighbourhood rule.
 * @param pivoting_rule The pivoting rule.
 * @param instance The instance for which we solve the linear ordering problem.
 */
void
iterative_improvement_algorithm(Neighbourhood neighbourhood_rule, Pivoting pivoting_rule, Instance& instance)
{
    neighbourhood(neighbourhood_rule, pivoting_rule, instance);
}

/**
 * Executes the variable neighbourhood descent algorithm to solve the linear ordering problem.
 *
 * @param neighbourhood_rule The neighbourhood rule.
 * @param pivoting_rule The pivoting rule.
 * @param instance The instance for which we solve the linear ordering problem.
 */
void
variable_neighborhood_descent_algorithm(Neighbourhood neighbourhood_rule, Pivoting pivoting_rule, Instance& instance)
{
    neighbourhood(neighbourhood_rule, pivoting_rule, instance);
}

/**
 * Executes the specified algorithm to solve the linear ordering problem.
 *
 * @param algorithm_rule The algorithm to be executed.
 * @param initial_solution_rule The initial solution rule.
 * @param neighbourhood_rule The neighbourhood rule.
 * @param pivoting_rule The pivoting rule.
 * @param instance The instance for which we solve the linear ordering problem.
 */
void
algorithm(Algorithm algorithm_rule, InitialSolution initial_solution_rule, Neighbourhood neighbourhood_rule, Pivoting pivoting_rule, Instance& instance)
{
    initial_solution(initial_solution_rule, instance); // Generate the initial solution
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