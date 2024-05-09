#include <iostream>
#include <cassert>

#include "neighbourhood.hpp"
#include "pivoting.hpp"
#include "cost.hpp"

/**
 * @brief Checks if a transpose operation is valid.
 * 
 * @param i The first index of the transpose operation.
 * @param j The second index of the transpose operation.
 * 
 * @return bool True if the transpose operation is valid, false otherwise.
 */
bool
transpose_is_valid(unsigned i, unsigned j)
{
    return j == i + 1;
}

/**
 * @brief Checks if an exchange operation is valid.
 * 
 * @param i The first index of the exchange operation.
 * @param j The second index of the exchange operation.
 * 
 * @return bool True if the exchange operation is valid, false otherwise.
 */
bool
exchange_is_valid(unsigned i, unsigned j)
{
    return j > i;
}

/**
 * @brief Checks if an insert operation is valid.
 * 
 * @param i The first index of the insert operation.
 * @param j The second index of the insert operation.
 * 
 * @return bool True if the insert operation is valid, false otherwise.
 */
bool
insert_is_valid(unsigned i, unsigned j)
{
    return i != j;
}

/**
 * @brief Checks if a neighbourhood is valid for a given neighbourhood rule.
 * 
 * @param neighbourhood_rule The neighbourhood rule.
 * @param i The first index of the neighbourhood.
 * @param j The second index of the neighbourhood.
 * 
 * @return bool True if the neighbourhood is valid, false otherwise.
 */
bool
neighbourhood_is_valid(Neighbourhood neighbourhood_rule, unsigned i, unsigned j)
{
    switch (neighbourhood_rule)
    {
        case Neighbourhood::TRANSPOSE:
            return transpose_is_valid(i, j);
        case Neighbourhood::EXCHANGE:
            return exchange_is_valid(i, j);
        case Neighbourhood::INSERT:
            return insert_is_valid(i, j);
        default:
            assert(false);
    }
}

/**
 * @brief Generates a neighbourhood for a given neighbourhood rule.
 * 
 * @param neighbourhood_rule The neighbourhood rule.
 * @param size The size of the neighbourhood.
 * 
 * @return std::vector<std::pair<int, int>> The neighbourhood.
 */
std::vector<std::pair<int, int>>
generate_neighbourhood(Neighbourhood neighbourhood_rule, int size)
{
    std::vector<std::pair<int, int>> neighbourhood;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (neighbourhood_is_valid(neighbourhood_rule, i, j)) {
                neighbourhood.push_back({i, j});
            }
        }
    }

    return neighbourhood;
}

/**
 * Performs a transpose operation on a solution.
 * 
 * @param solution The solution to perform the transpose operation on.
 * @param i The first index of the transpose operation.
 * @param j The second index of the transpose operation.
 * 
 * @return Solution The solution after the transpose operation.
*/
Solution&
transpose(Solution& solution, unsigned i, unsigned j) 
{
    solution.transpose_permutation(i, i+1);
    return solution;
}

/**
 * Performs an exchange operation on a solution.
 * 
 * @param solution The solution to perform the exchange operation on.
 * @param i The first index of the exchange operation.
 * @param j The second index of the exchange operation.
 * 
 * @return Solution The solution after the exchange operation.
*/
Solution&
exchange(Solution& solution, unsigned i, unsigned j)
{
    solution.exchange_permutation(i, j);
    return solution;
}

/**
 * Performs an insert operation on a solution.
 * 
 * @param solution The solution to perform the insert operation on.
 * @param i The first index of the insert operation.
 * @param j The second index of the insert operation.
 * 
 * @return Solution The solution after the insert operation.
*/
Solution&
insert(Solution& solution, unsigned i, unsigned j)
{  
    solution.insert_permutation(i, j);
    return solution;
}

/**
 * @brief Applies a permutation to a solution.
 * 
 * @param neighbourhood_rule The neighbourhood rule.
 * @param solution The solution to apply the permutation to.
 * @param i The first index of the permutation.
 * @param j The second index of the permutation.
 * 
 * @return Solution The solution after a permutation.
 */
Solution&
apply_permutation(Neighbourhood neighbourhood_rule, Solution& solution, unsigned i, unsigned j)
{
    switch (neighbourhood_rule)
    {
        case Neighbourhood::TRANSPOSE:
            return transpose(solution, i, j);
        case Neighbourhood::EXCHANGE:
            return exchange(solution, i, j);
        case Neighbourhood::INSERT:
            return insert(solution, i, j);
        default:
            assert(false);
    }
}