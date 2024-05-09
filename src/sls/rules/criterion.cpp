#include "criterion.hpp"
#include <iostream>

/**
 * Check if the local optimum criterion is not satisfied.
 * 
 * @param last_solution The last solution.
 * @param new_solution The new solution.
 * 
 * @return True if the local optimum criterion is not satisfied, false otherwise.
*/
bool
local_optimum_criterion_is_not_satisfied(Solution& last_solution, Solution& new_solution)
{
    return (last_solution != new_solution);
}

/**
 * Check if the termination criterion is not satisfied.
 * 
 * @param elapsed_time The elapsed time.
 * @param max_runtime The maximum runtime.
 * 
 * @return True if the termination criterion is not satisfied, false otherwise.
*/
bool
termination_criterion_is_not_satisfied(double elapsed_time, double max_runtime)
{
    return elapsed_time < max_runtime;
}

/**
 * Check if the acceptance criterion is not satisfied.
 * 
 * @param last_solution The last solution.
 * @param new_solution The new solution.
 * 
 * @return True if the acceptance criterion is not satisfied, false otherwise.
*/
bool
acceptance_criterion_is_not_satisfied(Solution& last_solution, Solution& new_solution)
{
    return (last_solution >= new_solution);
}