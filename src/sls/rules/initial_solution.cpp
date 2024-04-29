#include <cassert>
#include <iostream>
#include <numeric>
#include <algorithm>
#include <random>

#include "initial_solution.hpp"

Solution
random_seed_solution(Instance& instance) 
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

Solution random_solution(Instance& instance) {
    Solution random_solution = instance.solution();
    auto random_permutation = random_solution.permutation();
    std::iota(random_permutation.begin(), random_permutation.end(), 0);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(random_permutation.begin(), random_permutation.end(), gen);
    random_solution.set_permutation(random_permutation);
    random_solution.set_score(instance.evaluate(random_solution));
    return random_solution;
}

Solution
bi_solution(Instance& instance) 
{
    auto matrix = instance.matrix();
    auto k = instance.size();
    Solution bi_solution = instance.solution();
    auto bi_permutation = bi_solution.permutation();
    std::iota(bi_permutation.begin(), bi_permutation.end(), 0);
    
    for (int l = 0; l < k; l++) {
        std::vector<int> q(k);

        for (int t = 0; t <= k; t++) {
            int sum_1 = 0;
            int sum_2 = 0;

            for (int j = 0; j < t; j++) {
                sum_1 += matrix[j][bi_permutation[l]];
            }

            for (int j = t; j < k; j++) {
                sum_2 += matrix[bi_permutation[l]][j];
            }

            q[t] = sum_1 + sum_2;
        }

        unsigned best_position = distance(q.begin(), max_element(q.begin(), q.end()));

        if (best_position != l && best_position != l + 1) {
            int temp = bi_permutation[l];
            bi_permutation.erase(bi_permutation.begin() + l);
            bi_permutation.insert(bi_permutation.begin() + best_position, temp);
        }
    }

    bi_solution.set_permutation(bi_permutation);
    bi_solution.set_score(instance.evaluate(bi_solution));
    return bi_solution;
}

Solution
initial_solution(InitialSolution initial_solution_rule, Instance& instance)
{
    switch (initial_solution_rule)
    {
    case InitialSolution::RANDOM_SEED:
        return random_seed_solution(instance);
    case InitialSolution::CW:
        return cw_solution(instance);
    case InitialSolution::BI:
        return bi_solution(instance);
    case InitialSolution::RANDOM:
        return random_solution(instance);
    default:
        assert(false);
    }
}