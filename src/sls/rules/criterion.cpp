#include "criterion.hpp"

bool
local_optimum_criterion_is_not_satisfied(Solution& last_solution, Solution& new_solution)
{
    return (last_solution != new_solution);
}

bool
terminal_criterion_is_not_satisfied(double elapsed_time, double max_runtime)
{
    return elapsed_time < max_runtime;
}

bool
acceptance_criterion_is_satisfied(std::vector<Solution>& previous_solutions, Solution& old_solution, Solution& new_solution)
{
    // if (new_solution is in previous_solutions) {
    //     return false;
    // } else {
    //     new_solution.compute_score();
    //     previous_solutions.push_back(new_solution);
    //     return new_solution.score() > old_solution.score();
    // }

    return false;
}