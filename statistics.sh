#!/bin/sh

function_name() {
    local options="$1"
    local output="$2"
    echo 'instance      cost      computation_time' > "$output"
    for file in ./instances/*
    do
        ./lop $options -i "$file" >> "$output"  # Modified this line
    done
}

# Call function_name for each combination of options and output files
# function_name "--ii --random --first --transpose" ./statistics/ii_random_first_transpose.txt
# function_name "--ii --random --first --exchange" ./statistics/ii_random_first_exchange.txt
# function_name "--ii --random --first --insert" ./statistics/ii_random_first_insert.txt

# function_name "--ii --random --best --transpose" ./statistics/ii_random_best_transpose.txt
# function_name "--ii --random --best --exchange" ./statistics/ii_random_best_exchange.txt
# function_name "--ii --random --best --insert" ./statistics/ii_random_best_insert.txt

function_name "--ii --cw --first --transpose" ./statistics/ii_cw_first_transpose.txt
function_name "--ii --cw --first --exchange" ./statistics/ii_cw_first_exchange.txt
function_name "--ii --cw --first --insert" ./statistics/ii_cw_first_insert.txt

function_name "--ii --cw --best --transpose" ./statistics/ii_cw_best_transpose.txt
function_name "--ii --cw --best --exchange" ./statistics/ii_cw_best_exchange.txt
function_name "--ii --cw --best --insert" ./statistics/ii_cw_best_insert.txt

# function_name "--vnd --cw --first --transpose-exchange-insert" ./statistics/vnd_cw_first_transpose-exchange-insert.txt
# function_name "--vnd --cw --first --transpose-insert-exchange" ./statistics/vnd_cw_first_transpose-insert-exchange.txt
make 