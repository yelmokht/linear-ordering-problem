#ifndef _INSTANCE_H_
#define _INSTANCE_H_

#include <string>
#include <array>
#include <vector>

#define NUMBER_ALGORITHMS 14

class Instance 
{
    private:
        std::string name_;
        int size_ = 0;
        std::vector<std::vector<int>> matrix_;
        std::vector<int> permutation_;
        int score_ = 0;
        int seed_ = 0;
        std::array<float, NUMBER_ALGORITHMS> relative_percentage_deviations_;
        std::array<float, NUMBER_ALGORITHMS> computation_times_;
        float average_relative_percentage_deviation_;
        float sum_of_computation_time_;
        void check_file(std::string filepath);
        void save_matrix(std::string filepath);
    public:
        Instance();
        Instance(std::string filepath);
        std::string name() const;
        int size() const;
        std::vector<std::vector<int>> matrix() const;
        std::vector<int> permutation() const;
        int score() const;
        int seed() const;
        void set_permutation(std::vector<int> permutation);
        void permute_rows();
        void set_score(int score);
        std::array<float, NUMBER_ALGORITHMS> relative_percentage_deviations();
        std::array<float, NUMBER_ALGORITHMS> computation_times();
        float average_relative_percentage_deviation();
        float sum_of_computation_time();
        void print();
};

#endif
