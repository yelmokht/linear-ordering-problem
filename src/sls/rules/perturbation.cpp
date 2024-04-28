#include <cassert>

#include "perturbation.hpp"
#include "pivoting.hpp"

Solution& exchange(Instance& instance, Solution& solution)
{
    return best_improvement(Neighbourhood::EXCHANGE, instance, solution);
}

Solution& perturbation(Perturbation pertubartion_rule, Instance& instance, Solution& solution)
{
    switch (pertubartion_rule)
    {
        case Perturbation::EXCHANGE:
            return exchange(instance, solution);
        default:
            assert(false);
            break;
    }
}