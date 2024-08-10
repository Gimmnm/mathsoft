CXX = gcc
TARGET = lifegame
SRC = $(wildcard ../bmp/draw.c ../conway/*.c)
OBJ = $(patsubst %.c, %.o, $(SRC))

CXXFLAGS = -c -Wall

$(TARGET):$(OBJ)
	$(CXX) -lncurses -o $@ $^

%.o:%.c
	$(CXX) $(CXXFLAGS) $< -o $@

.PHONY: clean
clean: 
	rm -f ../bmp/*.o ../conway/*.o *.bmp $(TARGET)