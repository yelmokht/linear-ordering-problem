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


/**
 * Constructor for the Instance class.
 * 
 * @param filepath The path to the file containing the instance.
*/
Instance::Instance(std::string filepath) 
{
    check_file(filepath);
    save_matrix(filepath);
    save_best_known_solution(BEST_KNOWN_FILE_PATH);
    if (VERBOSE) {
        print();
    }
}

/**
 * Checks if the file exists and sets the name of the instance.
 * 
 * @param filepath The path to the file to check.
*/
void 
Instance::check_file(std::string filepath)
{
    if (!std::filesystem::exists(filepath)) {
        std::cerr << "Error: file " << filepath << " does not exist" << std::endl;
        exit(1);
    }

    auto path = std::filesystem::path(filepath);
    this->name_ = path.filename().string();
}


/**
 * Saves the matrix from the file to the instance.
 * Sets the size of the instance and the seed.
 * @param filepath The path to the file containing the instance.
*/
void 
Instance::save_matrix(std::string filepath)
{
    std::ifstream filestream(filepath.c_str());
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


/**
 * Saves the best known solution for the instance.
 * 
 * @param filepath The path to the file containing the best known solutions.
*/
void 
Instance::save_best_known_solution(std::string filepath)
{
    std::ifstream filestream(filepath);
    if (!filestream.is_open()) {
        std::cerr << "Error: could not open file " << filepath << std::endl;
        exit(1);
    }
    
    std::string line;
    while (std::getline(filestream, line)) {
        std::stringstream ss(line);
        std::string name;
        int best_known_solution;
        ss >> name >> best_known_solution;
        if (name == this->name_) {
            this->best_known_solution_ = best_known_solution;
            break;
        }
    }

    if (this->best_known_solution_ == 0) {
        std::cerr << "Error: could not find best known solution for instance " << this->name_ << std::endl;
        exit(1);
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
Instance::solution() const
{
    return this->solution_;
}

int
Instance::seed() const
{
    return this->seed_;
}

double
Instance::computation_time() const
{
    return this->computation_time_;
}

int
Instance::best_known_solution() const
{
    return this->best_known_solution_;
}

double
Instance::relative_percentage_deviation() const
{
    return this->relative_percentage_deviation_;
}

void
Instance::set_permutation(std::vector<int> permutation)
{
    this->permutation_ = permutation;
}


/**
 * Sets the solution for the instance.
 * Computes the relative percentage deviation.
 * 
 * @param solution The solution to set.
*/
void
Instance::set_solution(int solution)
{
    this->solution_ = solution;
    this->relative_percentage_deviation_ = 100 * (static_cast<double>(best_known_solution_ - solution_) / static_cast<double>(best_known_solution_));
}

void
Instance::set_computation_time(double computation_time)
{
    this->computation_time_ = computation_time;
}

/**
 * Permutes the rows of the matrix according to the permutation.
*/
void
Instance::permute_rows()
{
    for (int i = 0; i < size(); i++) {
            std::swap(matrix_[i], matrix_[permutation_[i]]);
    }
}

void
Instance::print()
{
    std::cerr << "- Instance - " << std::endl
              << "Name: " << this->name_ << std::endl
              << "Size: " << this->size_ << std::endl
              << "Seed: " << this->seed_ << std::endl
              << std::endl;
    std::cerr.flush();
}