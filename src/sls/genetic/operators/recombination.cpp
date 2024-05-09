#include <cassert>
#include <iostream>

#include "recombination.hpp"
#include "crossover.hpp"


/**
 * @brief Applies the cycle crossover operator to a population
 * 
 * @param instance The instance for which to apply the operator.
 * @param population The population to apply the operator to.
 * 
 * @return Population The recombined population.
 */
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

/**
 * @brief Applies the distance preserving crossover operator to a population
 * 
 * @param instance The instance for which to apply the operator.
 * @param population The population to apply the operator to.
 * 
 * @return Population The recombined population.
*/
Population dpx_recombination(Instance& instance, Population& population)
{
    //For future implementation
    return population;
}

/**
 * @brief Applies the order based crossover operator to a population
 * 
 * @param instance The instance for which to apply the operator.
 * @param population The population to apply the operator to.
 * 
 * @return Population The recombined population.
*/
Population ob_recombination(Instance& instance, Population& population)
{
    //For future implementation
    return population;
}

/**
 * @brief Applies the order crossover operator to a population
 * 
 * @param instance The instance for which to apply the operator.
 * @param population The population to apply the operator to.
 * 
 * @return Population The recombined population.
*/
Population op_recombination(Instance& instance, Population& population)
{
    //For future implementation
    return population;
}

/**
 * @brief Applies the ordered crossover operator to a population
 * 
 * @param instance The instance for which to apply the operator.
 * @param population The population to apply the operator to.
 * 
 * @return Population The recombined population.
*/
Population ox_recombination(Instance& instance, Population& population)
{
    //For future implementation
    return population;
}

/**
 * @brief Applies the partially matched crossover operator to a population
 * 
 * @param instance The instance for which to apply the operator.
 * @param population The population to apply the operator to.
 * 
 * @return Population The recombined population.
*/
Population pmx_recombination(Instance& instance, Population& population)
{
    //For future implementation
    return population;
}

/**
 * @brief Applies the position based crossover operator to a population
 * 
 * @param instance The instance for which to apply the operator.
 * @param population The population to apply the operator to.
 * 
 * @return Population The recombined population.
*/
Population po_recombination(Instance& instance, Population& population)
{
    //For future implementation
    return population;
}

/**
 * @brief Applies the rank based crossover operator to a population
 * 
 * @param instance The instance for which to apply the operator.
 * @param population The population to apply the operator to.
 * 
 * @return Population The recombined population.
*/
Population rank_recombination(Instance& instance, Population& population)
{
    //For future implementation
    return population;
}

/**
 * @brief Applies the recombination operator to a population
 * 
 * @param recombination_rule The recombination operator to apply.
 * @param instance The instance for which to apply the operator.
 * @param population The population to apply the operator to.
 * 
 * @return Population The recombined population.
 */
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
