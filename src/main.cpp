#include <iostream>
#include <chrono>

#include "configuration.hpp"
#include "./rules/algorithm.hpp"


/*
Solves the LOP using the given configuration.
*/
void solve_lop(Configuration& configuration)
{
	// Start the timer
	auto start = std::chrono::high_resolution_clock::now();

	if (VERBOSE) 
	{
		std::cerr << "- Solving LOP -" << std::endl;
		std::cerr.flush();
	}

	// Get the rules from the configuration
	auto algorithm_rule = configuration.algorithm();
	auto initial_solution_rule = configuration.initial_solution();
	auto neighbourhood_rule = configuration.neighbourhood();
	auto pivoting_rule = configuration.pivoting();
	auto instance = configuration.instance();

	// Use the rules to solve the LOP
	algorithm(algorithm_rule, initial_solution_rule, neighbourhood_rule, pivoting_rule, instance);

	// Stop the timer
	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::duration<double>>(stop - start);
	instance.set_computation_time(duration.count());

	if (VERBOSE) 
	{
		std::cerr << std::endl << "- Results -" << std::endl;
		std::cerr << "Solution: " << instance.solution() << std::endl;
		std::cerr << "Execution time: " << duration.count() << "s" << std::endl;
		std::cerr.flush();
	} else {
		std::cout 	<< instance.name()<< " "
					<< instance.solution() << " "
					<< instance.best_known_solution() << " "
					<< instance.relative_percentage_deviation() << " "
					<< instance.computation_time()
					<< std::endl;
		std::cout.flush();
	}

}

int
main(int argc, char *argv[])
{
	// Parse command line arguments and make a configuration object
	auto configuration = Configuration(argc, argv);

	// Solve the LOP using the configuration
	solve_lop(configuration);

	return EXIT_SUCCESS;
}