#include <cassert>
#include <algorithm>
#include <numeric>

#include "selection.hpp"

Population rank_selection(Instance& instance, Population& current_population, Population& recombined_population, Population& mutated_population) {
    int population_size = current_population.size();
    Population ranked_population(population_size);

    // Evaluate the scores of solutions in all populations
    for (int i = 0; i < population_size; i++) {
        current_population.solution(i).set_score(instance.evaluate(current_population.solution(i)));
        recombined_population.solution(i).set_score(instance.evaluate(recombined_population.solution(i)));
        mutated_population.solution(i).set_score(instance.evaluate(mutated_population.solution(i)));
    }

    // Combine all solutions
    std::vector<int> indices(population_size * 3);
    std::iota(indices.begin(), indices.end(), 0);

    // Sort indices based on scores
    std::sort(indices.begin(), indices.end(), [&](int a, int b) {
        return current_population.solution(a % population_size).score() < current_population.solution(b % population_size).score();
    });

    // Construct the ranked population using the sorted indices
    for (int i = 0; i < population_size; i++) {
        ranked_population.solution(i) = current_population.solution(indices[i]);
    }

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
