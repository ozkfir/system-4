.PHONY: clean all

all: graph

graph: main.c edges.c node.c
	gcc -Wall -g main.c edges.c node.c

clean:
	rm -f *.o graph