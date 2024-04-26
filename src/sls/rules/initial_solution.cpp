#include <cassert>
#include <iostream>
#include <numeric>
#include <algorithm>
#include <random>

#include "initial_solution.hpp"

Solution
random_solution(Instance& instance) 
{
    Solution random_solution = instance.solution();
    auto random_permutation = random_solution.permutation();
    std::iota(random_permutation.begin(), random_permutation.end(), 0);
    std::shuffle(random_permutation.begin(), random_permutation.end(), std::mt19937(instance.seed()));
    random_solution.set_permutation(random_permutation);
    random_solution.set_score(instance.evaluate(random_solution));
    return random_solution;
}

Solution
cw_solution(Instance& instance) 
{
    auto matrix = instance.matrix();
    Solution cw_solution = instance.solution();
    auto cw_permutation = cw_solution.permutation();
    std::iota(cw_permutation.begin(), cw_permutation.end(), 0);

    for (unsigned step = 0 ; step < instance.size(); step++) {
        unsigned best_row = step;
        long int best_row_score = -1;

        for (unsigned row = step ; row < instance.size() ; row++) {
            long int current_row_score = 0;

            for (unsigned col = 1 + step ; col < instance.size(); col++) {
                    current_row_score += matrix[cw_permutation[row]][col];
            }

            if (best_row_score < current_row_score) {
                best_row = row;
                best_row_score = current_row_score;
            }
        }

        std::swap(cw_permutation[step], cw_permutation[best_row]);
    }
    
    cw_solution.set_permutation(cw_permutation);
    cw_solution.set_score(instance.evaluate(cw_solution));

    return cw_solution;
}

Solution
initial_solution(InitialSolution initial_solution_rule, Instance& instance)
{
    switch (initial_solution_rule)
    {
    case InitialSolution::RANDOM:
        return random_solution(instance);
    case InitialSolution::CW:
        return cw_solution(instance);
    default:
        assert(false);
    }
}