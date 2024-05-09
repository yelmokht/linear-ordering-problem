#include <cassert>
#include <iostream>

#include "cost.hpp"

/**
 * @brief Evaluates the cost of a solution for the given instance.
 * 
 * @param instance The instance for which to evaluate the solution.
 * @param solution The solution to evaluate.
 * 
 * @return int The cost of the solution.
 */
int evaluate(Instance& instance, Solution& solution) {
    auto matrix = instance.matrix();
    auto permutation = solution.permutation();
    int size = instance.size();
    int cost = 0;
    for (unsigned i = 0; i < size; i++) {
        for (unsigned j = i + 1; j < size; j++) {
            cost += matrix[permutation[i]][permutation[j]];
        }
    }
    return cost;
}

/**
 * @brief Calculates the delta of a transpose move.
 * 
 * @param instance The instance for which to calculate the delta.
 * @param solution The solution for which to calculate the delta.
 * @param i The first index of the move.
 * @param j The second index of the move.
 * 
 * @return int The delta of the move.
 */
int transpose_delta(Instance& instance, Solution& solution, unsigned i, unsigned j) {
    auto matrix = instance.matrix();
    auto permutation = solution.permutation();
    unsigned k = permutation[i];
    unsigned l = permutation[j];
    int delta = matrix[l][k] - matrix[k][l];
    return delta;
}

/**
 * @brief Calculates the delta of an exchange move.
 * 
 * @param instance The instance for which to calculate the delta.
 * @param solution The solution for which to calculate the delta.
 * @param i The first index of the move.
 * @param j The second index of the move.
 * 
 * @return int The delta of the move.
 */
int exchange_delta(Instance& instance, Solution& solution, unsigned i, unsigned j) {
    auto matrix = instance.matrix();
    auto permutation = solution.permutation();
    unsigned k = permutation[i];
    unsigned l = permutation[j];
    int delta = matrix[l][k] - matrix[k][l];

    for (unsigned m = i + 1; m < j; m++) {
        unsigned n = permutation[m];
        delta += matrix[l][n] - matrix[k][n];
        delta += matrix[n][k] - matrix[n][l];
    }

    return delta;
}

/**
 * @brief Calculates the delta of an insert move.
 * 
 * @param instance The instance for which to calculate the delta.
 * @param solution The solution for which to calculate the delta.
 * @param i The first index of the move.
 * @param j The second index of the move.
 * 
 * @return int The delta of the move.
 */
int insert_delta(Instance& instance, Solution& solution, unsigned i, unsigned j) {
    auto matrix = instance.matrix();
    auto permutation = solution.permutation();
    unsigned k = permutation[i];
    int delta = 0;
    
    if (i < j) {
        for (unsigned l = i + 1; l < j + 1 ; l++) {
            unsigned m = permutation[l];
            delta += matrix[m][k] - matrix[k][m];
        }
    }
    
    if (i > j) {
        for (unsigned l = j; l < i; l++) {
            unsigned m = permutation[l];
            delta += matrix[k][m] - matrix[m][k];
        }
    }
    
    return delta;
}

/**
 * @brief Calculates the delta of a move.
 * 
 * @param neighbourhood_rule The neighbourhood rule.
 * @param instance The instance for which to calculate the delta.
 * @param solution The solution for which to calculate the delta.
 * @param i The first index of the move.
 * @param j The second index of the move.
 * 
 * @return int The delta of the move.
 */
int delta(Neighbourhood neighbourhood_rule, Instance& instance, Solution& solution, unsigned i, unsigned j)
{
    switch (neighbourhood_rule)
    {
        case Neighbourhood::TRANSPOSE:
            return transpose_delta(instance, solution, i, j);
        case Neighbourhood::EXCHANGE:
            return exchange_delta(instance, solution, i, j);
        case Neighbourhood::INSERT:
            return insert_delta(instance, solution, i, j);
        default:
            assert(false);
    }
}