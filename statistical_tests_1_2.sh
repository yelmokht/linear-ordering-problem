#!/bin/sh

# Rebuild stats for all algos in exercise 1.2


# random - first
./build_stats_algo.sh '--init-random --random-seed 666 --vnd-transpose-exchange-insert --first' ../stats_2/stats-rand-vnd-transpose-exchange-insert-first.txt

./build_stats_algo.sh '--init-random --random-seed 666 --vnd-transpose-insert-exchange --first' ../stats_2/stats-rand-vnd-transpose-insert-exchange-first.txt


# srz - first
./build_stats_algo.sh '--init-srz --vnd-transpose-exchange-insert --first' ../stats_2/stats-srz-vnd-transpose-exchange-insert-first.txt

./build_stats_algo.sh '--init-srz --vnd-transpose-insert-exchange --first' ../stats_2/stats-srz-vnd-transpose-insert-exchange-first.txt
