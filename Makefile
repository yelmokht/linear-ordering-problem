CC=g++
CFLAGS=-std=c++17 -O3 -Wall

SRC_DIR := src/
CPP_FILES := $(shell find $(SRC_DIR) -name '*.cpp')
OBJECTS := $(patsubst %.cpp, %.o, $(CPP_FILES))

.PHONY: clean

all: lop

lop: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o lop

statistics: lop
	./scripts/script.py

runtime:
	./scripts/compute_max_runtime.py

run: runtime
	./scripts/script_2.py

clean:
	find src -type f -name '*.o' -delete
	rm -f lop

