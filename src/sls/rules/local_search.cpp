#include <cassert>

#include "local_search.hpp"
#include "pivoting.hpp"
#include "neighbourhood.hpp"
#include "cost.hpp"

/**
 * @brief Applies the insert local search operator to a solution
 * 
 * @param instance The instance for which to apply the operator.
 * @param solution The solution to apply the operator to.
 * @return Solution The mutated solution.
 */
Solution& insert(Instance& instance, Solution& solution)
{
    int best_score = solution.score();
    unsigned best_i = 0;
    unsigned best_j = 0;

    for (unsigned i = 0; i < instance.size(); i++) {
        for (unsigned j = 0; j < instance.size(); j++) {

            if (neighbourhood_is_valid(Neighbourhood::INSERT, i, j)) {
                int new_score = solution.score() + delta(Neighbourhood::INSERT, instance, solution, i, j);

                if (new_score > best_score) {
                    best_score = new_score;
                    best_i = i;
                    best_j = j;
                }
            }
        }
        
        if (best_score > solution.score()) {
            solution = apply_permutation(Neighbourhood::INSERT, solution, best_i, best_j);
            solution.set_score(best_score);
            return solution;
        }
    }
    return solution;
}

/**
 * @brief Applies the local search operator to a solution
 * 
 * @param local_search_rule The local search operator to apply.
 * @param instance The instance for which to apply the operator.
 * @param solution The solution to apply the operator to.
 * @return Solution The mutated solution.
 */
Solution& local_search(LocalSearch local_search_rule, Instance& instance, Solution& solution)
{
    switch (local_search_rule)
    {
        case LocalSearch::INSERT:
            return insert(instance, solution);
        default:
            assert(false);
            break;
    }
}