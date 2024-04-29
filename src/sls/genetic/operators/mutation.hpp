#ifndef MUTATION_HPP
#define MUTATION_HPP

#include "../../../lop/configuration.hpp"
#include "../../../lop/population.hpp"


Population exchange_mutation(Instance& instance, Population& population, double mutation_rate);
Population insert_mutation(Instance& instance, Population& population, double mutation_rate);
Population invert_mutation(Instance& instance, Population& population, double mutation_rate);
Population scramble_mutation(Instance& instance, Population& population, double mutation_rate);
Population swap_mutation(Instance& instance, Population& population, double mutation_rate);
Population mutation(Mutation mutation_rule, Instance& instance, Population& population, double mutation_rate);

#endif