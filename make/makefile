CC = gcc
FLAGS = -Wall

TARGET = 2048
DEP = ../library/functions.h
OBJ = ../2048/main.o ../library/functions.o

$(TARGET): $(OBJ)
	$(CC) $(FLAGS) $^ -o $@

%.o: %.c $(DEP)
	$(CC) $(FLAGS) -c $< -o $@

.PHONY: clear

clear:
	-rm $(OBJ)
	-rm $(TARGET)
