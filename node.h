//
// Created by oz on 16/01/23.
//


#ifndef NODE_H
#define NODE_H
#include "edge.h"
#include "graph.h"

void printGraph_cmd(pnode head);
void deleteOneNode(node *node1, node *head);
node* newNode(int num);
node* newGraph(int p);
void addNode(node ** node1,int num);
void deleteGraph(node **node1);
node *ReturnNode(int t, node *head);

#endif //GRAPH_H_GCH_NODE_H
