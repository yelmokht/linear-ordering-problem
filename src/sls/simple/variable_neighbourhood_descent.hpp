#ifndef VARIABLE_NEIGHBOURHOOD_DESCENT_HPP
#define VARIABLE_NEIGHBOURHOOD_DESCENT_HPP

#include "../../lop/instance.hpp"
#include "../rules/initial_solution.hpp"
#include "../rules/neighbourhood.hpp"
#include "../rules/pivoting.hpp"

class VariableNeighbourhoodDescent
{
    private:
        InitialSolution initial_solution_rule;
        Neighbourhood neighbourhood_rule;
        Pivoting pivoting_rule;
        
    public:
        VariableNeighbourhoodDescent(InitialSolution initial_solution_rule, Neighbourhood neighbourhood_rule, Pivoting pivoting_rule);
        void run(Instance& instance);
};

#endif