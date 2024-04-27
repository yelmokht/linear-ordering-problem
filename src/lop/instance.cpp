#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <filesystem>

#include "instance.hpp"
#include "configuration.hpp"

Instance::Instance() 
{}

Instance::Instance(std::string filepath) 
{
    check_file(filepath);
    save_matrix(filepath);
    save_best_known_score(BEST_KNOWN_FILE_PATH);
}

Instance::~Instance() {}

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

    this->solution_ = Solution(size_);
    
    this->matrix_ = std::vector<std::vector<int>>(size_, std::vector<int>(size_));
    for (unsigned i = 0 ; i < size_ ; i++) {
        for (unsigned j = 0 ; j < size_; j++) {
            ss >> matrix_[i][j];
            seed_ += matrix_[i][j];
        }
    }
}

void 
Instance::save_best_known_score(std::string filepath)
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
        int best_known_score;
        ss >> name >> best_known_score;
        if (name == this->name_) {
            this->best_known_score_ = best_known_score;
            break;
        }
    }

    if (this->best_known_score_ == 0) {
        std::cerr << "Error: could not find best known solution for instance " << this->name_ << std::endl;
        exit(1);
    }
}

void
Instance::save_max_runtime()
{
    std::string filepath = MAX_RUNTIME_FILE_PATH;
    std::ifstream filestream(filepath);

    if (!filestream.is_open()) {
        std::cerr << "Error: could not open file " << filepath << std::endl;
        exit(1);
    }

    std::string line;
    while (std::getline(filestream, line)) {
        std::stringstream ss(line);
        std::string name;
        double max_runtime;
        ss >> name >> max_runtime;
        if (name == this->name_) {
            this->max_runtime_ = max_runtime;
            break;
        }
    }

    if (this->max_runtime_ == 0) {
        std::cerr << "Error: could not find max runtime for instance " << this->name_ << std::endl;
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

Solution
Instance::solution()
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
Instance::best_known_score() const
{
    return this->best_known_score_;
}

double
Instance::relative_percentage_deviation() const
{
    return this->relative_percentage_deviation_;
}

double
Instance::max_runtime() const
{
    return this->max_runtime_;
}

void
Instance::set_solution(Solution solution)
{
    this->solution_ = solution;
    this->relative_percentage_deviation_ = 100 * (static_cast<double>(best_known_score_ - solution_.score()) / static_cast<double>(best_known_score_));
}

void
Instance::set_computation_time(double computation_time)
{
    this->computation_time_ = computation_time;
}

void
Instance::print()
{
	std::cout 	<< name() << " "
				<< solution().score() << " "
				<< best_known_score() << " "
				<< relative_percentage_deviation() << " "
				<< computation_time()
				<< std::endl;
}

int
Instance::evaluate(Solution& solution)
{
    int score = 0;
    auto permutation = solution.permutation();
    for (int i = 0; i < size(); i++) {
        for (int j = i + 1; j < size(); j++) {
            score += matrix_[permutation[i]][permutation[j]];
        }
    }
    return score;
}

void
Instance::permute(Solution& solution)
{
    auto permutation = solution.permutation();
    auto new_matrix = std::vector<std::vector<int>>(size_, std::vector<int>(size_));
    for (int i = 0; i < size(); i++) {
        for (int j = 0; j < size(); j++) {
            new_matrix[i][j] = matrix_[permutation[i]][permutation[j]];
        }
    }
    matrix_ = new_matrix;
}