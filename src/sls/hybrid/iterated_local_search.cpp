#include "iterated_local_search.hpp"

IteratedLocalSearch::IteratedLocalSearch() 
{

}

void
IteratedLocalSearch::local_search(Pivoting pivoting_rule, Instance& instance, Solution& solution)
{
    // // Local search based on insertion
    // insert(pivoting_rule, instance);
}

// Perturbation based on exchange
void
IteratedLocalSearch::perturbation(Pivoting pivoting_rule, Instance& instance, Solution& solution)
{
    // exchange(pivoting_rule, instance)
}

// Run the iterated local search
void
IteratedLocalSearch::run(Pivoting pivoting_rule, Instance& instance)
{
    // auto terminal_criterion = instance.termination_criterion()
    // std::vector<Permutation> previous_permutations;
    // auto permutation = instance.solution(); //Generate initial solution
    // auto best_permutation = local_search(pivoting_rule, instance, permutation);
    // auto time = std::chrono::high_resolution_clock::now();
    // auto elapsed;
    // while (termination_criterion_is_not_satisfied(terminal_criterion, elapsed)) {
    //     auto new_permutation = perturbation(pivoting_rule, instance, best_permutation);
    //     new_permutation = local_search(pivoting_rule, instance, new_permutation);
    //     if (acceptance_criterion_is_satisfied(previous_permutations, best_permutation, new_permutation)) {
    //         best_permutation = new_permutation;
    //     }
    //     elapsed = std::chrono::high_resolution_clock::now() - time;
    // }

    // instance.set_solution(best_permutation);
}