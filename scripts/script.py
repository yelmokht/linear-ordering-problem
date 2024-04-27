#!/usr/bin/env python3

import os
import subprocess
import shlex

def experiment(options, output, output_file):
    options_list = shlex.split(options)
    for file in sorted(os.listdir("./instances")):
        command = ["./lop"] + options_list + ["-f", os.path.join("./instances", file)]
        subprocess.run(command, stdout=output_file, stderr=subprocess.PIPE)

def experiments():
    experiments_data = [
        ("-a ii -i random -p first -n transpose", "./statistics/experiments/ii_random_first_transpose.txt"),
        ("-a ii -i random -p first -n exchange", "./statistics/experiments/ii_random_first_exchange.txt"),
        ("-a ii -i random -p first -n insert", "./statistics/experiments/ii_random_first_insert.txt"),
        ("-a ii -i random -p best -n transpose", "./statistics/experiments/ii_random_best_transpose.txt"),
        ("-a ii -i random -p best -n exchange", "./statistics/experiments/ii_random_best_exchange.txt"),
        ("-a ii -i random -p best -n insert", "./statistics/experiments/ii_random_best_insert.txt"),
        ("-a ii -i cw -p first -n transpose", "./statistics/experiments/ii_cw_first_transpose.txt"),
        ("-a ii -i cw -p first -n exchange", "./statistics/experiments/ii_cw_first_exchange.txt"),
        ("-a ii -i cw -p first -n insert", "./statistics/experiments/ii_cw_first_insert.txt"),
        ("-a ii -i cw -p best -n transpose", "./statistics/experiments/ii_cw_best_transpose.txt"),
        ("-a ii -i cw -p best -n exchange", "./statistics/experiments/ii_cw_best_exchange.txt"),
        ("-a ii -i cw -p best -n insert", "./statistics/experiments/ii_cw_best_insert.txt"),
        ("-a vnd -i cw -p first -n transpose-exchange-insert", "./statistics/experiments/vnd_cw_first_transpose-exchange-insert.txt"),
        ("-a vnd -i cw -p first -n transpose-insert-exchange", "./statistics/experiments/vnd_cw_first_transpose-insert-exchange.txt")
    ]
    
    for options, output in experiments_data:
        with open(output, "w") as output_file:
            experiment(options, output, output_file)

def report(input_file, output_file):
    filename = os.path.splitext(os.path.basename(input_file))[0]
    with open(input_file, "r") as infile:
        lines = infile.readlines()
        sum1 = sum(float(line.split()[3]) for line in lines)
        sum2 = sum(float(line.split()[4]) for line in lines)
        count = len(lines)
        avg1 = "{:.6f}".format(sum1 / count) if count > 0 else "0.000000"
        avg2 = "{:.6f}".format(sum2)

    with open(output_file, "a") as outfile:
        outfile.write(f"{filename} {avg1} {avg2}\n")

def reports():
    with open("./statistics/reports/report.txt", "w") as output_file:
        pass
    for file in sorted(os.listdir("./statistics/experiments")):
        if file.endswith(".txt"):
            report(os.path.join("./statistics/experiments", file), "./statistics/reports/report.txt")

def statistical_tests():
    subprocess.run(["./scripts/statistical_tests.r"])

if __name__ == "__main__":
    # experiments()
    reports()
    statistical_tests()
