#include <algorithm>
#include <vector>
#include <random>

#include "crossover.hpp"
#include "../../rules/cost.hpp"

/**
 * @brief Applies the Cycle Crossover operator to two parent solutions.
 * 
 * @param instance The instance for which to apply the operator.
 * @param parent_1 The first parent solution.
 * @param parent_2 The second parent solution.
 * @return std::pair<Solution, Solution> The offspring solutions.
 */
std::pair<Solution, Solution> cx(Instance& instance, Solution& parent_1, Solution& parent_2)
{
    int size = parent_1.size();
    std::vector<int> parent_1_permutation = parent_1.permutation();
    std::vector<int> parent_2_permutation = parent_2.permutation();
    std::vector<int> offspring_1_permutation(size, -1);
    std::vector<int> offspring_2_permutation(size, -1);
    std::vector<bool> assigned(size, false);

    int index = rand() % size;
    int start_index = index;

    do {
        offspring_1_permutation[index] = parent_1_permutation[index];
        assigned[parent_1_permutation[index]] = true;
        index = std::distance(parent_1_permutation.begin(), std::find(parent_1_permutation.begin(), parent_1_permutation.end(), parent_2_permutation[index]));
    } while (index != start_index);

    for (int i = 0; i < size; ++i) {
        if (offspring_1_permutation[i] == -1) {
            offspring_1_permutation[i] = parent_2_permutation[i];
            assigned[parent_2_permutation[i]] = true;
        }
    }

    for (int i = 0; i < size; ++i) {
        if (!assigned[parent_1_permutation[i]]) {
            offspring_2_permutation[i] = parent_1_permutation[i];
            assigned[parent_1_permutation[i]] = true;
        } else {
            offspring_2_permutation[i] = parent_2_permutation[i];
        }
    }

    // Create offspring solutions and evaluate scores
    Solution offspring_1(size, offspring_1_permutation);
    offspring_1.set_score(evaluate(instance, offspring_1));
    Solution offspring_2(size, offspring_2_permutation);
    offspring_2.set_score(evaluate(instance, offspring_2));

    return std::make_pair(offspring_1, offspring_2);
}

