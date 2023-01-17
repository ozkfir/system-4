CC=gcc
AR=ar
FLAGS= -Wall -g

all: graph

graph: main.o edge.o node.o algo.o
	$(CC) $(FLAGS) -o graph main.o edge.o node.o algo.o


edge.o: edge.c node.h edge.h
	$(CC) $(FLAGS) -c edge.c
node.o: node.c node.h edge.h
	$(CC) $(FLAGS) -c node.c
algo.o: algo.c algo.h node.h edge.h graph.h
	$(CC) $(FLAGS) -c algo.c
main.o: main.c algo.h node.h edge.h graph.h
	$(CC) $(FLAGS) -c main.c
.PHONY: clean all

clean:
	rm -f *.o *.a *.so graph
