CC=g++
CFLAGS=-std=c++17 -O3 -Wall

OBJECTS=src/main.o src/configuration.o src/instance.o src/algorithm.o src/rules/initial_solution.o src/rules/pivoting.o src/rules/neighbourhood.o

.PHONY: clean

all: lop

lop: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o lop

statistics: lop
	./statistics.sh

statistical_tests: lop
	./statistical_tests.sh

clean:
	rm -f src/*~ src/*.o src/rules/*.o statistics/*.txt lop
