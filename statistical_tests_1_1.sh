#!/bin/sh

# Rebuild stats for all algos in exercise 1.1


# random - first
./build_stats_algo.sh '--init-random --random-seed 666 --transpose --first' ../stats_1/stats-rand-transpose-first.txt

./build_stats_algo.sh '--init-random --random-seed 666 --exchange --first' ../stats_1/stats-rand-exchange-first.txt

./build_stats_algo.sh '--init-random --random-seed 666 --insert --first' ../stats_1/stats-rand-insert-first.txt


# srz - first
./build_stats_algo.sh '--init-srz --transpose --first' ../stats_1/stats-srz-transpose-first.txt

./build_stats_algo.sh '--init-srz --exchange --first' ../stats_1/stats-srz-exchange-first.txt

./build_stats_algo.sh '--init-srz --insert --first' ../stats_1/stats-srz-insert-first.txt



# random - best
./build_stats_algo.sh '--init-random --random-seed 666 --transpose --best' ../stats_1/stats-rand-transpose-best.txt

./build_stats_algo.sh '--init-random --random-seed 666 --exchange --best' ../stats_1/stats-rand-exchange-best.txt

./build_stats_algo.sh '--init-random --random-seed 666 --insert --best' ../stats_1/stats-rand-insert-best.txt


# srz - best
./build_stats_algo.sh '--init-srz --transpose --best' ../stats_1/stats-srz-transpose-best.txt

./build_stats_algo.sh '--init-srz --exchange --best' ../stats_1/stats-srz-exchange-best.txt

./build_stats_algo.sh '--init-srz --insert --best' ../stats_1/stats-srz-insert-best.txt
