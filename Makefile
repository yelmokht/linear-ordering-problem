CC=g++
CFLAGS=-std=c++17 -O3 -Wall

SRC_DIR := src/
CPP_FILES := $(shell find $(SRC_DIR) -name '*.cpp')
OBJECTS := $(patsubst %.cpp, %.o, $(CPP_FILES))

.PHONY: clean

all: lop

lop: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o lop

ie1: lop
	./scripts/ie.py 1

ie2: lop
	./scripts/ie.py 2

clean:
	find src -type f -name '*.o' -delete
	rm -f lop

