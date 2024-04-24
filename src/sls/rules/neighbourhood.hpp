#ifndef NEIGHBOURHOOD_HPP
#define NEIGHBOURHOOD_HPP

#include "../../lop/configuration.hpp"
#include "../../lop/instance.hpp"
#include "../../lop/solution.hpp"

Solution transpose(Instance& instance, Solution solution, int i, int j);
Solution exchange(Instance& instance, Solution solution, int i, int j);
Solution insert(Instance& instance, Solution solution, int i, int j);
// Solution transpose_exchange_insert(Instance& instance, Solution& solution, int i, int j);
// Solution transpose_insert_exchange(Instance& instance, Solution& solution, int i, int j);
Solution neighbourhood(Neighbourhood neighbourhood_rule, Instance& instance, Solution solution, int i, int j);

#endif
