#include "solution.hpp"
#include <iostream>

Solution::Solution() {}

Solution::Solution(int size)
{
    this->size_ = size;
    this->permutation_ = std::vector<int>(size);
    this->score_ = 0;
}

int
Solution::size()
{
    return this->size_;
}

std::vector<int>
Solution::permutation() const
{
    return this->permutation_;
}

int
Solution::score()
{
    return this->score_;
}

void
Solution::swap_permutation(int i, int j)
{
    std::swap(this->permutation_[i], this->permutation_[j]);
}

void
Solution::transpose_permutation(int i, int j)
{
    swap_permutation(i, j);
}

void
Solution::exchange_permutation(int i, int j)
{
    swap_permutation(i, j);
}

void
Solution::insert_permutation(int i, int j)
{
    int value = this->permutation_[i];
    this->permutation_.erase(this->permutation_.begin() + i);
    this->permutation_.insert(this->permutation_.begin() + j, value);
}

void
Solution::set_permutation(std::vector<int> permutation)
{
    this->permutation_ = permutation;
}

void
Solution::set_score(int score)
{
    this->score_ = score;
}

bool
Solution::operator==(const Solution& other) const
{
    return this->permutation_ == other.permutation();
}

bool
Solution::operator!=(const Solution& other) const
{
    return this->permutation_ != other.permutation();
}
