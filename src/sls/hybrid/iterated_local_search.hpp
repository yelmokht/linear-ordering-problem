#ifndef ITERATED_LOCAL_SEARCH_HPP
#define ITERATED_LOCAL_SEARCH_HPP

#include "../../lop/instance.hpp"
#include "../../lop/configuration.hpp"


class IteratedLocalSearch
{
    public:
        IteratedLocalSearch();
        void local_search(Pivoting pivoting_rule, Instance& instance, Solution& solution);
        void perturbation(Pivoting pivoting_rule, Instance& instance, Solution& solution);
        void run(Pivoting pivoting_rule, Instance& instance);
};

#endif