#ifndef ALGORITHM_HPP
#define ALGORITHM_HPP

#include "../configuration.hpp"


void iterative_improvement_algorithm(Neighbourhood neighbourhood_rule, Pivoting pivoting_rule, Instance& instance);
void variable_neighborhood_descent_algorithm(Neighbourhood neighbourhood_rule, Pivoting pivoting_rule, Instance& instance);
void algorithm(Algorithm algorithm_rule, InitialSolution initial_solution_rule, Neighbourhood neighbourhood_rule, Pivoting pivoting_rule, Instance& instance);

#endif