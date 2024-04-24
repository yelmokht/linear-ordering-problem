#include <chrono>

#include "memetic_algorithm.hpp"

MemeticAlgorithm::MemeticAlgorithm(double mutation_rate, int population_size)
{
    this->mutation_rate = mutation_rate;
    this->population_size = population_size;
}

// void
// MemeticAlgorithm::local_search(Instance& instance)
// {
//     for (auto& permutation : population) {
//         instance.set_permutation(permutation);
//         instance.set_solution(compute_cost(instance, permutation));
//         transpose(Pivoting::RANDOM, instance);
//     }
// }


// // Implement the memetic algorithm here
void
MemeticAlgorithm::run(Instance& instance)
{
    auto start = std::chrono::high_resolution_clock::now();
    // initialize_population(instance);
    while (std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - start).count() < max_time) {
        // local_search(instance);
        // crossover(instance);
        // mutation(instance);
        // selection(instance);
    }
}