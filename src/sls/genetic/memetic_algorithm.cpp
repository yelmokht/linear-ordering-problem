#include <chrono>

#include "memetic_algorithm.hpp"

MemeticAlgorithm::MemeticAlgorithm(InitialSolution initial_solution_rule, LocalSearch local_search_rule, Recombination recombination_rule, Mutation mutation_rule, Selection selection_rule)
{
    this->initial_solution_rule = initial_solution_rule;
    this->local_search_rule = local_search_rule;
    this->recombination_rule = recombination_rule;
    this->mutation_rule = mutation_rule;
    this->selection_rule = selection_rule;
}


void
MemeticAlgorithm::run(Instance& instance)
{
}