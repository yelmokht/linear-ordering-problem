#ifndef ITERATIVE_IMPROVEMENT_HPP
#define ITERATIVE_IMPROVEMENT_HPP

#include "../../lop/configuration.hpp"

class IterativeImprovement
{
    private:
        InitialSolution initial_solution_rule;
        Neighbourhood neighbourhood_rule;
        Pivoting pivoting_rule;

    public:
        IterativeImprovement(InitialSolution initial_solution_rule, Neighbourhood neighbourhood_rule, Pivoting pivoting_rule);
        void run(Instance& instance);
};

#endif