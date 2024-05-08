#include <iostream>
#include <cassert>

#include "pivoting.hpp"
#include "neighbourhood.hpp"
#include "cost.hpp"
#include "../../lop/solution.hpp"
#include "../../lop/configuration.hpp"

Solution& first_improvement(Neighbourhood neighbourhood_rule, Instance& instance, Solution& solution)
{
    for (unsigned i = 0; i < instance.size(); i++) {
        for (unsigned j = 0; j < instance.size(); j++) {

            if (neighbourhood_is_valid(neighbourhood_rule, i, j)) {
                int new_score = solution.score() + delta(neighbourhood_rule, instance, solution, i, j);

                if (new_score > solution.score()) {
                    solution = apply_permutation(neighbourhood_rule, solution, i, j);
                    solution.set_score(new_score);
                }
            }
        }
    }

    return solution;
}

Solution& first_improvement_2(Neighbourhood neighbourhood_rule, Instance& instance, Solution& solution)
{
    for (unsigned i = 0; i < instance.size(); i++) {
        for (unsigned j = 0; j < instance.size(); j++) {

            if (neighbourhood_is_valid(neighbourhood_rule, i, j)) {
                int new_score = solution.score() + delta(neighbourhood_rule, instance, solution, i, j);

                if (new_score > solution.score()) {
                    solution = apply_permutation(neighbourhood_rule, solution, i, j);
                    return solution;
                }
            }
        }
    }

    return solution;
}

Solution& best_improvement(Neighbourhood neighbourhood_rule, Instance& instance, Solution& solution) 
{
    int best_score = solution.score();
    unsigned best_i = 0;
    unsigned best_j = 0;

    for (unsigned i = 0; i < instance.size(); i++) {
        for (unsigned j = 0; j < instance.size(); j++) {

            if (neighbourhood_is_valid(neighbourhood_rule, i, j)) {
                int new_score = solution.score() + delta(neighbourhood_rule, instance, solution, i, j);

                if (new_score > best_score) {
                    best_score = new_score;
                    best_i = i;
                    best_j = j;
                }
            }
        }
    }

    solution = apply_permutation(neighbourhood_rule, solution, best_i, best_j);
    solution.set_score(best_score);
    return solution;
}


Solution& improvement(Pivoting pivoting_rule, Neighbourhood neighbourhood_rule, Instance& instance, Solution& solution)
{
    switch (pivoting_rule)
    {
    case Pivoting::FIRST:
        return first_improvement(neighbourhood_rule, instance, solution);
    case Pivoting::BEST:
        return best_improvement(neighbourhood_rule, instance, solution);
    default:
        assert(false);
    }
}
