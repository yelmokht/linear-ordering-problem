#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <fstream>
#include <sstream>
#include <filesystem>

#include "configuration.hpp"

Configuration::Configuration(int argc, char *argv[]) 
{
    parse_args(argc, argv);
    if (VERBOSE) {
        print();
    }
}

void
Configuration::help(int status) 
{
  std::cerr << "Usage: ./lop [algorithms or help] [initial_solutions] [improvements] [neighbourhoods] [-i <instance_file> | -f <instances_folder>]" << std::endl
            << std::endl
            << "Algorithms or help:" << std::endl
            << "  --ii" << std::endl
            << "  --vnd" << std::endl
            << "  --help" << std::endl
            << std::endl
            << "Initial solutions:" << std::endl
            << "  --random (only with --ii)" << std::endl
            << "  --cw" << std::endl
            << std::endl
            << "Improvements:" << std::endl
            << "  --first " << std::endl
            << "  --best (only with --ii)" << std::endl
            << std::endl
            << "Neighbourhoods:" << std::endl
            << "  --transpose (only with --ii)" << std::endl
            << "  --exchange (only with --ii)" << std::endl
            << "  --insert (only with --ii)" << std::endl
            << "  --transpose-exchange-insert (only with --vnd)" << std::endl
            << "  --transpose-insert-exchange (only with --vnd)" << std::endl
            << std::endl;
  exit(status);
}

void 
Configuration::parse_args(int argc, char* argv[])
{
    if (argc < 7 || std::string(argv[1]) == "--help") {
        help(0);
    }

    if (std::string(argv[1]) == "--ii") {
        this->a = II;
    } else if (std::string(argv[1]) == "--vnd") {
        this->a = VND;
    } else {
        help(1);
    }

    if (std::string(argv[2]) == "--random" && this->a == II) {
        this->i = RANDOM;
    } else if (std::string(argv[2]) == "--cw") {
        this->i = CW;
    } else {
        help(1);
    }

    if (std::string(argv[3]) == "--first") {
        this->p = FIRST;
    } else if (std::string(argv[3]) == "--best" && this->a == II) {
        this->p = BEST;
    } else {
        help(1);
    }

    if (std::string(argv[4]) == "--transpose" && this->a == II) {
        this->n = TRANSPOSE;
    } else if (std::string(argv[4]) == "--exchange" && this->a == II) {
        this->n = EXCHANGE;
    } else if (std::string(argv[4]) == "--insert" && this->a == II) {
        this->n = INSERT;
    } else if (std::string(argv[4]) == "--transpose-exchange-insert" && this->a == VND) {
        this->n = TRANSPOSE_EXCHANGE_INSERT;
    } else if (std::string(argv[4]) == "--transpose-insert-exchange" && this->a == VND) {
        this->n = TRANSPOSE_INSERT_EXCHANGE;
    } else {
        help(1);
    }

    if (std::string(argv[5]) == "-i") {
        this->instance_ = Instance(std::string(argv[6]));
    } else {
        help(1);
    }
}

Algorithm 
Configuration::algorithm() const 
{
    return this->a;
}

InitialSolution 
Configuration::initial_solution() const 
{
    return this->i;
}

Pivoting 
Configuration::pivoting() const 
{
    return this->p;
}

Neighbourhood 
Configuration::neighbourhood() const 
{
    return this->n;
}

Instance 
Configuration::instance() 
{
    return this->instance_;
}

void 
Configuration::print() const 
{
    std::cerr   << "- Configuration - " << std::endl
                << "Algorithm: " << algorithm_map[a] << std::endl
                << "Initial solution rule: " << initial_solution_map[i] << std::endl
                << "Pivoting rule: " << pivoting_map[p] << std::endl
                << "Neighborhood rule: " << neighbourhood_map[n] << std::endl
                << std::endl;
    std::cerr.flush();
}

