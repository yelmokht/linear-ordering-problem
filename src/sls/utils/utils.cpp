#include <iostream>

#include "utils.hpp"

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