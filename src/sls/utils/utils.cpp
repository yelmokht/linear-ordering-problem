#include <iostream>

#include "utils.hpp"

/**
 * @brief Checks if a permutation contains duplicates.
 * 
 * @param permutation The permutation to check.
 * 
 * @return bool True if the permutation contains duplicates, false otherwise.
 */
bool check_duplicates_permutation(std::vector<int> permutation) {
    for (int i = 0; i < permutation.size(); i++) {
        for (int j = i + 1; j < permutation.size(); j++) {
            if (permutation[i] == permutation[j]) {
                std::cerr << "Duplicate found in permutation" << std::endl;
                return true;
            }
        }
    }
    return false;
}

/**
 * @brief Checks if a population contains duplicates.
 * 
 * @param population The population to check.
 * 
 * @return bool True if the population contains duplicates, false otherwise.
 */
bool check_duplicates(Population population) {
    for (Solution solution : population.solutions()) {
        auto result = check_duplicates_permutation(solution.permutation());
        if (result) {
            std::cerr << "Duplicate found in one solution in population" << std::endl;
            exit(1);
        }
    }
    return false;
}