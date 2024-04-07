# Linear ordering problem
Implemention of iterative improvement algorithms for the linear ordering problem (LOP) for the course Heuristic Optimization (INFO-H413)

## Compilation

~~~
> make lop vnd
~~~

## Run on one instance

### II

~~~
Usage:./lop -i <initialization_rule (cw|random)>
	        -p <pivoting_rule (first|best)>
	        -n <neighbourhood (transpose|exchange|insert)>
	        -f <instance_file>

> ./lop -i cw -p first -n transpose -f ../instances/N-be75eec_250
~~~

### VND

~~~
Usage:./vnd -n <neighbourhood (tei|tie)>
            -f <instance_file>

> ./vnd -n tei -f ../instances/N-be75eec_250
~~~

# Scripts

## Generate experiments

~~~
# Execute all the experiments sequentially (will take a lot of time)
> ./generate_experiments.lua

OR

# Execute one type of experiment on all instances
> ./generate_experiments_one.lua lop <random|cw> <first|best>
                                     <transpose|exchange|insert>
> ./generate_experiments_one.lua vnd <tei|tie>

OR

# Execute all the experiments in parallel.
# Comment lines inside the script in order to execute k experiments where k is
# the number of threads your processor can run.
> ./generate_experiments.sh
~~~

## Generate averages

~~~
# Generate averages from the previous experiments.
# Requirement: the previous experiments must be placed in the experiments
# directory at the root of the project.
> ./compute_averages.lua
~~~

## Execute statistical hypothesis tests

~~~
# Execute statistical hypothesis tests on the previous experiments.
# Requirement: the previous experiments must be placed in the experiments
# directory at the root of the project.
> ./statistical_hypothesis_tests.R
~~~