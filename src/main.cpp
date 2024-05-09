#include <iostream>
#include <chrono>

#include "./lop/configuration.hpp"
#include "./sls/sls_factory.hpp"

/*
Solves the LOP using the given configuration.
*/
void solve_lop(Configuration& configuration)
{
	// Start the timer
	auto start = std::chrono::high_resolution_clock::now();
	auto instance = configuration.instance();

	// Use the configuration to solve the LOP
	sls_algorithm(configuration, instance);

	// Stop the timer
	auto stop = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::duration<double>>(stop - start);
	
	// Print the results
	instance.set_computation_time(duration.count());
	instance.print();
}

int
main(int argc, char *argv[])
{
	// Parse command line arguments and make a configuration object
	Configuration configuration = Configuration(argc, argv);

	// Solve the LOP using the configuration
	solve_lop(configuration);
	
	return EXIT_SUCCESS;
}