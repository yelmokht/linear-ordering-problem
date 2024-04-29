#ifndef INITIALISATION_HPP
#define INITIALISATION_HPP

#include "../../../lop/configuration.hpp"
#include "../../../lop/population.hpp"

Population random_initialisation(Instance& instance, int population_size);
Population bi_initialisation(Instance& instance, int population_size);
Population initialisation(InitialSolution initial_solution_rule, Instance& instance, int population_size);
#endif