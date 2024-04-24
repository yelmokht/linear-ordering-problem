#include "variable_neighbourhood_descent.hpp"

VariableNeighbourhoodDescent::VariableNeighbourhoodDescent(InitialSolution initial_solution_rule, Neighbourhood neighbourhood_rule, Pivoting pivoting_rule)
{
    this->initial_solution_rule = initial_solution_rule;
    this->neighbourhood_rule = neighbourhood_rule;
    this->pivoting_rule = pivoting_rule;
}

void
VariableNeighbourhoodDescent::run(Instance& instance)
{
    auto solution = initial_solution(initial_solution_rule, instance); 
    improvement(pivoting_rule, neighbourhood_rule, instance, solution);
    instance.set_solution(solution);
}