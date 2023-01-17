//
// Created by oz on 16/01/23.
//


#ifndef GRAPH_H_GCH_NODE_H
#define GRAPH_H_GCH_NODE_H
#include "edge.h"
#include "algo.h"


typedef struct GRAPH_NODE_ {
    int inqueue;
    int distance;
    int node_num;
    struct edge_ *edges;
    struct GRAPH_NODE_ *next;
}node,*pnode;

void printGraph_cmd(pnode head);
void deleteOneNode(node *node1, node *head);
node* newNode(int num);
node* newGraph(int p);
void addNode(node ** node1,int num);
void deleteGraph(node **node1);
node *ReturnNode(int t, node *head);

#endif //GRAPH_H_GCH_NODE_H
