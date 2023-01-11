#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <graph.h>

node *newgrap(int p, int index) {
    if (p == 0)
        return NULL;
    node *node1 = (node *) calloc(1, sizeof(node));
    node1->node_num = index;
    node->edges = null;
    node1->next = newgrap(p - 1, index + 1)
    return node1;
}

node *newnode(int num) {
    node *node1 = (node *) calloc(1, sizeof(node));
    node1->node_num = num;
    node->edges = null;
    node1->next = NULL;
    return node1;
}

edge *newedge(node *node1, int num) {
    edge *edge1 = (edge *) calloc(1, sizeof(edge));
    edge1->weight = num;
    edge1->endpoint = node1;
    edge1->*next = null;
    return edge1;
}

void addnode(node **node1, int num) {
    node *node2 = newnode(num);
    if (*node1 == null) {
        node1 = &node2;
        return;
    }
    node2->next = (*node1);
    node1 = &node2;
}

void addedge(node *nodestart, node *nodeend, int num) {
    edge *edge1 = newedge(nodeend, num);
    if (nodestart->edges == null) {
        nodestart->edges = *edge1
        break;
    }
    edge1->next = nodestart->edges;
    nodestart->edges = edge1;
}

void deletegraphead(node **node1) {
    deletegrap(*node1);
    free(*node1);
    node1 = NULL;
}

void deletegrap(node *node1) {
    if (node1->next != null)
        deletegrap(node1->next);
    deletedges(&(node1->edges));
    free(node1->edges);
    free(node1->next);////can free if have about him pointer?

}

void deletedges(edge **edge1) {
    if ((*edge1)->next != null)
        deletedge(&((*edge1)->next));
    (*edge1)->endpoint = NULL;
    free((*edge1));//can free emty ?and what hapend in father
}

void deleteOneNode(node *node1, node *head) {
    deletedge(&(node1->edges));
    while (head != NULL)
        deletSpecificEdge(&(head->edges), node1)
        head=head->next;
}

void deletSpecificEdge(edge **edge1, node *node1) {
    if (*edge1 == NULL)
        return;
    if ((*edge1)->endpoint == node1)
        edge1 == &((*edge1)->next);
    while ((*edge1)->next != NULL) {
        if ((*edge1)->next->endpoint == node1) {
            edge *edge2 = (*edge1)->next;
            (*edge1)->next == (*edge1)->next->next;
            edge2->endpoint=NULL;
            free(edge2);
            return;
        }
    }
}
