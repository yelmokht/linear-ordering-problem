#include <algorithm>
#include <vector>
#include <random>

#include "crossover.hpp"

std::pair<Solution, Solution> cx(Solution& parent_1, Solution& parent_2)
{
    std::vector<int> parent_1_permutation = parent_1.permutation();
    std::vector<int> parent_2_permutation = parent_2.permutation();
    std::vector<int> offspring_1_permutation(parent_1.size(), -1);
    std::vector<int> offspring_2_permutation(parent_1.size(), -1);

    int size = parent_1.size();
    bool cycle_unfound = true;
    int index = rand() % size;
    std::vector<int> visited_indexes(size);
    visited_indexes[0] = index;
    int new_index = 0;

    while(cycle_unfound) {
        auto it = std::find(parent_1_permutation.begin(), parent_1_permutation.end(), parent_2_permutation[index]);
        if (it != parent_1_permutation.end()) {
            int new_index = std::distance(parent_1_permutation.begin(), it);
            offspring_1_permutation[index] = parent_1_permutation[index];
            offspring_2_permutation[index] = parent_2_permutation[index];
            index = new_index;
        } else {
            cycle_unfound = false;
        }
        visited_indexes.push_back(new_index);
    }

    for (int i = 0; i < size; i++) {
        if (offspring_1_permutation[i] == -1) {
            offspring_1_permutation[i] = parent_2_permutation[i];
            offspring_2_permutation[i] = parent_1_permutation[i];
        }
    }

    Solution offspring_1(size, offspring_1_permutation);
    Solution offspring_2(size, offspring_2_permutation);

    return std::make_pair(offspring_1, offspring_2);
}