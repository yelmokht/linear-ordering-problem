#include <iostream>

#include "variable_neighbourhood_descent.hpp"


VariableNeighbourhoodDescent::VariableNeighbourhoodDescent(InitialSolution initial_solution_rule, Neighbourhood neighbourhood_rule, Pivoting pivoting_rule)
{
    this->initial_solution_rule = initial_solution_rule;
    get_neighbourhoods(neighbourhood_rule);
    this->pivoting_rule = pivoting_rule;
}

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

void
VariableNeighbourhoodDescent::run(Instance& instance)
{
    auto solution = initial_solution(initial_solution_rule, instance);
    auto last_solution = solution;
    int i = 0;
    while (i < 3) {
        improvement(pivoting_rule, neighbourhood_rules[i], instance, solution);

        if (solution.score() > last_solution.score()) {
            last_solution = solution;
            // std::cout << "New best solution: " << solution.score() << std::endl;
            // std::cout << "Back to neighbourhood 0" << std::endl;
            i = 0;
        } else {
            // std::cout << "No improvement, trying next neighbourhood" << std::endl;
            i++;
            solution.set_last_neighbour({0, 0});
            std::cout << "Neighbourhood " << i << std::endl;
        }
    }
    instance.set_solution(solution);
}