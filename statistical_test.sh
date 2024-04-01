#!/bin/sh

# Rebuild stats for one algo in exercise 1.1

options=$1
output=$2

echo 'filename	time	wsct' > $output

for file in ../instances/50* ../instances/100*
do
    ./pfsp_stats $options $file >> $output
done