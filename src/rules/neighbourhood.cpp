#include <iostream>
#include <cassert>

#include "neighbourhood.hpp"

void
print_permutation(std::vector<int> old_permutation, std::vector<int> new_permutation)
{
    std::cout << std::endl;
    std::cout << "Old permutation: ";
    for (auto i : old_permutation) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    std::cout << "New permutation: ";
    for (auto i : new_permutation) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

std::vector<int>
transpose(std::vector<int> permutation, int i) 
{
    std::swap(permutation[i], permutation[i + 1]);
    return permutation;
}


std::vector<int>
exchange(std::vector<int> permutation, int i, int j)
{
    std::swap(permutation[i], permutation[j]);
    return permutation;
}

std::vector<int>
insert(std::vector<int> permutation, int i, int j)
{
    if (i == j) return permutation;
    
    int value = permutation[i];
    
    if (i < j) {
        permutation.erase(permutation.begin() + i);
        permutation.insert(permutation.begin() + j - 1, value);
    } else {
        permutation.insert(permutation.begin() + j, value);
        permutation.erase(permutation.begin() + i + 1);
    }
    return permutation;
}

std::vector<int>
transpose_exchange_insert(std::vector<int> permutation, int i, int j)
{
    permutation = transpose(permutation, i);
    permutation = exchange(permutation, i, j);
    permutation = insert(permutation, i, j);
    return permutation;
}

std::vector<int>
transpose_insert_exchange(std::vector<int> permutation, int i, int j)
{
    permutation = transpose(permutation, i);
    permutation = insert(permutation, i, j);
    permutation = exchange(permutation, i, j);
    return permutation;
}

std::vector<int>
neighbourhood(Neighbourhood neighbourhood_rule, Instance& instance, int i, int j)
{
    std::vector<int> new_permutation = instance.permutation();
    switch (neighbourhood_rule)
    {
        case TRANSPOSE:
            new_permutation = transpose(new_permutation, i);
            break;
        case EXCHANGE:
            new_permutation = exchange(new_permutation, i, j);
            break;
        case INSERT:
            new_permutation = insert(new_permutation, i, j);
            break;
        case TRANSPOSE_EXCHANGE_INSERT:
            new_permutation = transpose_exchange_insert(new_permutation, i, j);
            break;
        case TRANSPOSE_INSERT_EXCHANGE:
            new_permutation = transpose_insert_exchange(new_permutation, i, j);
            break;
        default:
            assert(false);
            break;
    }
    if (VERBOSE) 
    {
        print_permutation(instance.permutation(), new_permutation);
    }
    return new_permutation;
}