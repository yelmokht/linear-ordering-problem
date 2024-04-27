#include <iostream>
#include <cassert>

#include "pivoting.hpp"
#include "neighbourhood.hpp"
#include "cost.hpp"
#include "../../lop/solution.hpp"
#include "../../lop/configuration.hpp"


Solution& first_improvement(Neighbourhood neighbourhood_rule, Instance& instance, Solution& solution)
{
    std::pair<unsigned int, unsigned int> kl = solution.last_neighbour();
    unsigned k = kl.first;
    unsigned l = kl.second;

    for (unsigned i = k; i < instance.size(); i++) {
        for (unsigned j = l; j < instance.size(); j++) {

            if (neighbourhood_is_valid(neighbourhood_rule, i, j)) {
                int new_score = solution.score() + delta(neighbourhood_rule, instance, solution, i, j);

                if (new_score > solution.score()) {
                    std::cout << "i: " << i << " j: " << j << " new_score: " << new_score << std::endl;
                    solution = apply_permutation(neighbourhood_rule, solution, i, j);
                    solution.set_score(new_score);
                    solution.set_last_neighbour({i, j});
                    return solution;
                }
            }
        }
    }

    // if (l != 0) {
    //     solution.set_last_neighbour({0, 0});
    //     first_improvement(neighbourhood_rule, instance, solution);
    // }

    return solution;
}

Solution& best_improvement(Neighbourhood neighbourhood_rule, Instance& instance, Solution& solution) 
{
    for (unsigned i = 0; i < instance.size(); i++) {
        for (unsigned j = 0; j < instance.size(); j++) {

            if (neighbourhood_is_valid(neighbourhood_rule, i, j)) {
                int new_score = solution.score() + delta(neighbourhood_rule, instance, solution, i, j);

                if (new_score > solution.score()) {
                    apply_permutation(neighbourhood_rule, solution, i, j);
                    solution.set_score(new_score);
                }
            }
        }
    }

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
