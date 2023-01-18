#include <stdio.h>
#include <stdlib.h>
#include "algo.h"
#include "edge.h"
#include "node.h"
#include "graph.h"

node *newGraph(int p) {
    node *node1 = NULL;
    if (p > 1) {
        node1 = (node *) calloc(1, sizeof(node));
        if (node1 == NULL) {
            printf("problem with memory");
            exit(1);
        }
        node1->node_num = 0;
        node1->edges = NULL;
    }
    node *node2 = node1;
    for (int i = 1; i < p; ++i) {
        node1->next = (node *) calloc(1, sizeof(node));
        if (node1 == NULL) {
            printf("problem with memory");
            exit(1);
        }
        node1->next->node_num = i;
        node1->next->edges = NULL;
        node1 = node1->next;
    }
    return node2;
}

node *newNode(int num) {
    node *node1 = NULL;
    node1 = (node *) calloc(1, sizeof(node));
    if (node1 == NULL) {
        printf("problem with memory");
        exit(1);
    }
    node1->node_num = num;
    node1->edges = NULL;
    node1->next = NULL;
    return node1;
}

void addNode(node **node1, int num) {
    node *node2 = newNode(num);
    if (*node1 == NULL) {
        *node1 = node2;
        return;
    }
    node2->next = (*node1);
    *node1 = node2;
}


void deleteGraph(node **head) {
    while (*head != NULL) {
        deleteEdges(&(*head)->edges);
        node *temp = *head;
        (*head) = (*head)->next;
        (temp)->next = NULL;
        free(temp);
    }
}

void deleteOneNode(node *node1, node *head) {

    deleteEdges(&((node1)->edges));
    while (head != NULL) {
        printf("-------------------%d\n",(head)->node_num);
        deleteSpecificEdge(&((head)->edges), node1);
        head = (head)->next;
    }

}


void printGraph_cmd(pnode head) {
    printf("Graph representation [src]---(weight)--->[dest]\n");
    while (head != NULL) {
        pedge current_edge = head->edges;
        if (current_edge == NULL) {
            printf("[%d]\n", head->node_num);
        }
        while (current_edge != NULL) {
            printf("[%d]---(%d)--->[%d]\n", head->node_num, current_edge->weight, current_edge->endpoint->node_num);
            current_edge = current_edge->next;
        }
        head = head->next;
    }
}

node *ReturnNode(int t, node *head) {
    node *node1 = head;

    if (node1 != NULL) {
        while ((node1)->node_num != t && (node1)->next != NULL) {
            node1 = node1->next;
        }

        if (node1->node_num == t)
            return node1;
    }
    return NULL;
}

