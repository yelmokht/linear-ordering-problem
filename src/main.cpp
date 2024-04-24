#include <iostream>
#include <chrono>

#include "./lop/configuration.hpp"
#include "./sls/sls_factory.hpp"

void solve_lop(Configuration& configuration)
{
	auto algorithm_rule = configuration.algorithm();
	auto initial_solution_rule = configuration.initial_solution();
	auto neighbourhood_rule = configuration.neighbourhood();
	auto pivoting_rule = configuration.pivoting();
	auto instance = configuration.instance();
	
	auto start = std::chrono::high_resolution_clock::now();

	sls_algorithm(algorithm_rule, initial_solution_rule, neighbourhood_rule, pivoting_rule, instance);

	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::duration<double>>(stop - start);
	
	instance.set_computation_time(duration.count());
	instance.print();
}

int
main(int argc, char *argv[])
{
	Configuration configuration = Configuration(argc, argv);
	solve_lop(configuration);
	return EXIT_SUCCESS;
}