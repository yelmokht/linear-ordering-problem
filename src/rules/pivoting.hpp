#ifndef PIVOTING_HPP
#define PIVOTING_HPP

#include "../configuration.hpp"

int compute_cost(Instance& instance, std::vector<int> permutation);
void first_improvement(Neighbourhood neighborhood_rule, Instance& instance);
void best_improvement(Neighbourhood neighborhood_rule, Instance& instance);
void improvement(Pivoting pivoting_rule, Neighbourhood neighbourhood_rule, Instance& instance);

#endif