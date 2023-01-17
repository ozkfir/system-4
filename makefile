CC=gcc
AR=ar
FLAGS= -Wall -g

all: graph

graph: main.c edges.c node.c graph.h
	gcc -Wall -g main.c edges.c node.c graph.h

graph:node.o edge.o algo.o main.o



edge.o: edge.c edge.h
	$(CC) $(FLAGS) -c mylib.c
node.o: node.c node.h
	$(CC) $(FLAGS) -c node.c
algo.o: algo.c algo.h
	$(CC) $(FLAGS) -c algo.c
main.o: main.c algo.h node.h edge.h
	$(CC) $(FLAGS) -c main.c
.PHONY: clean all

clean:
	rm -f *.o *.a *.so graph
