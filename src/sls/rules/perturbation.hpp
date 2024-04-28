#ifndef PERTURBATION_HPP
#define PERTURBATION_HPP

#include "../../lop/configuration.hpp"

Solution& exchange(Instance& instance, Solution& solution);
Solution& perturbation(Perturbation pertubartion_rule, Instance& instance, Solution& solution);

#endif 