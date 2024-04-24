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
    if (VERBOSE) {
        print();
    }

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

// void
// Instance::save_termination_criterion(std::string filepath_1, std::string filepath_2)
// {
//     auto average_computation_time_1;
//     auto average_computation_time_2;
//     std::ofstream filestream(filepath_1);
//     if (!filestream.is_open()) {
//         std::cerr << "Error: could not open file " << filepath_1 << std::endl;
//         exit(1);
//     }
//     auto average_computation_time_1 = (find instance name in col 1 then read col 5)
//     filestream.close();

//     filestream.open(filepath_2);
//     if (!filestream.is_open()) {
//         std::cerr << "Error: could not open file " << filepath_2 << std::endl;
//         exit(1);
//     }
//     auto average_computation_time_2 = (find instance name in col 1 then read col 5)
//     filestream.close();

//     this->termination_criterion = ((average_computation_time_1 + average_computation_time_2)/2)*100;
// }

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

// double
// Instance::termination_criterion() const
// {
//     return this->termination_criterion;
// }

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
	std::cout 	<< name()<< " "
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
    for (int i = 0; i < size(); i++) {
        for (int j = i + 1; j < size(); j++) {
            score += matrix_[solution.permutation()[i]][solution.permutation()[j]];
        }
    }
    return score;
}