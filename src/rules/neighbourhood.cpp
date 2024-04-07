#include <iostream>
#include <cassert>

#include "neighbourhood.hpp"
#include "pivoting.hpp"


/**
 * @brief Computes the cost of a permutation based on the given instance.
 * 
 * @param instance The instance of the linear ordering problem.
 * @param permutation The permutation to compute the cost for.
 * @return The cost of the permutation.
 */
int
compute_cost(Instance& instance, std::vector<int>& permutation)
{
    auto matrix = instance.matrix();
    int size = instance.size();
    int cost = 0;
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            cost += matrix[permutation[i]][permutation[j]];
        }
    }
    return cost;
}


/**
 * @brief Performs the transpose neighbourhood on the given instance using the specified pivoting rule.
 * 
 * @param pivoting_rule The pivoting rule to use.
 * @param instance The instance of the linear ordering problem.
 * @return The best solution found after performing the transpose operation.
 */
int
transpose(Pivoting pivoting_rule, Instance& instance) 
{
    auto permutation = instance.permutation();
    auto best_permutation = permutation;
    auto solution = compute_cost(instance, permutation);
    auto last_best_solution = solution;
    auto best_solution = solution;
    bool local_optimum = false;
    auto iteration = 1;

    while(!local_optimum && iteration <= MAX_ITERATIONS) {
        for (int i = 0; i + 1 < instance.size(); i++) {
            auto new_permutation = best_permutation;
            std::swap(new_permutation[i], new_permutation[i+1]);
            auto new_solution = compute_cost(instance, new_permutation);

            if (best_solution < new_solution) {
                best_permutation = new_permutation;
                best_solution = new_solution;
                local_optimum = false;
                if (improvement(pivoting_rule)) {
                    instance.set_permutation(best_permutation);
                    instance.set_solution(best_solution);
                    break;
                }
            }
        }
        local_optimum = (last_best_solution == best_solution);
        last_best_solution = best_solution;
        iteration++;
        std::cout << "Iteration: " << iteration << " Solution: " << best_solution << std::endl;
    }

    instance.set_permutation(best_permutation);
    instance.set_solution(best_solution);
    return best_solution;
}


/**
 * @brief Performs the exchange neighbourhood on the given instance using the specified pivoting rule.
 * 
 * @param pivoting_rule The pivoting rule to use.
 * @param instance The instance of the linear ordering problem.
 * @return The best solution found after performing the exchange operation.
 */
int
exchange(Pivoting pivoting_rule, Instance& instance)
{
    auto permutation = instance.permutation();
    auto best_permutation = permutation;
    auto solution = compute_cost(instance, permutation);
    auto last_best_solution = solution;
    auto best_solution = solution;
    bool local_optimum = false;
    auto iteration = 1;

    while (!local_optimum && iteration <= MAX_ITERATIONS) {
        for (int i = 0; i < instance.size(); i++) {
            for (int j = i+1; j < instance.size(); j++) {
                auto new_permutation = best_permutation;
                std::swap(new_permutation[i], new_permutation[j]);
                auto new_solution = compute_cost(instance, new_permutation);

                if (best_solution < new_solution) {
                    best_permutation = new_permutation;
                    best_solution = new_solution;

                    if (improvement(pivoting_rule)) {
                        instance.set_permutation(best_permutation);
                        instance.set_solution(best_solution);
                        return best_solution;
                    }
                }
            }
        }

        local_optimum = (last_best_solution == best_solution);
        last_best_solution = best_solution;
        iteration++;
    }
    
    instance.set_permutation(best_permutation);
    instance.set_solution(best_solution);
    return best_solution;
}


/**
 * @brief Performs the insert neighbourhood on the given instance using the specified pivoting rule.
 * 
 * @param pivoting_rule The pivoting rule to use.
 * @param instance The instance of the linear ordering problem.
 * @return The best solution found after performing the insert operation.
 */
int
insert(Pivoting pivoting_rule, Instance& instance)
{
    auto permutation = instance.permutation();
    auto best_permutation = permutation;
    auto solution = compute_cost(instance, permutation);
    auto last_best_solution = solution;
    auto best_solution = solution;
    bool local_optimum = false;
    auto iteration = 1;

    while (!local_optimum && iteration <= MAX_ITERATIONS) {
        for (int i = 0; i < instance.size(); i++) {
            for (int j = 0; j < instance.size(); j++) {
                auto new_permutation = best_permutation;
                if (i == j) {break;}
                
                int value = new_permutation[i];
                
                if (i < j) {
                    new_permutation.erase(new_permutation.begin() + i);
                    new_permutation.insert(new_permutation.begin() + j + 1, value);
                } else {
                    new_permutation.insert(new_permutation.begin() + j, value);
                    new_permutation.erase(new_permutation.begin() + i + 1);
                }
                auto new_solution = compute_cost(instance, new_permutation);

                if (best_solution < new_solution) {
                    best_permutation = new_permutation;
                    best_solution = new_solution;
                    if (improvement(pivoting_rule)) {
                        instance.set_permutation(best_permutation);
                        instance.set_solution(best_solution);
                        return best_solution;
                    }
                }
            }
        }
        local_optimum = (last_best_solution == best_solution);
        last_best_solution = best_solution;
        iteration++;
        std::cout << "Iteration: " << iteration << " Solution: " << best_solution << std::endl;
    }

    instance.set_permutation(best_permutation);
    instance.set_solution(best_solution);
    return best_solution;
}

/**
 * @brief Performs the transpose, exchange, and insert operations on the given instance using the specified pivoting rule.
 * 
 * @param pivoting_rule The pivoting rule to use.
 * @param instance The instance of the linear ordering problem.
 * @return The best solution found after performing the operations.
 */
int
transpose_exchange_insert(Pivoting pivoting_rule, Instance& instance)
{
    transpose(pivoting_rule, instance);
    exchange(pivoting_rule, instance);
    auto best_solution = insert(pivoting_rule, instance);
    return best_solution;
}

/**
 * @brief Performs the transpose, insert, and exchange operations on the given instance using the specified pivoting rule.
 * 
 * @param pivoting_rule The pivoting rule to use.
 * @param instance The instance of the linear ordering problem.
 * @return The best solution found after performing the operations.
 */
int
transpose_insert_exchange(Pivoting pivoting_rule, Instance& instance)
{
    transpose(pivoting_rule, instance);
    insert(pivoting_rule, instance);
    auto best_solution = exchange(pivoting_rule, instance);
    return best_solution;
}

/**
 * @brief Applies the specified neighbourhood rule to the given instance using the specified pivoting rule.
 * 
 * @param neighbourhood_rule The neighbourhood rule to apply.
 * @param pivoting_rule The pivoting rule to use.
 * @param instance The instance of the linear ordering problem.
*/
void
neighbourhood(Neighbourhood neighbourhood_rule, Pivoting pivoting_rule, Instance& instance)
{
    switch (neighbourhood_rule)
    {
        case TRANSPOSE:
            transpose(pivoting_rule, instance);
            break;
        case EXCHANGE:
            exchange(pivoting_rule, instance);
            break;
        case INSERT:
            insert(pivoting_rule, instance);
            break;
        case TRANSPOSE_EXCHANGE_INSERT:
            transpose_exchange_insert(pivoting_rule, instance);
            break;
        case TRANSPOSE_INSERT_EXCHANGE:
            transpose_insert_exchange(pivoting_rule, instance);
            break;
        default:
            assert(false);
            break;
    }
}