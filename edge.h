
#ifndef EDGE_H
#define EDGE_H

#include "node.h"
#include "graph.h"



void deleteSpecificEdge(edge **edge1,node *node1);
edge* newEdge(node * node1,int num);
void addEdge(node * nodeStart,node *nodeEnd,int num);
void deleteEdges(edge ** edge1);
void printEdges(edge *edge1,int index);




#endif
