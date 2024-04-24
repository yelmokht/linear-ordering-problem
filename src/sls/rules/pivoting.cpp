#include <iostream>
#include <cassert>

#include "pivoting.hpp"
#include "neighbourhood.hpp"
#include "cost.hpp"
#include "../../lop/solution.hpp"
#include "../../lop/configuration.hpp"


Solution
first_improvement(Neighbourhood neighbourhood_rule, Instance& instance, Solution solution)
{
    for (int i = 0; i < instance.size(); i++) {
        for (int j = i + 1; j < instance.size(); j++) {

            Solution new_solution = neighbourhood(neighbourhood_rule, instance, solution, i, j);

            if (new_solution.score() > solution.score()) {
                return new_solution;
            }
        }
    }

    return solution;
}

Solution
best_improvement(Neighbourhood neighbourhood_rule, Instance& instance, Solution solution) 
{
    Solution best_solution = solution;

    for (int i = 0; i < instance.size(); i++) {
        for (int j = 0; j < instance.size(); j++) {

            Solution new_solution = neighbourhood(neighbourhood_rule, instance, best_solution, i, j);

            if (new_solution.score() > best_solution.score()) {
                best_solution = new_solution;
            }
        }
    }

    return best_solution;
}


Solution improvement(Pivoting pivoting_rule, Neighbourhood neighbourhood_rule, Instance& instance, Solution solution)
{
    switch (pivoting_rule)
    {
    case FIRST:
        return first_improvement(neighbourhood_rule, instance, solution);
    case BEST:
        return best_improvement(neighbourhood_rule, instance, solution);
    default:
        assert(false);
    }
}
