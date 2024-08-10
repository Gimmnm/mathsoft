CXX = gcc
CXXFLAGS = -c -Wall -O3
SRC = $(wildcard ../calpi/*.c)
OBJ = $(patsubst %.c, %.o, $(SRC))

pi : pi.o
	$(CXX) $< -lmpfr -lgmp -o $@

%.o:%.c
	$(CXX) $(CXXFLAGS) $< -o $@

.PHONY: clean
clean: 
	rm -f ../calpi/*.o pi.o pi