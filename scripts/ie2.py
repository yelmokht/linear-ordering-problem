#!/usr/bin/env python3

import os
import subprocess
import shlex

def experiment(options, output_file):
    options_list = shlex.split(options)
    for file in sorted(os.listdir("./instances")):
        if file.endswith("_150"):
            command = ["./lop"] + options_list + ["-f", os.path.join("./instances", file)]
            subprocess.run(command, stdout=output_file, stderr=subprocess.PIPE)

def experiments():
    experiments_data = [
        ("-a ils -i bi -ls insert -pb exchange", "./statistics/experiments/ils_bi_insert_exchange.txt"),
        ("-a ma -i bi -r ox -m inversion -s roulette", "./statistics/experiments/ma_bi_ox_inversion_roulette.txt"),
    ]
    
    for options, output in experiments_data:
        with open(output, "w") as output_file:
            experiment(options, output_file)

if __name__ == "__main__":
    experiments()
