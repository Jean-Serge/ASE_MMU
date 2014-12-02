CC = gcc
CFLAGS = -Wall -ansi -pedantic -g
LIBDIR = ./lib
INC = -I./include
# Permet de linker la librairie libhardware.a
LIB = -L$(LIBDIR) -lhardware


# LIB doit être en fin de commande
main: 
	$(CC) $(CFLAGS) -o main.bin main.c $(INC) $(LIB) 


.PHONY: clean
clean:
	rm *.bin 
