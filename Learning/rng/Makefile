CXX = gcc
CXXFLAGS = -c -Wall -O3
SRC = $(wildcard ../rng/*.c ../rand/TinyMT-master/tinymt/tinymt64.c)
OBJ = $(patsubst %.c, %.o, $(SRC))

test : test.o mtwister.o ../rand/TinyMT-master/tinymt/tinymt64.o
	$(CXX) $< mtwister.o ../rand/TinyMT-master/tinymt/tinymt64.o -o $@

%.o:%.c
	$(CXX) $(CXXFLAGS) $< -o $@

.PHONY: clean
clean: 
	rm -f ../rand/*.o mtwister.o test ../rand/TinyMT-master/tinymt/tinymt64.o