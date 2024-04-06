#ifndef ALGORITHM_HPP
#define ALGORITHM_HPP

#include "../configuration.hpp"

void iterative_improvement_algorithm(Pivoting pivoting_rule, Neighbourhood neighborhood_rule, Instance& instance);
void variable_neighborhood_descent_algorithm(Pivoting pivoting_rule, Neighbourhood neighborhood_rule, Instance& instance);
void algorithm(Algorithm algorithm_rule, InitialSolution initial_solution_rule, Pivoting pivoting_rule, Neighbourhood neighbourhood_rule, Instance& instance);

#endif // ALGORITHM_HPP