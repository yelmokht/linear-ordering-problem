#ifndef LOCAL_SEARCH_HPP
#define LOCAL_SEARCH_HPP

#include "../../lop/configuration.hpp"

Solution& insert(Instance& instance, Solution& solution);
Solution& local_search(LocalSearch local_search_rule, Instance& instance, Solution& solution);

#endif 