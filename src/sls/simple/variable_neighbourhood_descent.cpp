#include <iostream>

#include "variable_neighbourhood_descent.hpp"

/**
 * Constructor for the VariableNeighbourhoodDescent class.
 * 
 * @param initial_solution_rule The rule for generating the initial solution.
 * @param neighbourhood_rule The rule for generating the neighbourhood.
 * @param pivoting_rule The rule for selecting the next solution.
 */
VariableNeighbourhoodDescent::VariableNeighbourhoodDescent(InitialSolution initial_solution_rule, Neighbourhood neighbourhood_rule, Pivoting pivoting_rule)
{
    this->initial_solution_rule = initial_solution_rule;
    get_neighbourhoods(neighbourhood_rule);
    this->pivoting_rule = pivoting_rule;
}

/**
 * Get the neighbourhoods for the VND algorithm.
 * 
 * @param neighbourhood_rule The rule for generating the neighbourhood.
 */
void
VariableNeighbourhoodDescent::get_neighbourhoods(Neighbourhood neighbourhood_rule) 
{
    switch (neighbourhood_rule)
    {
        case Neighbourhood::TRANSPOSE_EXCHANGE_INSERT:
            neighbourhood_rules[0] = Neighbourhood::TRANSPOSE;
            neighbourhood_rules[1] = Neighbourhood::EXCHANGE;
            neighbourhood_rules[2] = Neighbourhood::INSERT;
            break;
        case Neighbourhood::TRANSPOSE_INSERT_EXCHANGE:
            neighbourhood_rules[0] = Neighbourhood::TRANSPOSE;
            neighbourhood_rules[1] = Neighbourhood::INSERT;
            neighbourhood_rules[2] = Neighbourhood::EXCHANGE;
            break;
    }
}

/**
 * Runs the variable neighbourhood descent algorithm.
 * 
 * @param instance The instance for which to run the algorithm.
 */
void
VariableNeighbourhoodDescent::run(Instance& instance)
{
    auto solution = initial_solution(initial_solution_rule, instance);
    auto last_solution = solution;
    auto iteration = 1;
    int i = 0;
    while (i < 3) {
        improvement(pivoting_rule, neighbourhood_rules[i], instance, solution);
        // std::cout << "Iteration: " << iteration << " Score: " << solution.score() << std::endl;
        if (solution.score() > last_solution.score()) {
            last_solution = solution;
            i = 0;
        } else {
            i++;
        }
        iteration++;
    }
    instance.set_solution(solution);
}