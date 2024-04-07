#include <iostream>
#include <cassert>

#include "pivoting.hpp"

/**
 * Use the first improvement strategy.
 * It is always true so the first better solution that is evaluated is returned.
 * @return Always returns true.
*/
bool
first_improvement()
{
    return true;
}


/**
 * Use the best improvement strategy.
 * It is always false so all solutions are evaluated.
 * @return Always returns false.
 */
bool
best_improvement() 
{
    return false;
}


/**
 * Applies the specified pivoting rule.
 * 
 * @param pivoting_rule The pivoting rule to apply.
 * @return True for first improvement, false for best improvement
 */
bool
improvement(Pivoting pivoting_rule)
{
    switch (pivoting_rule)
    {
    case FIRST:
        return first_improvement(); 
        break;
    case BEST:
        return best_improvement();
        break;
    default:
        assert(false);
        break;
    }
}