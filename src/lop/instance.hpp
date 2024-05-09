#ifndef INSTANCE_HPP
#define INSTANCE_HPP

#include <string>
#include <array>
#include <vector>

#include "solution.hpp"

#define BEST_KNOWN_FILE_PATH "./best_known/best_known.txt"
#define MAX_RUNTIME_FILE_PATH "./max_runtime/max_runtime.txt"

class Instance 
{
    private:
        std::string name_;
        std::vector<std::vector<int>> matrix_;
        Solution solution_;
        int size_ = 0;
        int seed_ = 0;
        int best_known_score_ = 0;
        double relative_percentage_deviation_ = 0.0;
        double computation_time_ = 0.0;
        double max_runtime_ = 0.0;
        void check_file(std::string filepath);
        void save_matrix(std::string filepath);
        void save_best_known_score(std::string filepath);

    public:
        Instance();
        Instance(std::string filepath);
        ~Instance();
        std::string name() const;
        std::vector<std::vector<int>> matrix() const;
        Solution solution();
        int size() const;
        int seed() const;
        int best_known_score() const;
        double relative_percentage_deviation() const;
        double computation_time() const;
        double max_runtime() const;
        void set_solution(Solution solution);
        void set_computation_time(double computation_time);
        int evaluate(Solution& solution);
        void save_max_runtime();
        void print();
};

#endif
