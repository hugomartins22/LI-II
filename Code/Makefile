CC = gcc
FLAGS= -std=c99 -Wextra -O2 -D_GNU_SOURCE

all: g1 g2 g3 g4 g5 stack parse filter allprog 
	
g1: g1.c g1.h
	$(CC) $(FLAGS) -o g1.o -c g1.c

g2: g2.c g2.h
	$(CC) $(FLAGS) -o g2.o -c g2.c

g3: g3.c g3.h
	$(CC) $(FLAGS) -o g3.o -c g3.c

g4: g4.c g4.h
	$(CC) $(FLAGS) -o g4.o -c g4.c

g5: g5.c g5.h
	$(CC) $(FLAGS) -o g5.o -c g5.c

stack: stack.c stack.h
	$(CC) $(FLAGS) -o stack.o -c stack.c
	
parse: parse.c parse.h
	$(CC) $(FLAGS) -o parse.o -c parse.c

filter: filter.c filter.h
	$(CC) $(FLAGS) -o filter.o -c filter.c

allprog: main.c g1.o g2.o g3.o g4.o g5.o filter.o stack.o parse.o
	$(CC) $(FLAGS) main.c g1.o g2.o g3.o g4.o g5.o filter.o stack.o parse.o -o program -lm
	
memcheck:
	valgrind --leak-check=yes ./program

clean:
	rm -rf *.o program