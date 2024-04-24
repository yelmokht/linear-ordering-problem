// #include "mutation.hpp"


// // DONT FORGET TO SET PARAMETER BASED ON ILS (ON PAPER IS 7)
// void random_interchange_mutation(Population& population, Instance& instance)
// {
//     for (auto& permutation : population) {
//         if (random_double() < instance.mutation_rate()) {
//             auto i = random_int(0, instance.size() - 1);
//             auto j = random_int(0, instance.size() - 1);
//             std::swap(permutation[i], permutation[j]); // To connect with exchange method in neighbourhood.cpp
//         }
//     }
// }