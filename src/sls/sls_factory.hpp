#ifndef SLS_FACTORY_HPP
#define SLS_FACTORY_HPP

#include "../lop/configuration.hpp"

void sls_algorithm(Algorithm algorithm_rule, InitialSolution initial_solution_rule, Neighbourhood neighbourhood_rule, Pivoting pivoting_rule, Instance& instance);

#endif