#!/usr/bin/env python3
import os

import os

def compute_max_runtime():
    instances_dir = "./instances"
    statistics_dir = "./statistics"
    experiments_dir = os.path.join(statistics_dir, "experiments")
    filename1 = "vnd_cw_first_transpose-exchange-insert.txt"
    filename2 = "vnd_cw_first_transpose-insert-exchange.txt"

    with open(os.path.join(statistics_dir, "max_runtime.txt"), "w") as stats_file:
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

if __name__ == "__main__":
    compute_max_runtime()

