// #include "sls/genetic/operators/recombination.hpp"

// // Choose one or combine multiple crossover operators

// /**
//  * Crossover operator. CX is considered as the best in the paper
// */
// void
// cx_crossover(Population& population, Instance& instance)
// {
//     for (auto& permutation : population) {
//         if (random_double() < instance.crossover_rate()) {
//             auto i = random_int(0, instance.size() - 1);
//             auto j = random_int(0, instance.size() - 1);
//             if (i > j) std::swap(i, j);
//             std::vector<int> child(instance.size(), -1);
//             for (int k = i; k <= j; ++k) {
//                 child[k] = permutation[k];
//             }
//             int idx = 0;
//             for (int k = 0; k < instance.size(); ++k) {
//                 if (child[k] == -1) {
//                     while (std::find(child.begin(), child.end(), permutation[idx]) != child.end()) {
//                         ++idx;
//                     }
//                     child[k] = permutation[idx];
//                 }
//             }
//             permutation = child;
//         }
//     }
// }

// /**
//  * Crossover operator. OB is considered also as the best in the paper
// */
// void
// ob_crossover(Population& population, Instance& instance)
// {
//     for (auto& permutation : population) {
//         if (random_double() < instance.crossover_rate()) {
//             auto i = random_int(0, instance.size() - 1);
//             auto j = random_int(0, instance.size() - 1);
//             if (i > j) std::swap(i, j);
//             std::vector<int> child(instance.size(), -1);
//             for (int k = i; k <= j; ++k) {
//                 child[k] = permutation[k];
//             }
//             int idx = 0;
//             for (int k = 0; k < instance.size(); ++k) {
//                 if (child[k] == -1) {
//                     while (std::find(child.begin(), child.end(), permutation[idx]) != child.end()) {
//                         ++idx;
//                     }
//                     child[k] = permutation[idx];
//                 }
//             }
//             permutation = child;
//         }
//     }
// }