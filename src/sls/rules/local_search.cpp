#include <cassert>

#include "local_search.hpp"
#include "pivoting.hpp"
#include "neighbourhood.hpp"

Solution& insert(Instance& instance, Solution& solution)
{
    return best_improvement(Neighbourhood::INSERT, instance, solution);
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