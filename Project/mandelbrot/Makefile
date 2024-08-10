CXX = gcc
CXXFLAGS = -c -Wall -O3
SRC = $(wildcard ../bmp/draw.c ../mandelbrot/*.c)
OBJ = $(patsubst %.c, %.o, $(SRC))

mandelbrot : main.o mandelbrot.o ../bmp/draw.o
	$(CXX) $< mandelbrot.o ../bmp/draw.o -o $@

sdlclick : sdlclick.o sdl.o
	$(CXX) `sdl2-config --cflags --libs` $< sdl.o -o $@

sdldyn : sdldyn.o sdl.o
	$(CXX) `sdl2-config --cflags --libs` $< sdl.o -o $@

%.o:%.c
	$(CXX) $(CXXFLAGS) $< -o $@

.PHONY: clean
clean: 
	rm -f ../bmp/*.o ../mandelbrot/*.o *.bmp mandelbrot sdlclick sdldyn