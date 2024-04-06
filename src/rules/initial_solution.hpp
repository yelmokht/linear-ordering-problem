#ifndef INITIAL_SOLUTION_HPP
#define INITIAL_SOLUTION_HPP

#include "../configuration.hpp"

void print_initial_solution(Instance& instance);
void random_solution(Instance& instance);
void cw_solution(Instance& instance);
void initial_solution(InitialSolution initial_solution_rule, Instance& instance);

#endif