#include <iostream>
#include <chrono>

#include "./lop/configuration.hpp"
#include "./sls/sls_factory.hpp"

void solve_lop(Configuration& configuration)
{
	// Start the timer
	auto start = std::chrono::high_resolution_clock::now();

	if (VERBOSE) 
	{
		std::cerr << "- Solving LOP -" << std::endl;
		std::cerr.flush();
	}

	auto algorithm_rule = configuration.algorithm();
	auto initial_solution_rule = configuration.initial_solution();
	auto neighbourhood_rule = configuration.neighbourhood();
	auto pivoting_rule = configuration.pivoting();
	auto instance = configuration.instance();

	sls_algorithm(algorithm_rule, initial_solution_rule, neighbourhood_rule, pivoting_rule, instance);

	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::duration<double>>(stop - start);
	instance.set_computation_time(duration.count());

	if (VERBOSE) 
	{
		std::cerr << std::endl << "- Results -" << std::endl;
		std::cerr << "Solution: " << instance.solution().score() << std::endl;
		std::cerr << "Execution time: " << duration.count() << "s" << std::endl;
		std::cerr.flush();
	} else {
		std::cout 	<< instance.name()<< " "
					<< instance.solution().score() << " "
					<< instance.best_known_score() << " "
					<< instance.relative_percentage_deviation() << " "
					<< instance.computation_time()
					<< std::endl;
		std::cout.flush();
	}

}

int
main(int argc, char *argv[])
{
	Configuration configuration = Configuration(argc, argv);
	solve_lop(configuration);
	return EXIT_SUCCESS;
}