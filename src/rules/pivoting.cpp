#include <iostream>
#include <cassert>

#include "pivoting.hpp"
#include "neighbourhood.hpp"

int
compute_cost(Instance& instance, std::vector<int> permutation)
{
    auto matrix = instance.matrix();
    int size = instance.size();
    int cost = 0;
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            cost += matrix[permutation[i]][permutation[j]];
        }
    }
    return cost;
}

void
first_improvement(Neighbourhood neighbourhood_rule, Instance& instance)
{
    auto permutation = instance.permutation();
    auto solution = compute_cost(instance, permutation);
    instance.set_solution(solution);
    bool improved = false;
    while (!improved) {
        auto new_permutation = permutation;
        for (int i = 0; i < permutation.size(); ++i) {
            for (int j = i + 1; j < permutation.size(); ++j) {
                new_permutation = neighbourhood(neighbourhood_rule, instance, i, j);
                auto new_solution = compute_cost(instance, new_permutation);
                if (instance.solution() < new_solution) {
                    improved = true;
                    instance.set_permutation(new_permutation);
                    instance.set_solution(new_solution);
                    break;
                }
            }
        }
    }
}

void
best_improvement(Neighbourhood neighbourhood_rule, Instance& instance) 
{
    auto permutation = instance.permutation();
    auto solution = compute_cost(instance, permutation);
    instance.set_solution(solution);
    bool improved = false;
    while (!improved) {
        auto new_permutation = permutation;
        int best_solution = 0;
        for (int i = 0; i < permutation.size(); i++) {
            for (int j = i + 1; j < permutation.size(); j++) {
                new_permutation = neighbourhood(neighbourhood_rule, instance, i, j);
                auto new_solution = compute_cost(instance, new_permutation);
                if (instance.solution() < new_solution) {
                    improved = true;
                    instance.set_permutation(new_permutation);
                    instance.set_solution(new_solution);
                }
                if (best_solution < new_solution) {
                    best_solution = new_solution;
                    instance.set_permutation(new_permutation);
                    instance.set_solution(new_solution);
                }
            }
        }
    }
}

void
improvement(Pivoting pivoting_rule, Neighbourhood neighbourhood_rule, Instance& instance)
{
    switch (pivoting_rule)
    {
    case FIRST:
        first_improvement(neighbourhood_rule, instance); 
        break;
    case BEST:
        best_improvement(neighbourhood_rule, instance);
        break;
    default:
        assert(false);
        break;
    }
}