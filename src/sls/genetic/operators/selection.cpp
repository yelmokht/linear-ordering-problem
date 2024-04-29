#include <cassert>
#include <algorithm>
#include <numeric>
#include <vector>

#include "selection.hpp"

Population rank_selection(Instance& instance, Population& current_population, Population& recombined_population, Population& mutated_population) {
    int population_size = current_population.size();
    Population ranked_population(population_size);
    std::vector<Solution> ranked_solutions(population_size);

    std::vector<Solution> all_solutions(current_population.size() + recombined_population.size() + mutated_population.size());
    std::copy(current_population.solutions().begin(), current_population.solutions().end(), all_solutions.begin());
    std::copy(recombined_population.solutions().begin(), recombined_population.solutions().end(), all_solutions.begin() + current_population.size());
    std::copy(mutated_population.solutions().begin(), mutated_population.solutions().end(), all_solutions.begin() + current_population.size() + recombined_population.size());

    stable_sort(all_solutions.begin(), all_solutions.end(), [](Solution a, Solution b) {return a.score() > b.score();});
    ranked_solutions.assign(all_solutions.begin(), all_solutions.begin() + population_size);
    ranked_population.set_solutions(ranked_solutions);

    return ranked_population;
}


Population roulette_selection(Instance& instance, Population& current_population, Population& recombined_population, Population& mutated_population) {
    //Future implementation
    return current_population;
}

Population tournament_selection(Instance& instance, Population& current_population, Population& recombined_population, Population& mutated_population) {
    //Future implementation
    return current_population;
}

Population uniform_selection(Instance& instance, Population& current_population, Population& recombined_population, Population& mutated_population) {
    //Future implementation
    return current_population;
}

Population selection(Selection selection_rule, Instance& instance, Population& current_population, Population& recombined_population, Population& mutated_population) {
    switch (selection_rule) {
        case Selection::RANK:
            return rank_selection(instance, current_population, recombined_population, mutated_population);
        case Selection::ROULETTE:
            return roulette_selection(instance, current_population, recombined_population, mutated_population);
        case Selection::TOURNAMENT:
            return tournament_selection(instance, current_population, recombined_population, mutated_population);
        case Selection::UNIFORM:
            return uniform_selection(instance, current_population, recombined_population, mutated_population);
        default:
            assert(false);
    }
}
