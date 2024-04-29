#include <iostream>

#include "population.hpp"


Population::Population(int size) {
    this->size_ = size;
    this->solutions_ = std::vector<Solution>(size);
}

int Population::size() const {
    return this->size_;
}

std::vector<Solution>& Population::solutions() {
    return this->solutions_;
}

Solution& Population::solution(int i) {
    return this->solutions_[i];
}

Solution Population::best_solution() {
    return this->solutions_[0];
}

void Population::set_solutions(std::vector<Solution> solutions) {
    this->solutions_ = solutions;
}

void Population::set_solution(int i, Solution solution) {
    this->solutions_[i] = solution;
}

void Population::print() {
    for (auto i = 0; i < this->size_; i++) {
        std::cout << "Solution " << i << std::endl;
        this->solutions_[i].print();
    }
}