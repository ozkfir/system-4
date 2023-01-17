#include "edge.h"
#include "algo.h"
#include "node.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>



edge *newEdge(node *node1, int num) {
    edge *edge1 = NULL;
    edge1 = (edge *) calloc(1, sizeof(edge));
    if (edge1 == NULL) {
        printf("problem with memory");
        exit(1);
    }
    edge1->weight = num;
    edge1->endpoint = node1;
    edge1->next = NULL;
    return edge1;
}

void addEdge(node *nodeStart, node *nodeEnd, int num) {
    edge *edge1 = newEdge(nodeEnd, num);
    if (nodeStart->edges == NULL) {
        nodeStart->edges = edge1;
        return;
    }
    edge1->next = nodeStart->edges;
    nodeStart->edges = edge1;
}


void deleteSpecificEdge(edge **edge1, node *node1) {
    if ((*edge1)->endpoint->node_num != node1->node_num){
        edge *temp = *edge1;
        *edge1 = (*edge1)->next;
        temp->endpoint = NULL;
        free(temp);
        return;
    }

    edge *edge2=*edge1;
    while (edge2->next != NULL) {
        if ((edge2)->next->endpoint->node_num != node1->node_num)
            edge2=edge2->next;
        else {
            edge * temp = (edge2)->next;
            (edge2)->next=(edge2)->next->next;
            temp->endpoint = NULL;
            free(temp);
            return;
        }

    }
}


void deleteEdges(edge **head) {
    while (*head != NULL) {
        edge * temp=*head;
        (temp)->next = NULL;
        (temp)->endpoint = NULL;
        free(temp);
        (temp) = NULL;
    }
}


void printEdges(edge *edge1, int index) {
    while (edge1 != NULL) {
        printf("edge %d:weight-%d endpointvalue-%d\n\n", index, edge1->weight, edge1->endpoint->node_num);
        edge1 = edge1->next;
        index++;
    }

}