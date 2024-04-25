#ifndef PIVOTING_HPP
#define PIVOTING_HPP

#include "../../lop/configuration.hpp"

Solution& first_improvement(Neighbourhood neighbourhood_rule, Instance& instance, Solution& solution);
Solution& best_improvement(Neighbourhood neighbourhood_rule, Instance& instance, Solution& solution);
Solution& improvement(Pivoting pivoting_rule, Neighbourhood neighbourhood_rule, Instance& instance, Solution& solution);

#endif