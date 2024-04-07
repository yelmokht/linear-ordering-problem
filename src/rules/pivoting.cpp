#include <iostream>
#include <cassert>

#include "pivoting.hpp"

bool
first_improvement()
{
    return true;
}


bool
best_improvement() 
{
    return false;
}


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