#include <cassert>
#include <iostream>
#include <numeric>
#include <algorithm>
#include <random>

#include "initial_solution.hpp"

void
print_initial_solution(Instance& instance)
{
    std::cout << "Initial solution: ";
    for (auto i : instance.permutation()) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

void 
random_solution(Instance& instance) 
{
    auto random_permutation = std::vector<int>(instance.size());
    std::iota(random_permutation.begin(), random_permutation.end(), 0);
    std::shuffle(random_permutation.begin(), random_permutation.end(), std::default_random_engine(instance.seed()));
    instance.set_permutation(random_permutation);
    // instance.permute_rows();
}

void 
cw_solution(Instance& instance) 
{
    auto matrix = instance.matrix();
    auto cw_permutation = std::vector<int>(instance.size());
    std::iota(cw_permutation.begin(), cw_permutation.end(), 0);
    auto default_permutation = cw_permutation;
    
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
    
    instance.set_permutation(cw_permutation);
    instance.permute_rows();
    // instance.set_permutation(default_permutation);
}


void 
initial_solution(InitialSolution initial_solution_rule, Instance& instance)
{
    switch (initial_solution_rule)
    {
    case RANDOM:
        random_solution(instance);
        break;
    case CW:
        cw_solution(instance);
        break;
    default:
        assert(false);
        break;
    }
    if (VERBOSE) {
        print_initial_solution(instance);
    }
}