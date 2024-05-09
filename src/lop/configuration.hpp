#ifndef CONFIGURATION_HPP
#define CONFIGURATION_HPP

#include <string>

#include "instance.hpp"

#define termination "./statistics/vnd_average.txt"

enum class Algorithm {
    UNDEFINED = -1,
    II,
    VND,
    ILS,
    MA
};

enum class InitialSolution {
    UNDEFINED = -1,
    RANDOM_SEED,
    CW,
    BI,
    RANDOM
};

enum class Neighbourhood {
    UNDEFINED = -1,
    TRANSPOSE,
    EXCHANGE,
    INSERT,
    TRANSPOSE_EXCHANGE_INSERT,
    TRANSPOSE_INSERT_EXCHANGE
};

enum class Pivoting {
    UNDEFINED = -1,
    FIRST,
    BEST
};

enum class LocalSearch {
    UNDEFINED = -1,
    KLE,
    KLI,
    LOCAL_ENUM,
    EXCHANGE,
    INSERT,
    OPT2,
    OPT3,
};

enum class Perturbation {
    UNDEFINED = -1,
    EXCHANGE,
    RANDOM_EXCHANGE
};

enum class Recombination {
    UNDEFINED = -1,
    CX,
    DPX,
    OB,
    OP,
    OX,
    PMX,
    PO,
    RANK
};

enum class Mutation {
    UNDEFINED = -1,
    EXCHANGE,
    INSERT,
    INVERSION,
    SCRAMBLE,
    SWAP
};

enum class Selection {
    UNDEFINED = -1,
    RANK,
    ROULETTE,
    TOURNAMENT,
    UNIFORM
};



const std::string algorithm_map[4] = {"iterative improvement", "variable neighbourhood descent", "iterated local search", "memetic algorithm"};
const std::string initial_solution_map[4] = {"random seed", "chenery-watanabe", "best insertion", "random"};
const std::string neighbourhood_map[5] = {"transpose", "exchange", "insert", "transpose, exchange, insert", "transpose, insert, exchange"};
const std::string pivoting_map[2] = {"first", "best"};
const std::string local_search_map[1] = {"insert"};
const std::string perturbation_map[1] = {"exchange"};
const std::string recombination_map[8] = {"cycle crossover", "distribution-based partition crossover", "order based crossover", "one point crossover", "order crossover", "partially mapped crossover", "position crossover", "rank crossover"};
const std::string mutation_map[5] = {"exchange", "insert", "inversion", "scramble", "swap"};
const std::string selection_map[4] = {"rank", "roulette", "tournament", "uniform"};

const std::string algorithm_map_short[4] = {"ii", "vnd", "ils", "ma"};
const std::string initial_solution_map_short[4] = {"rs", "cw", "bi", "r"};
const std::string neighbourhood_map_short[5] = {"transpose", "exchange", "insert", "transpose-exchange-insert", "transpose-insert-exchange"};
const std::string pivoting_map_short[2] = {"first", "best"};
const std::string local_search_map_short[1] = {"insert"};
const std::string perturbation_map_short[1] = {"exchange"};
const std::string recombination_map_short[8] = {"cx", "dpx", "ob", "op", "ox", "pmx", "po", "rank"};
const std::string mutation_map_short[5] = {"exchange", "insert", "inversion", "scramble", "swap"};
const std::string selection_map_short[4] = {"rank", "roulette", "tournament", "uniform"};

class Configuration {
    private:
        Algorithm a = Algorithm::UNDEFINED;
        InitialSolution i = InitialSolution::UNDEFINED;
        Neighbourhood n = Neighbourhood::UNDEFINED;
        Pivoting p = Pivoting::UNDEFINED;
        LocalSearch l = LocalSearch::UNDEFINED;
        Perturbation pb = Perturbation::UNDEFINED;
        Recombination r = Recombination::UNDEFINED;
        Mutation m = Mutation::UNDEFINED;
        Selection s = Selection::UNDEFINED;
        Instance instance_;
        
    public:
        Configuration(int argc, char *argv[]);
        Algorithm algorithm() const;
        InitialSolution initial_solution() const;
        Neighbourhood neighbourhood() const;
        Pivoting pivoting() const;
        LocalSearch local_search() const;
        Perturbation perturbation() const;
        Recombination recombination() const;
        Mutation mutation() const;
        Selection selection() const;
        Instance instance();
        void parse_args(int argc, char *argv[]);
        void parse_algorithm_option(std::string option);
        void parse_initial_solution_option(std::string option);
        void parse_neighbourhood_option(std::string option);
        void parse_pivoting_option(std::string option);
        void parse_local_search_option(std::string option);
        void parse_perturbation_option(std::string option);
        void parse_recombination_option(std::string option);
        void parse_mutation_option(std::string option);
        void parse_selection_option(std::string option);
        void help(int exit_code);
        void print() const;
};

#endif