#!/usr/bin/env python3

import sys
import os
import subprocess
import shlex

def experiment(arg, options, output_file):
    options_list = shlex.split(options)
    for file in sorted(os.listdir("./instances")):
        if arg == '1':
                print(f"Running experiment for {file}...")
                command = ["./lop"] + options_list + ["-f", os.path.join("./instances", file)]
                subprocess.run(command, stdout=output_file, stderr=subprocess.PIPE)
        if arg == '2':
            if file.endswith("_150"):
                print(f"Running experiment for {file}...")
                command = ["./lop"] + options_list + ["-f", os.path.join("./instances", file)]
                subprocess.run(command, stdout=output_file, stderr=subprocess.PIPE)

def experiments(arg):

    if arg == '1':
        experiments_data = [
        ("-a ii -i random -p first -n transpose", "./statistics/ie1/experiments/ii_random_first_transpose.txt"),
        ("-a ii -i random -p first -n exchange", "./statistics/ie1/experiments/ii_random_first_exchange.txt"),
        ("-a ii -i random -p first -n insert", "./statistics/ie1/experiments/ii_random_first_insert.txt"),
        ("-a ii -i random -p best -n transpose", "./statistics/ie1/experiments/ii_random_best_transpose.txt"),
        ("-a ii -i random -p best -n exchange", "./statistics/ie1/experiments/ii_random_best_exchange.txt"),
        ("-a ii -i random -p best -n insert", "./statistics/ie1/experiments/ii_random_best_insert.txt"),
        ("-a ii -i cw -p first -n transpose", "./statistics/ie1/experiments/ii_cw_first_transpose.txt"),
        ("-a ii -i cw -p first -n exchange", "./statistics/ie1/experiments/ii_cw_first_exchange.txt"),
        ("-a ii -i cw -p first -n insert", "./statistics/ie1/experiments/ii_cw_first_insert.txt"),
        ("-a ii -i cw -p best -n transpose", "./statistics/ie1/experiments/ii_cw_best_transpose.txt"),
        ("-a ii -i cw -p best -n exchange", "./statistics/ie1/experiments/ii_cw_best_exchange.txt"),
        ("-a ii -i cw -p best -n insert", "./statistics/ie1/experiments/ii_cw_best_insert.txt"),
        ("-a vnd -i cw -p first -n transpose-exchange-insert", "./statistics/ie1/experiments/vnd_cw_first_transpose-exchange-insert.txt"),
        ("-a vnd -i cw -p first -n transpose-insert-exchange", "./statistics/ie1/experiments/vnd_cw_first_transpose-insert-exchange.txt")
        ]
        
    if arg == '2':
        experiments_data = [
            ("-a ils -i random -ls insert -pb exchange", "./statistics/ie2/experiments/ils_random_insert_exchange.txt"),
            ("-a ma -i random -ls insert -r cx -m exchange -s rank", "./statistics/ie2/experiments/ma_random_insert_cx_exchange_rank.txt"),
            ]
    
    for options, output in experiments_data:
        print(f"Running experiment with options: {options}")
        with open(output, "w") as output_file:
            experiment(arg, options, output_file)

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

def reports(arg):
    if arg == '1':
        with open("./statistics/ie1/reports/report.txt", "w") as output_file:
            pass
        for file in sorted(os.listdir("./statistics/ie1/experiments")):
            if file.endswith(".txt"):
                report(os.path.join("./statistics/ie1/experiments", file), "./statistics/ie1/reports/report.txt")
    if arg == '2':
        with open("./statistics/ie2/reports/report.txt", "w") as output_file:
            pass
        for file in sorted(os.listdir("./statistics/ie2/experiments")):
            if file.endswith(".txt"):
                report(os.path.join("./statistics/ie2/experiments", file), "./statistics/ie2/reports/report.txt")

def statistical_tests(arg):
    if arg == '1':
        arg1 = "./statistics/ie1/experiments/"
        arg2 = "./statistics/ie2/statistical_tests/"
    
    if arg == '2':
        arg1 = "./statistics/ie2/experiments/"
        arg2 = "./statistics/ie2/statistical_tests/"

    subprocess.run(["./scripts/statistical_tests.r", arg1 ,arg2])

def compute_max_runtime():
    if not os.path.exists("./max_runtime/max_runtime.txt"):
        print("Computing max runtime...")
        instances_dir = "./instances"
        statistics_dir = "./statistics/ie1/"
        experiments_dir = os.path.join(statistics_dir, "experiments")
        filename1 = "vnd_cw_first_transpose-exchange-insert.txt"
        filename2 = "vnd_cw_first_transpose-insert-exchange.txt"

        with open(os.path.join("./max_runtime/", "max_runtime.txt"), "w") as stats_file:
            for instance_name in sorted(os.listdir(instances_dir)):
                max_runtime = 0
                with open(os.path.join(experiments_dir, filename1)) as file1, \
                    open(os.path.join(experiments_dir, filename2)) as file2:
                    for line1, line2 in zip(file1, file2):
                        columns1 = line1.strip().split()
                        columns2 = line2.strip().split()
                        if columns1[0] == columns2[0] == instance_name:
                            runtime1 = float(columns1[4])
                            runtime2 = float(columns2[4])
                            max_runtime = round(((runtime1 + runtime2) / 2) * 100)
                            stats_file.write(f"{instance_name} {max_runtime}\n")
                            break
    else:
        print("Max runtime already computed.")    


if __name__ == "__main__":
    if len(sys.argv) != 1 and sys.argv[1] not in ['1', '2']:
        print("Usage:")
        print("For implementation exercise 1: python script.py 1")
        print("For implementation exercise 2: python script.py 2")
        sys.exit(1)

    arg = sys.argv[1]
    if arg == '2':
        compute_max_runtime()
    experiments(arg)
    reports(arg)
    statistical_tests(arg)