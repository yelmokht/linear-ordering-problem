#include <iostream>
#include <cassert>

#include "neighbourhood.hpp"
#include "pivoting.hpp"
#include "cost.hpp"

bool
transpose_is_valid(unsigned i, unsigned j)
{
    return j == i + 1;
}

bool
exchange_is_valid(unsigned i, unsigned j)
{
    return j > i;
}

bool
insert_is_valid(unsigned i, unsigned j)
{
    return i != j;
}

bool
neighbourhood_is_valid(Neighbourhood neighbourhood_rule, unsigned i, unsigned j)
{
    switch (neighbourhood_rule)
    {
        case Neighbourhood::TRANSPOSE:
            return transpose_is_valid(i, j);
        case Neighbourhood::EXCHANGE:
            return exchange_is_valid(i, j);
        case Neighbourhood::INSERT:
            return insert_is_valid(i, j);
        default:
            assert(false);
    }
}

Solution&
transpose(Solution& solution, unsigned i, unsigned j) 
{
    solution.transpose_permutation(i, i+1);
    return solution;
}

Solution&
exchange(Solution& solution, unsigned i, unsigned j)
{
    solution.exchange_permutation(i, j);
    return solution;
}

Solution&
insert(Solution& solution, unsigned i, unsigned j)
{  
    solution.insert_permutation(i, j);
    return solution;
}


Solution&
apply_permutation(Neighbourhood neighbourhood_rule, Solution& solution, unsigned i, unsigned j)
{
    switch (neighbourhood_rule)
    {
        case Neighbourhood::TRANSPOSE:
            return transpose(solution, i, j);
        case Neighbourhood::EXCHANGE:
            return exchange(solution, i, j);
        case Neighbourhood::INSERT:
            return insert(solution, i, j);
        default:
            assert(false);
    }
}