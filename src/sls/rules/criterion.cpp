#include "criterion.hpp"
#include <iostream>

bool
local_optimum_criterion_is_not_satisfied(Solution& last_solution, Solution& new_solution)
{
    return (last_solution != new_solution);
}

bool
termination_criterion_is_not_satisfied(double elapsed_time, double max_runtime)
{
    return elapsed_time < max_runtime;
}

bool
acceptance_criterion_is_not_satisfied(Solution& last_solution, Solution& new_solution)
{
    return (last_solution >= new_solution);
}