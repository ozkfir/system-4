#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include "algo.h"
#include "graph.h"
#include "edge.h"
#include "node.h"
#include <string.h>

void relax(edge *e, node *head, int du) {
    while (head->node_num != e->endpoint->node_num)
        head = head->next;
    int w = e->weight;
    int dv = head->distance;
    if (du != INT_MAX) {
        if (dv > du + w) {
            head->distance = du + w;
        }
    }
}

int shortsPath_cmd(pnode head, int num_start, int num_end) {
    if (num_start == num_end)
        return 0;
    int min;
    resetQueue(head);
    node *s = ReturnNode(num_start, head);
    s->distance = 0;
    while (emptyQueue(head)) {
        node *u = ExtractMin(head);
        edge *edge1 = u->edges;
        while (edge1 != NULL) {
            relax(edge1, head, u->distance);
            edge1 = edge1->next;
        }
    }
    node *temp = head;
    while (temp->node_num != num_end) { temp = temp->next; }
    min = temp->distance;
    temp = NULL;
    return min;
}

int emptyQueue(node *head) {
    while (head != NULL) {
        if (head->inqueue == 1)
            return 1;
        head = head->next;
    }
    return 0;
}

void resetQueue(node *head) {
    while (head != NULL) {
        head->distance = INT_MAX;
        head->inqueue = 1;
        head = head->next;
    }
}

node *ExtractMin(node *head) {
    node *min = findMin(head);
    if (min != NULL)
        deleteMini(head, min);
    return min;
}

node *findMin(node *head) {
    while (head->inqueue == 0) { head = head->next; }
    node *min = head;
    while (head != NULL) {
        if (min->distance > head->distance && head->inqueue == 1)
            min = head;
        head = head->next;
    }
    return min;
}

void deleteMini(node *head, node *min) {
    while (head->node_num != min->node_num) { head = head->next; }
    head->inqueue = 0;
}


int dijkstra(node *head, int *nodes, int len, int start, int end, int *intb, int sum) {
    int min = INT_MAX;
    intb[end] = 1;
    int finish = 0;

    for (int i = 0; i < len; ++i) {
        finish += intb[i];
    }
    if (finish == len) {
        int d = shortsPath_cmd(head, nodes[start], nodes[end]);
        if (d == INT_MAX)
            return INT_MAX;
        return sum + d;
    }

    for (int i = 0; i < len; i++) {
        int d = shortsPath_cmd(head, nodes[start], nodes[end]);
        if (intb[i] != 1 && d != INT_MAX) {
            int *boo1 = (int *) malloc(len * sizeof(int));
            for (int j = 0; j < len; ++j) {
                boo1[j] = intb[j];
            }
            sum += d;
            int tempMin = dijkstra(head, nodes, len, end, i, boo1, sum);
            if (tempMin < min)
                min = tempMin;
            sum -= d;
            free(boo1);
        }
    }
    return min;
}

void TSP_cmd(pnode head, int *nodes, int len) {
    int min = INT_MAX;
    for (int j = 0; j < len; j++) {
        int *boo = (int *) calloc(len, sizeof(int));
        if (boo == NULL) {
            printf("problem with memory");
            exit(1);}
        int temp = dijkstra(head, nodes, len, j, j, boo, 0);
        free(boo);
        if (temp < min)
            min = temp;
    }
    if (min == INT_MAX) {
        printf("TSP shortest path: -1 \n");
    } else {
        printf("TSP shortest path: %d \n", min);
    }
}
