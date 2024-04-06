#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <filesystem>

#include "instance.hpp"
#include "configuration.hpp"

Instance::Instance() 
{
}

Instance::Instance(std::string filepath) 
{
    check_file(filepath);
    save_matrix(filepath);
    if (VERBOSE) {
        print();
    }
}

void Instance::check_file(std::string filepath)
{
    if (!std::filesystem::exists(filepath)) {
        std::cerr << "Error: file " << filepath << " does not exist" << std::endl;
        exit(1);
    }

    auto path = std::filesystem::path(filepath);
    this->name_ = path.filename().string();
}

void Instance::save_matrix(std::string filepath)
{
    std::ifstream filestream(filepath);
    if (!filestream.is_open()) {
        std::cerr << "Error: could not open file " << filepath << std::endl;
        exit(1);
    }

    std::stringstream ss;
    ss << filestream.rdbuf();
    ss >> this->size_;

    this->permutation_ = std::vector<int>(size_);
    
    this->matrix_ = std::vector<std::vector<int>>(size_, std::vector<int>(size_));
    for (unsigned i = 0 ; i < size_ ; i++) {
        for (unsigned j = 0 ; j < size_; j++) {
            ss >> matrix_[i][j];
            seed_ += matrix_[i][j];
        }
    }
}

std::string
Instance::name() const
{
    return this->name_;
}

int
Instance::size() const
{
    return this->size_;
}

std::vector<std::vector<int>>
Instance::matrix() const
{
    return this->matrix_;
}

std::vector<int>
Instance::permutation() const
{
    return this->permutation_;
}

int
Instance::score() const
{
    return this->score_;
}

int
Instance::seed() const
{
    return this->seed_;
}

void
Instance::set_permutation(std::vector<int> permutation)
{
    this->permutation_ = permutation;
}

void
Instance::permute_rows()
{
    for (unsigned i = 0; i < size(); ++i) {
        if (i != permutation_[i]) {
            std::swap(matrix_[i], matrix_[permutation_[i]]);
        }
    }
}

void
Instance::set_score(int score)
{
    this->score_ = score;
}

std::array<float, NUMBER_ALGORITHMS>
Instance::relative_percentage_deviations()
{
    return this->relative_percentage_deviations_;
}

std::array<float, NUMBER_ALGORITHMS>
Instance::computation_times()
{
    return this->computation_times_;
}

float
Instance::average_relative_percentage_deviation()
{
    return this->average_relative_percentage_deviation_;
}

float
Instance::sum_of_computation_time()
{
    return this->sum_of_computation_time_;
}

void
Instance::print()
{
    std::cerr << "- Instance - " << std::endl
              << "Name: " << this->name_ << std::endl
              << "Size: " << this->size_ << std::endl
              << "Seed: " << this->seed_ << std::endl
              << std::endl;
}