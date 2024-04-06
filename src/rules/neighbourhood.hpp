#ifndef NEIGHBOURHOOD_HPP
#define NEIGHBOURHOOD_HPP

#include "../configuration.hpp"

void print_permutation(std::vector<int> old_permutation, std::vector<int> permutation);
std::vector<int> transpose(std::vector<int> permutation, int i);
std::vector<int> exchange(std::vector<int> permutation, int i, int j);
std::vector<int> insert(std::vector<int> permutation, int i, int j);
std::vector<int> transpose_exchange_insert(std::vector<int> permutation, int i, int j);
std::vector<int> transpose_insert_exchange(std::vector<int> permutation, int i, int j);
std::vector<int> neighbourhood(Neighbourhood neighbourhood_rule, Instance& instance, int i, int j);

#endif
