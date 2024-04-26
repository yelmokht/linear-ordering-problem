#ifndef NEIGHBOURHOOD_HPP
#define NEIGHBOURHOOD_HPP

#include "../../lop/configuration.hpp"
#include "../../lop/instance.hpp"
#include "../../lop/solution.hpp"


bool transpose_is_valid(unsigned i, unsigned j);
bool exchange_is_valid(unsigned i, unsigned j);
bool insert_is_valid(unsigned i, unsigned j);
bool neighbourhood_is_valid(Neighbourhood neighbourhood_rule, unsigned i, unsigned j);

Solution& transpose(Solution& solution, unsigned i, unsigned j);
Solution& exchange(Solution& solution, unsigned i, unsigned j);
Solution& insert(Solution& solution, unsigned i, unsigned j);
Solution& apply_permutation(Neighbourhood neighbourhood_rule, Solution& solution, unsigned i, unsigned j);

#endif
