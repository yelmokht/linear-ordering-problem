#ifndef NEIGHBOURHOOD_HPP
#define NEIGHBOURHOOD_HPP

#include "../configuration.hpp"

int compute_cost(Instance& instance, std::vector<int>& permutation);
int transpose(Pivoting pivoting_rule, Instance& instance);
int exchange(Pivoting pivoting_rule, Instance& instance);
int insert(Pivoting pivoting_rule, Instance& instance);
int transpose_exchange_insert(Pivoting pivoting_rule, Instance& instance);
int transpose_insert_exchange(Pivoting pivoting_rule, Instance& instance);
void neighbourhood(Neighbourhood neighbourhood_rule, Pivoting pivoting_rule, Instance& instance);

#endif
