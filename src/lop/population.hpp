#ifndef POPULATION_HPP
#define POPULATION_HPP

#include <vector>

#include "solution.hpp"

class Population
{
    private:
        int size_;
        std::vector<Solution> solutions_;
        
    public:
        Population(int size);
        int size() const;
        std::vector<Solution>& solutions();
        Solution& solution(int i);
        Solution best_solution();
        void set_solutions(std::vector<Solution> solutions);
        void set_solution(int i, Solution solution);
        void print();
};

#endif