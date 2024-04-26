#ifndef ITERATED_LOCAL_SEARCH_HPP
#define ITERATED_LOCAL_SEARCH_HPP

#include "../../lop/instance.hpp"
#include "../../lop/configuration.hpp"


class IteratedLocalSearch
{
    private:
        InitialSolution initial_solution_rule;
        LocalSearch local_search_rule;
        Perturbation perturbation_rule;

    public:
        IteratedLocalSearch(InitialSolution initial_solution_rule, LocalSearch local_search_rule, Perturbation perturbation_rule);
        void run(Instance& instance);
};

#endif