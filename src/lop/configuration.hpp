#ifndef CONFIGURATION_HPP
#define CONFIGURATION_HPP

#include <string>

#include "instance.hpp"

#define VERBOSE false

// You can add more algorithms, initial solutions, neighbourhoods, and pivoting rules here.
typedef enum Algorithm {
    II,
    VND,
    ILS,
    MA
} Algorithm;

typedef enum InitialSolution {
    RANDOM,
    CW,
    BI
} IntialSolution;

typedef enum Neighbourhood {
    TRANSPOSE,
    EXCHANGE,
    INSERT,
    TRANSPOSE_EXCHANGE_INSERT,
    TRANSPOSE_INSERT_EXCHANGE
} Neighbourhood;

typedef enum Pivoting {
    FIRST,
    BEST
} Pivoting;


const std::string algorithm_map[4] = {"iterative improvement", "variable neighbourhood descent", "iterated local search", "memetic algorithm"};
const std::string initial_solution_map[3] = {"random", "chenery-watanabe", "best insertion"};
const std::string neighbourhood_map[5] = {"transpose", "exchange", "insert", "transpose, exchange, insert", "transpose, insert, exchange"};
const std::string pivoting_map[2] = {"first", "best"};

const std::string algorithm_map_short[4] = {"ii", "vnd", "ils", "ma"};
const std::string initial_solution_map_short[3] = {"random", "cw", "bi"};
const std::string neighbourhood_map_short[5] = {"transpose", "exchange", "insert", "transpose-exchange-insert", "transpose-insert-exchange"};
const std::string pivoting_map_short[2] = {"first", "best"};

class Configuration {
    private:
        Algorithm a;
        IntialSolution i;
        Neighbourhood n;
        Pivoting p;
        Instance instance_;
        void help(int status);
        
    public:
        Configuration(int argc, char *argv[]);
        Algorithm algorithm() const;
        IntialSolution initial_solution() const;
        Neighbourhood neighbourhood() const;
        Pivoting pivoting() const;
        Instance instance();
        void parse_args(int argc, char *argv[]);
        void print() const;
};

#endif