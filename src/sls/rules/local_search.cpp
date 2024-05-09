#include <cassert>

#include "local_search.hpp"
#include "pivoting.hpp"
#include "neighbourhood.hpp"
#include "cost.hpp"

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