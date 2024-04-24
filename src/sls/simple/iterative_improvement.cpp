#include <iostream>

#include "iterative_improvement.hpp"
#include "../rules/criterion.hpp"
#include "../rules/initial_solution.hpp"
#include "../rules/pivoting.hpp"

IterativeImprovement::IterativeImprovement(InitialSolution initial_solution_rule, Neighbourhood neighbourhood_rule, Pivoting pivoting_rule)
{
    this->initial_solution_rule = initial_solution_rule;
    this->neighbourhood_rule = neighbourhood_rule;
    this->pivoting_rule = pivoting_rule;
}

void
IterativeImprovement::run(Instance& instance)
{
    Solution solution = initial_solution(initial_solution_rule, instance);
    Solution last_solution = Solution(instance.size());
    int iteration = 0;

    while (local_optimum_criterion_is_not_satisfied(last_solution, solution))
    {
        last_solution = solution;
        solution = improvement(pivoting_rule, neighbourhood_rule, instance, solution);
        std::cout << "Iteration: " << iteration << " Score: " << solution.score() << std::endl;
        iteration++;
    }

    instance.set_solution(solution);
}