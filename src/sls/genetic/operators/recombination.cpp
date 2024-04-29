#include <cassert>
#include <iostream>

#include "recombination.hpp"
#include "crossover.hpp"


Population cx_recombination(Instance& instance, Population& population)
{
    Population recombined_population(population.size());

    for (int i = 0; i < population.size(); i += 2) {
        if (i + 1 < population.size()) {
            Solution parent_1 = population.solution(i);
            Solution parent_2 = population.solution(i + 1);

            std::pair<Solution, Solution> offsprings = cx(instance, parent_1, parent_2);
            Solution offspring_1 = offsprings.first;
            Solution offspring_2 = offsprings.second;

            recombined_population.set_solution(i, offspring_1);
            recombined_population.set_solution(i + 1, offspring_2);
        }
        else {
            recombined_population.set_solution(i, population.solution(i));
        }
    }

    return recombined_population;
}

Population dpx_recombination(Instance& instance, Population& population)
{
    //For future implementation
    return population;
}

Population ob_recombination(Instance& instance, Population& population)
{
    //For future implementation
    return population;
}

Population op_recombination(Instance& instance, Population& population)
{
    //For future implementation
    return population;
}

Population ox_recombination(Instance& instance, Population& population)
{
    //For future implementation
    return population;
}

Population pmx_recombination(Instance& instance, Population& population)
{
    //For future implementation
    return population;
}

Population po_recombination(Instance& instance, Population& population)
{
    //For future implementation
    return population;
}

Population rank_recombination(Instance& instance, Population& population)
{
    //For future implementation
    return population;
}

Population recombination(Recombination recombination_rule, Instance& instance, Population& population)
{
    switch (recombination_rule) {
        case Recombination::CX:
            return cx_recombination(instance, population);
        case Recombination::DPX:
            return dpx_recombination(instance, population);
        case Recombination::OB:
            return ob_recombination(instance, population);
        case Recombination::OP:
            return op_recombination(instance, population);
        case Recombination::OX:
            return ox_recombination(instance, population);
        case Recombination::PMX:
            return pmx_recombination(instance, population);
        case Recombination::PO:
            return po_recombination(instance, population);
        case Recombination::RANK:
            return rank_recombination(instance, population);
        default:
            assert(false);
    }
}
