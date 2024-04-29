#ifndef SUBSIDIARY_LOCAL_SEARCH_HPP
#define SUBSIDIARY_LOCAL_SEARCH_HPP

#include "../../../lop/configuration.hpp"
#include "../../../lop/population.hpp"

Population& insert(Instance& instance, Population& population);
Population& subsidiary_local_search(LocalSearch local_search_rule, Instance& instance, Population& population);

#endif