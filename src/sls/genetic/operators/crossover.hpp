#ifndef CROSSOVER_HPP
#define CROSSOVER_HPP

#include "../../../lop/instance.hpp"
#include "../../../lop/solution.hpp"

std::pair<Solution, Solution> cx(Instance& instance, Solution& parent_1, Solution& parent_2);

#endif