#include <iostream>
#include <cassert>

#include "neighbourhood.hpp"
#include "pivoting.hpp"
#include "cost.hpp"

Solution
transpose(Instance& instance, Solution solution, int i, int j) 
{
    if (j == i + 1) {
        solution.set_score(solution.score() + evaluate(TRANSPOSE, instance, solution, i, i+1));
        solution.transpose_permutation(i, i+1);
    }

    return solution;
}

Solution
exchange(Instance& instance, Solution solution, int i, int j)
{
    if (j > i) {
        solution.set_score(solution.score() + evaluate(EXCHANGE, instance, solution, i, j));
        solution.exchange_permutation(i, j);
    }

    return solution;
}

Solution
insert(Instance& instance, Solution solution, int i, int j)
{
    if (i != j && i != j + 1) {       
        solution.set_score(solution.score() + evaluate(INSERT, instance, solution, i, j));
        solution.insert_permutation(i, j);
    }

    return solution;
}


Solution
neighbourhood(Neighbourhood neighbourhood_rule, Instance& instance, Solution solution, int i, int j)
{
    switch (neighbourhood_rule)
    {
        case TRANSPOSE:
            return transpose(instance, solution, i, j);
        case EXCHANGE:
            return exchange(instance, solution, i, j);
        case INSERT:
            return insert(instance, solution, i, j);
        default:
            assert(false);
    }
}