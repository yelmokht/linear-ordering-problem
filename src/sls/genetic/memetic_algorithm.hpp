#ifndef MEMETIC_ALGORITHM_HPP
#define MEMETIC_ALGORITHM_HPP

#include <vector>

#include "../../lop/configuration.hpp"

class MemeticAlgorithm
{
    private:
        double mutation_rate;
        int population_size;
        std::vector<Solution> population; //of population_size
        double max_time;

    public:
        MemeticAlgorithm(double mutation_rate, int population_size);
        // void initialize_population(Instance& instance);
        // void local_search(Instance& instance);
        // void crossover(Instance& instance);
        // void mutation(Instance& instance);
        // void selection(Instance& instance);
        void run(Instance& instance);
};

#endif