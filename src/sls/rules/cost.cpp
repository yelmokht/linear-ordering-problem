#include <cassert>

#include "cost.hpp"

int cost_function(Instance& instance, Solution& solution) {
    auto matrix = instance.matrix();
    auto permutation = solution.permutation();
    int size = instance.size();
    int cost = 0;
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            cost += matrix[permutation[i]][permutation[j]];
        }
    }
    return cost;
}

int transpose_cost(Instance& instance, Solution& old_solution, int i, int j) {
    auto matrix = instance.matrix();
    auto oldP = old_solution.permutation();
    unsigned oldPfirst = oldP[i];
    unsigned oldPsecond = oldP[j];
    int delta = matrix[oldPsecond][oldPfirst] - matrix[oldPfirst][oldPsecond];
    return delta;
}

int exchange_cost(Instance& instance, Solution& old_solution, int i, int j) {
    auto matrix = instance.matrix();
    auto oldP = old_solution.permutation();
    unsigned oldPfirst = oldP[i];
    unsigned oldPsecond = oldP[j];

    int delta = matrix[oldPsecond][oldPfirst] - matrix[oldPfirst][oldPsecond];
    for (unsigned k = i + 1 ; k < j ; k++) {
        delta += matrix[oldPsecond][oldP[k]] - matrix[oldPfirst][oldP[k]];
        delta += matrix[oldP[k]][oldPfirst] - matrix[oldP[k]][oldPsecond];
    }

    return delta;
}

int insert_cost(Instance& instance, Solution& old_solution, int i, int j) {
    auto matrix = instance.matrix();
    auto oldP = old_solution.permutation();
    unsigned oldPfirst = oldP[i];
    
    int delta = 0;
    if (i < j) {
        for (unsigned k = i + 1 ; k <= j ; k++) {
            delta += matrix[oldP[k]][oldPfirst] - matrix[oldPfirst][oldP[k]];
        }
    }
    else if (i > j) {
        for (unsigned k = j ; k <= i - 1 ; k++) {
            delta += matrix[oldPfirst][oldP[k]] - matrix[oldP[k]][oldPfirst];
        }
    }
    
    return delta;
}

int evaluate(Neighbourhood neighbourhood_rule, Instance& instance, Solution& old_solution, int i, int j)
{
    switch (neighbourhood_rule)
    {
        case TRANSPOSE:
            return transpose_cost(instance, old_solution, i, j);
        case EXCHANGE:
            return exchange_cost(instance, old_solution, i, j);
        case INSERT:
            return insert_cost(instance, old_solution, i, j);
        default:
            assert(false);
    }
}