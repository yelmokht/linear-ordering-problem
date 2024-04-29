#ifndef COST_HPP
#define COST_HPP

#include "../../lop/configuration.hpp"

int evaluate(Instance& instance, Solution& solution);
int transpose_delta(Instance& instance, Solution& solution, unsigned i, unsigned j);
int exchange_delta(Instance& instance, Solution& solution, unsigned i, unsigned j);
int insert_delta(Instance& instance, Solution& solution, unsigned i, unsigned j);
int delta(Neighbourhood neighbourhood_rule, Instance& instance, Solution& solution, unsigned i, unsigned j);

#endif