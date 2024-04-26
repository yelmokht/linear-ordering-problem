#include <iostream>
#include <chrono>

#include "./lop/configuration.hpp"
#include "./sls/sls_factory.hpp"

void solve_lop(Configuration& configuration)
{
	
	auto start = std::chrono::high_resolution_clock::now();
	auto instance = configuration.instance();

	sls_algorithm(configuration, instance);

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