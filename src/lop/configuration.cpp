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
    // print();
}

void
Configuration::help(int exit_code)
{
    std::cerr << "Usage: ./lop [options]" << std::endl
              << "Options:" << std::endl
              << "  -a, --algorithm [options]" << std::endl
              << "      - ii"   << std::endl
              << "      - vnd"  << std::endl
              << "      - ils"  << std::endl
              << "      - ma"   << std::endl
              << std::endl
              << "  -i, --initial-solution [options]" << std::endl
              << "      - random (only for ii, ils, ma)" << std::endl
              << "      - cw (only for ii, vnd)" << std::endl
              << "      - bi (only for ils, ma)" << std::endl
              << std::endl
              << "  -p, --pivoting [options]" << std::endl
              << "      - first (only for ii, vnd)" << std::endl
              << "      - best (only for ii)" << std::endl
              << std::endl
              << "  -n, --neighborhood [options]" << std::endl
              << "      - transpose (only for ii)" << std::endl
              << "      - exchange (only for ii)" << std::endl
              << "      - insert (only for ii)" << std::endl
              << "      - transpose-exchange-insert (only for vnd)" << std::endl
              << "      - transpose-insert-exchange (only for vnd)" << std::endl
              << std::endl
              << "  -ls, --local-search [options]" << std::endl
              << "      - insert (only for ils and ma)" << std::endl
              << std::endl
              << "  -pb, --perturbation [options]" << std::endl
              << "      - exchange (only for ils)" << std::endl
              << std::endl
              << "  -r, --recombination [options]" << std::endl
              << "      - cx (only for ma)" << std::endl
              << "      - dpx (only for ma)" << std::endl
              << "      - ob (only for ma)" << std::endl
              << "      - op (only for ma)" << std::endl
              << "      - ox (only for ma)" << std::endl
              << "      - pmx (only for ma)" << std::endl
              << "      - po (only for ma)" << std::endl
              << "      - rank (only for ma)" << std::endl
              << std::endl
              << "  -m, --mutation [options]" << std::endl
              << "      - exchange (only for ma)" << std::endl
              << "      - insert (only for ma)" << std::endl
              << "      - inversion (only for ma)" << std::endl
              << "      - scramble (only for ma)" << std::endl
              << "      - swap (only for ma)" << std::endl
              << std::endl
              << "  -s, --selection [options]" << std::endl
              << "      - rank (only for ma)" << std::endl
              << "      - roulette (only for ma)" << std::endl
              << "      - tournament (only for ma)" << std::endl
              << "      - uniform (only for ma)" << std::endl
              << std::endl
              << "  -f, --file [instance file]" << std::endl
              << std::endl
              << "  --help [Display this help message]" << std::endl;
    exit(exit_code);
}

void Configuration::parse_args(int argc, char* argv[]) {
    if (argc < 7 || std::string(argv[1]) == "--help") {
        help(0);
    }

    int argIndex = 1;

    while (argIndex < argc) {
        std::string option(argv[argIndex]);

        if (option == "-a" || option == "--algorithm") {
            parse_algorithm_option(argv[argIndex + 1]);
            argIndex += 2;
        } else if (option == "-i" || option == "--initial-solution") {
            parse_initial_solution_option(argv[argIndex + 1]);
            argIndex += 2;
        } else if (option == "-p" || option == "--pivoting") {
            parse_pivoting_option(argv[argIndex + 1]);
            argIndex += 2;
        } else if (option == "-n" || option == "--neighborhood") {
            parse_neighbourhood_option(argv[argIndex + 1]);
            argIndex += 2;
        } else if (option == "-ls" || option == "--local-search") {
            parse_local_search_option(argv[argIndex + 1]);
            argIndex += 2;
        } else if (option == "-pb" || option == "--perturbation") {
            parse_perturbation_option(argv[argIndex + 1]);
            argIndex += 2;
        } else if (option == "-r" || option == "--recombination") {
            parse_recombination_option(argv[argIndex + 1]);
            argIndex += 2;
        } else if (option == "-m" || option == "--mutation") {
            parse_mutation_option(argv[argIndex + 1]);
            argIndex += 2;
        } else if (option == "-s" || option == "--selection") {
            parse_selection_option(argv[argIndex + 1]);
            argIndex += 2;
        } else if (option == "-f" || option == "--file") {
            if (argIndex + 1 < argc) {
                this->instance_ = Instance(std::string(argv[argIndex + 1]));
                argIndex += 2;
            } else {
                help(1);
            }
        } else {
            help(1);
        }
    }
}

void Configuration::parse_algorithm_option(std::string option) {
    if (option == "ii") {
        this->a = Algorithm::II;
    } else if (option == "vnd") {
        this->a = Algorithm::VND;
    } else if (option == "ils") {
        this->a = Algorithm::ILS;
    } else if (option == "ma") {
        this->a = Algorithm::MA;
    } else {
        help(1);
    }
}

