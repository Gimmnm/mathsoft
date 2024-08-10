CXX = gcc
CXXFLAGS = -c -Wall -O3
SRC = $(wildcard ../cblas/*.c ../../Learning/rng/mtwister.c)
OBJ = $(patsubst %.c, %.o, $(SRC))

main : main.o cblas_dgemm.o
	$(CXX) $< cblas_dgemm.o -o $@

bentch_mark : main.o
	$(CXX) $< -lopenblas -o $@

strassen : strassen.o
	$(CXX) $< -o $@

rand_mat : rand_mat.o ../../Learning/rng/mtwister.o
	$(CXX) $< ../../Learning/rng/mtwister.o -o $@

analysis: analysis.o
	$(CXX) $< -o $@

%.o:%.c
	$(CXX) $(CXXFLAGS) $< -o $@

all : main bentch_mark rand_mat strassen analysis

.PHONY: clean
clean: 
	rm -f ../cblas/*.o main.o cblas_dgemm.o input output_bentch_mark output_main output_str main rand_mat bentch_mark strassen ../../Learning/rng/*.o analysis output_analysis