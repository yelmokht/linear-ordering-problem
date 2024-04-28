#ifndef CRITERION_HPP
#define CRITERION_HPP

#include <chrono>
#include <vector>
#include "../../lop/configuration.hpp"

bool local_optimum_criterion_is_not_satisfied(Solution& last_solution, Solution& new_solution);
bool termination_criterion_is_not_satisfied(double elapsed_time, double max_runtime);
bool acceptance_criterion_is_not_satisfied(Solution& last_solution, Solution& new_solution);

#endif