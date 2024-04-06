#!/bin/sh

experiment() {
    options="$1"
    output="$2"

    for file in ./instances/*
    do
        ./lop $options -i $file >> $output
    done
}

experiments() {
    experiment "--ii --random --first --transpose" ./statistics/experiments/ii_random_first_transpose.txt
    experiment "--ii --random --first --exchange" ./statistics/experiments/ii_random_first_exchange.txt
    experiment "--ii --random --first --insert" ./statistics/experiments/ii_random_first_insert.txt

    experiment "--ii --random --best --transpose" ./statistics/experiments/ii_random_best_transpose.txt
    experiment "--ii --random --best --exchange" ./statistics/experiments/ii_random_best_exchange.txt
    experiment "--ii --random --best --insert" ./statistics/experiments/ii_random_best_insert.txt

    experiment "--ii --cw --first --transpose" ./statistics/experiments/ii_cw_first_transpose.txt
    experiment "--ii --cw --first --exchange" ./statistics/experiments/ii_cw_first_exchange.txt
    experiment "--ii --cw --first --insert" ./statistics/experiments/ii_cw_first_insert.txt

    experiment "--ii --cw --best --transpose" ./statistics/experiments/ii_cw_best_transpose.txt
    experiment "--ii --cw --best --exchange" ./statistics/experiments/ii_cw_best_exchange.txt
    experiment "--ii --cw --best --insert" ./statistics/experiments/ii_cw_best_insert.txt

    experiment "--vnd --cw --first --transpose-exchange-insert" ./statistics/experiments/vnd_cw_first_transpose-exchange-insert.txt
    experiment "--vnd --cw --first --transpose-insert-exchange" ./statistics/experiments/vnd_cw_first_transpose-insert-exchange.txt
}

report() {
    input_file="$1"
    output_file="$2"

    filename=$(basename "$input_file" .txt)
    awk -v filename="$filename" '{sum1 += $4; sum2 += $5; count++} END {printf "%s %f %f\n", filename, (count > 0) ? sum1 / count : 0, sum2}' "$input_file" >> "$output_file"
}


reports() {
    for file in ./statistics/experiments/*.txt
    do
        report "$file" "./statistics/reports/report.txt"
    done

}

statistical_tests() {
    ./statistical_tests.r
}

experiments
reports
statistical_tests