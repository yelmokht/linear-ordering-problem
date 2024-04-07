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
    experiment "--ii --random --transpose --first" ./statistics/experiments/ii_random_transpose_first.txt
    experiment "--ii --random --exchange --first" ./statistics/experiments/ii_random_exchange_first.txt
    experiment "--ii --random --insert --first" ./statistics/experiments/ii_random_insert_first.txt

    experiment "--ii --random --transpose --best " ./statistics/experiments/ii_random_transpose_best.txt
    experiment "--ii --random --exchange --best" ./statistics/experiments/ii_random_exchange_best.txt
    experiment "--ii --random --insert --best" ./statistics/experiments/ii_random_insert_best.txt

    experiment "--ii --cw --transpose  --first" ./statistics/experiments/ii_cw_transpose_first.txt
    experiment "--ii --cw --exchange --first" ./statistics/experiments/ii_cw_exchange_first.txt
    experiment "--ii --cw --insert --first" ./statistics/experiments/ii_cw_insert_first.txt

    experiment "--ii --cw --transpose --best" ./statistics/experiments/ii_cw_transpose_best.txt
    experiment "--ii --cw --exchange --best" ./statistics/experiments/ii_cw_exchange_best.txt
    experiment "--ii --cw --insert --best " ./statistics/experiments/ii_cw_insert_best.txt

    experiment "--vnd --cw --transpose-exchange-insert --first" ./statistics/experiments/vnd_cw_transpose-exchange-insert_first.txt
    experiment "--vnd --cw --transpose-insert-exchange --first " ./statistics/experiments/vnd_cw_transpose-insert-exchange_first.txt
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

# experiments
# reports
statistical_tests