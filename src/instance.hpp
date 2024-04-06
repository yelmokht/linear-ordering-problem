#ifndef _INSTANCE_H_
#define _INSTANCE_H_

#include <string>
#include <array>
#include <vector>

#define BEST_KNOWN_FILE_PATH "./best_known/best_known.txt"

class Instance 
{
    private:
        std::string name_;
        std::vector<std::vector<int>> matrix_;
        std::vector<int> permutation_;
        int size_ = 0;
        int seed_ = 0;
        int solution_ = 0;
        int best_known_solution_ = 0;
        double relative_percentage_deviation_ = 0.0;
        double computation_time_ = 0.0;
        void check_file(std::string filepath);
        void save_matrix(std::string filepath);
        void save_best_known_solution(std::string filepath);
    public:
        Instance();
        Instance(std::string filepath);
        std::string name() const;
        std::vector<std::vector<int>> matrix() const;
        std::vector<int> permutation() const;
        int size() const;
        int seed() const;
        int solution() const;
        int best_known_solution() const;
        double relative_percentage_deviation() const;
        double computation_time() const;
        void set_permutation(std::vector<int> permutation);
        void set_solution(int solution);
        void set_computation_time(double computation_time);
        void permute_rows();
        void print();
};

#endif
