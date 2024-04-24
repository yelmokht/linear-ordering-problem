#ifndef COST_HPP
#define COST_HPP

#include "../../lop/configuration.hpp"

int cost_function(Instance& instance, Solution& solution);
int transpose_cost(Instance& instance, Solution& old_solution, int i, int j);
int exchange_cost(Instance& instance, Solution& old_solution, int i, int j);
int insert_cost(Instance& instance, Solution& old_solution, int i, int j);
int transpose_exchange_insert_cost(Instance& instance, Solution& old_solution, int i, int j);
int transpose_insert_exchange_cost(Instance& instance, Solution& old_solution, int i, int j);
int evaluate(Neighbourhood neighbourhood_rule, Instance& instance, Solution& old_solution, int i, int j);

#endif