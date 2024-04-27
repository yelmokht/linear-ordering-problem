#ifndef INITIAL_SOLUTION_HPP
#define INITIAL_SOLUTION_HPP

#include "../../lop/configuration.hpp"

Solution random_solution(Instance& instance);
Solution cw_solution(Instance& instance);
Solution initial_solution(InitialSolution initial_solution_rule, Instance& instance);

#endif