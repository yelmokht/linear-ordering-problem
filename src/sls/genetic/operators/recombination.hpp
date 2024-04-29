#ifndef RECOMBINATION_HPP
#define RECOMBINATION_HPP

#include "../../../lop/configuration.hpp"
#include "../../../lop/population.hpp"

Population cx_recombination(Instance& instance, Population& population);
Population dpx_recombination(Instance& instance, Population& population);
Population ob_recombination(Instance& instance, Population& population);
Population op_recombination(Instance& instance, Population& population);
Population ox_recombination(Instance& instance, Population& population);
Population pmx_recombination(Instance& instance, Population& population);
Population po_recombination(Instance& instance, Population& population);
Population rank_recombination(Instance& instance, Population& population);
Population recombination(Recombination recombination_rule, Instance& instance, Population& population);

#endif