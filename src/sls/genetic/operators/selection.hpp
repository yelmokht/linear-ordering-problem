#ifndef SELECTION_HPP
#define SELECTION_HPP

#include "../../../lop/configuration.hpp"
#include "../../../lop/population.hpp"

Population rank_selection(Instance& instance, Population& current_population, Population& recombined_population, Population& mutated_population);
Population roulette_selection(Instance& instance, Population& current_population, Population& recombined_population, Population& mutated_population);
Population tournament_selection(Instance& instance, Population& current_population, Population& recombined_population, Population& mutated_population);
Population uniform_selection(Instance& instance, Population& current_population, Population& recombined_population, Population& mutated_population);
Population selection(Selection selection_rule, Instance& instance, Population& current_population, Population& recombined_population, Population& mutated_population);

#endif