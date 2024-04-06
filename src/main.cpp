#include <iostream>
#include <chrono>

#include "configuration.hpp"
#include "algorithm.hpp"

void solve_lop(Configuration configuration)
{
	auto start = std::chrono::high_resolution_clock::now();

	if (VERBOSE) 
	{
	std::cerr << "- Solving LOP -" << std::endl;
	std::cerr.flush();
	}

	auto algorithm_rule = configuration.algorithm();
	auto initial_solution_rule = configuration.initial_solution();
	auto pivoting_rule = configuration.pivoting();
	auto neighbourhood_rule = configuration.neighbourhood();
	auto instance = configuration.instance();

	algorithm(algorithm_rule, initial_solution_rule, pivoting_rule, neighbourhood_rule, instance);

	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::duration<double>>(stop - start);

	if (VERBOSE) 
	{
	std::cerr << std::endl << "- Results -" << std::endl;
	std::cerr << "Score: " << instance.score() << std::endl;
	std::cerr << "Execution time: " << duration.count() << "s" << std::endl;
	std::cerr.flush();
	} else {
	std::cout << instance.name() << std: << instance.score() << "\t" << duration.count() << std::endl;
	std::cout.flush();
	}

}

int
main(int argc, char *argv[])
{
	auto configuration = Configuration(argc, argv);
	solve_lop(configuration);
	return EXIT_SUCCESS;
}