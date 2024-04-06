#ifndef CONFIGURATION_HPP
#define CONFIGURATION_HPP

#include <string>

#include "instance.hpp"

#define VERBOSE true

typedef enum Algorithm {
    II,
    VND
} Algorithm;

typedef enum InitialSolution {
    RANDOM,
    CW
} IntialSolution;

typedef enum Pivoting {
    FIRST,
    BEST
} Pivoting;

typedef enum Neighbourhood {
    TRANSPOSE,
    EXCHANGE,
    INSERT,
    TRANSPOSE_EXCHANGE_INSERT,
    TRANSPOSE_INSERT_EXCHANGE
} Neighbourhood;

const std::string algorithm_map[2] = {"iterative improvement", "variable neighbourhood descent"};
const std::string initial_solution_map[2] = {"random", "chenery-watanabe"};
const std::string pivoting_map[2] = {"first", "best"};
const std::string neighbourhood_map[5] = {"transpose", "exchange", "insert", "transpose, exchange, insert", "transpose, insert, exchange"};

const std::string algorithm_map_short[2] = {"ii", "vnd"};
const std::string initial_solution_map_short[2] = {"random", "cw"};
const std::string pivoting_map_short[2] = {"first", "best"};
const std::string neighbourhood_map_short[5] = {"transpose", "exchange", "insert", "transpose-exchange-insert", "transpose-insert-exchange"};

class Configuration {
    private:
        Algorithm a;
        IntialSolution i;
        Pivoting p;
        Neighbourhood n;
        Instance instance_;
        void help(int status);
        void parse_args(int argc, char *argv[]);
        
    public:
        Configuration(int argc, char *argv[]);
        Algorithm algorithm() const;
        IntialSolution initial_solution() const;
        Pivoting pivoting() const;
        Neighbourhood neighbourhood() const;
        Instance instance();
        void print() const;
        void save_statistics();
};

#endif