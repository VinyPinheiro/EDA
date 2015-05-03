CC = gcc
CFLAGS = -W -Wall -pedantic -ansi -g -O2
LIBS = -lSDL2 -lSDL2_ttf

SRC = ${wildcard *.c}
OBJ = ${SRC:.cpp=.o}

all:
	@make lista

%.o: %.c
	$(CC) $(CFLAGS) -c $<

lista: $(OBJ)
	$(CC) -o $@ $(OBJ) $(LIBS)

clean:
	@rm -rf *.o

dist-clean: clean
	@rm -rf game
