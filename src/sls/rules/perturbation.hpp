#ifndef PERTURBATION_HPP
#define PERTURBATION_HPP

#include "../../lop/configuration.hpp"

Solution& exchange(Instance& instance, Solution& solution);
Solution& random_exchange(Instance& instance, Solution& solution, int moves);
Solution& perturbation(Perturbation pertubartion_rule, Instance& instance, Solution& solution, int moves = 0);

#endif 