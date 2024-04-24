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

clean:
	rm -f src/*~ src/*.o src/rules/*.o statistics/*/*.txt lop
	find src -type f -name '*.o' -delete

