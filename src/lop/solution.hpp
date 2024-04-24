#ifndef SOLUTION_HPP
#define SOLUTION_HPP

#include <vector>

class Solution
{
    private:
        int size_;
        std::vector<int> permutation_;
        int score_;
    public:
        Solution();
        Solution(int size);
        int size();
        std::vector<int> permutation() const;
        int score();
        void swap_permutation(int i, int j);
        void transpose_permutation(int i, int j);
        void exchange_permutation(int i, int j);
        void insert_permutation(int i, int j);
        void set_permutation(std::vector<int> permutation);
        void set_score(int score);
        bool operator==(const Solution& other) const;
        bool operator!=(const Solution& other) const;
};

#endif