void Configuration::parse_initial_solution_option(std::string option) {
    if (option == "random_seed" && (this->a == Algorithm::II)) {
        this->i = InitialSolution::RANDOM_SEED;
    } else if (option == "cw" && (this->a == Algorithm::II || this->a == Algorithm::VND)) {
        this->i = InitialSolution::CW;
    } else if (option == "bi" && (this->a == Algorithm::ILS || this->a == Algorithm::MA)) {
        this->i = InitialSolution::BI;
    } else if (option == "random" && (this->a == Algorithm::II || this->a == Algorithm::ILS || this->a == Algorithm::MA)) {
        this->i = InitialSolution::RANDOM;
    } else {
        help(1);
    }
}

void Configuration::parse_pivoting_option(std::string option) {
    if (option == "first" && (this->a == Algorithm::II || this->a == Algorithm::VND)) {
        this->p = Pivoting::FIRST;
    } else if (option == "best" && this->a == Algorithm::II) {
        this->p = Pivoting::BEST;
    } else {
        help(1);
    }
}

void Configuration::parse_neighbourhood_option(std::string option) {
    if (option == "transpose" && this->a == Algorithm::II) {
        this->n = Neighbourhood::TRANSPOSE;
    } else if (option == "exchange" && this->a == Algorithm::II) {
        this->n = Neighbourhood::EXCHANGE;
    } else if (option == "insert" && this->a == Algorithm::II) {
        this->n = Neighbourhood::INSERT;
    } else if (option == "transpose-exchange-insert" && this->a == Algorithm::VND) {
        this->n = Neighbourhood::TRANSPOSE_EXCHANGE_INSERT;
    } else if (option == "transpose-insert-exchange" && this->a == Algorithm::VND) {
        this->n = Neighbourhood::TRANSPOSE_INSERT_EXCHANGE;
    } else {
        help(1);
    }
}

void Configuration::parse_local_search_option(std::string option) {
    if (option == "insert" && (this->a == Algorithm::ILS || this->a == Algorithm::MA)) {
        this->l = LocalSearch::INSERT;
    } else {
        help(1);
    }
}

void Configuration::parse_perturbation_option(std::string option) {
    if (option == "exchange" && this->a == Algorithm::ILS) {
        this->pb = Perturbation::EXCHANGE;
    } else {
        help(1);
    }
}

void Configuration::parse_recombination_option(std::string option) {
    if (option == "cx" && this->a == Algorithm::MA) {
        this->r = Recombination::CX;
    } else {
        help(1);
    }
}

void Configuration::parse_mutation_option(std::string option) {
    if (option == "exchange" && this->a == Algorithm::MA) {
        this->m = Mutation::EXCHANGE;
    } else {
        help(1);
    }
}

void Configuration::parse_selection_option(std::string option) {
    if (option == "rank" && this->a == Algorithm::MA) {
        this->s = Selection::RANK;
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


Neighbourhood 
Configuration::neighbourhood() const 
{
    return this->n;
}

Pivoting 
Configuration::pivoting() const 
{
    return this->p;
}

LocalSearch
Configuration::local_search() const 
{
    return this->l;
}

Perturbation
Configuration::perturbation() const 
{
    return this->pb;
}

Recombination
Configuration::recombination() const 
{
    return this->r;
}

Mutation
Configuration::mutation() const 
{
    return this->m;
}

Selection
Configuration::selection() const 
{
    return this->s;
}

Instance
Configuration::instance() 
{
    return this->instance_;
}

void Configuration::print() const 
{
    std::cerr << "- Configuration -" << std::endl;
    std::cerr << "Algorithm: " << algorithm_map[static_cast<int>(a)] << std::endl;
    if (i != InitialSolution::UNDEFINED) {
        std::cerr << "Initial solution rule: " << initial_solution_map[static_cast<int>(i)] << std::endl;
    }
    if (n != Neighbourhood::UNDEFINED) {
        std::cerr << "Neighborhood rule: " << neighbourhood_map[static_cast<int>(n)] << std::endl;
    }
    if (p != Pivoting::UNDEFINED) {
        std::cerr << "Pivoting rule: " << pivoting_map[static_cast<int>(p)] << std::endl;
    }
    if (l != LocalSearch::UNDEFINED) {
        std::cerr << "Local search rule: " << local_search_map[static_cast<int>(l)] << std::endl;
    }
    if (pb != Perturbation::UNDEFINED) {
        std::cerr << "Perturbation rule: " << perturbation_map[static_cast<int>(pb)] << std::endl;
    }
    if (r != Recombination::UNDEFINED) {
        std::cerr << "Recombination rule: " << recombination_map[static_cast<int>(r)] << std::endl;
    }
    if (m != Mutation::UNDEFINED) {
        std::cerr << "Mutation rule: " << mutation_map[static_cast<int>(m)] << std::endl;
    }
    if (s != Selection::UNDEFINED) {
        std::cerr << "Selection rule: " << selection_map[static_cast<int>(s)] << std::endl;
    }
    std::cerr << "Instance: " << instance_.name() << std::endl;
    std::cerr.flush();
}
