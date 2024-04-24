import subprocess
import os

#Exercise 2.1.1
def run_algorithms():
    sls_1 = "./lop --ils --bi --insert --first ./statistics/experiments/ils_bi_insert_first.txt"
    sls_2 = "./lop --ma --bi --insert --constant ./statistics/experiments/ma_bi_insert_constant.txt"

    try:
        subprocess.run(sls_1, shell=True, check=True)
        subprocess.run(sls_2, shell=True, check=True)
        print("Commands executed successfully.")
    except subprocess.CalledProcessError as e:
        print("Error executing commands:", e)

#Exercise 2.1.2
def report(input_file, output_file):
    filename = os.path.basename(input_file)[:-4]
    with open(input_file, 'r') as f:
        sum1 = sum2 = count = 0
        for line in f:
            values = line.split()
            sum1 += float(values[3])
            sum2 += float(values[4])
            count += 1
        with open(output_file, 'a') as out:
            out.write(f"{filename} {sum1 / count if count > 0 else 0} {sum2}\n")

def reports():
    input_dir = "./statistics/experiments"
    output_file = "./statistics/reports/report.txt"
    for file in os.listdir(input_dir):
        if file.endswith(".txt"):
            report(os.path.join(input_dir, file), output_file)

#Exercise 2.1.3
def produce_correlation_plots():
    pass


#Exercise 2.1.4
def statistical_tests():
    subprocess.run(["Rscript", "statistical_tests.r"])

#Exercise 2.1.5
def run_time_distributions():
    pass

run_algorithms()