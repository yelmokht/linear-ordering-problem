#ifndef MEMETIC_ALGORITHM_HPP
#define MEMETIC_ALGORITHM_HPP

#include <vector>

#include "../../lop/configuration.hpp"

class MemeticAlgorithm
{
    private:
        InitialSolution initial_solution_rule;
        LocalSearch local_search_rule;
        Recombination recombination_rule;
        Mutation mutation_rule;
        Selection selection_rule;
        double mutation_rate = 0.2;
        int population_size = 100;
        double max_time;

    public:
        MemeticAlgorithm(InitialSolution initial_solution_rule, LocalSearch local_search_rule, Recombination recombination_rule, Mutation mutation_rule, Selection selection_rule);
        void run(Instance& instance);
};

#endif