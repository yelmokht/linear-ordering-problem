#include <cassert>
#include <algorithm>
#include <random>

#include "perturbation.hpp"
#include "pivoting.hpp"
#include "neighbourhood.hpp"
#include "cost.hpp"

/**
 * @brief Applies an exchange operator to a solution.
 * 
 * @param instance The instance for which to apply the operator.
 * @param solution The solution to apply the operator to.
 * 
 * @return Solution The mutated solution.
 */
Solution& exchange(Instance& instance, Solution& solution)
{
    return first_improvement(Neighbourhood::EXCHANGE, instance, solution);
}

/**
 * @brief Applies a random exchange operator to a solution.
 * 
 * @param instance The instance for which to apply the operator.
 * @param solution The solution to apply the operator to.
 * 
 * @return Solution The mutated solution.
 */
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

/**
 * @brief Applies a perturbation operator to a solution.
 * 
 * @param pertubartion_rule The perturbation operator to apply.
 * @param instance The instance for which to apply the operator.
 * @param solution The solution to apply the operator to.
 * @param moves The number of moves to apply.
 * 
 * @return Solution The mutated solution.
 */
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