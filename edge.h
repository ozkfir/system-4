

#ifndef GRAPH_H_GCH_EDGE_H
#define GRAPH_H_GCH_EDGE_H

#include "node.h"
#include "algo.h"

typedef struct edge_ {
    int weight;
    struct GRAPH_NODE_ * endpoint;
    struct edge_ *next;
}edge, *pedge;


void deleteSpecificEdge(edge **edge1,node *node1);
edge* newEdge(node * node1,int num);
void addEdge(node * nodeStart,node *nodeEnd,int num);
void deleteEdges(edge ** edge1);
void printEdges(edge *edge1,int index);




#endif //GRAPH_H_GCH_EDGE_H
