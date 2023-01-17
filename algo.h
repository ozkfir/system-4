

#ifndef ALGO_H
#define ALGO_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include "node.h"
#include "edge.h"
#include "graph.h"


void relax(edge *e, node *head, int du);
int emptyQueue(node *head);
void deleteMini(node *head, node *min);
node *findMin(node *head);
node *ExtractMin(node *head);
void resetQueue(node *head);
int shortsPath_cmd(pnode head, int numstart, int numend);
int dijkstra(node *head,int *nodes,int len, int start, int end, int *boo, int sum);
    void TSP_cmd(pnode head, int *nodes, int len);




    //int isTheChar(char c);



//int inputEdges(node *start, node *end);
//    void TSP_cmd(pnode head,int *nodes,int len);
//void TSP_cmd(pnode head, int *nodes, int len);
//int min_distance();
//void dijkstra(int src);

//void build_graph_cmd(pnode *head);
//void insert_node_cmd(pnode *head);
//void delete_node_cmd(pnode *head);
//void deleteGraph_cmd(pnode* head);
//void TSP_cmd(pnode head);

#endif