#include <cassert>
#include <algorithm>
#include <random>

#include "perturbation.hpp"
#include "pivoting.hpp"
#include "neighbourhood.hpp"
#include "cost.hpp"

Solution& exchange(Instance& instance, Solution& solution)
{
    return first_improvement(Neighbourhood::EXCHANGE, instance, solution);
}

Solution& random_exchange(Instance& instance, Solution& solution)
{
    auto neighbourhood = generate_neighbourhood(Neighbourhood::EXCHANGE, instance.size());
    std::shuffle(neighbourhood.begin(), neighbourhood.end(), std::mt19937(rand()));

    for (auto [i, j] : neighbourhood) {
        int new_score = solution.score() + delta(Neighbourhood::EXCHANGE, instance, solution, i, j);

        if (new_score > solution.score()) {
            solution = apply_permutation(Neighbourhood::EXCHANGE, solution, i, j);
            solution.set_score(new_score);
            return solution;
        }
    }

    return solution;
}

Solution& perturbation(Perturbation pertubartion_rule, Instance& instance, Solution& solution, int moves)
{
    switch (pertubartion_rule)
    {
        case Perturbation::EXCHANGE:
            return exchange(instance, solution);
        case Perturbation::RANDOM_EXCHANGE:
            return random_exchange(instance, solution);
        default:
            assert(false);
            break;
    }
}