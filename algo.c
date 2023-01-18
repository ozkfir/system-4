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
    printf("_________________\n");
    for (int i = 0; i < len; ++i) {
        printf("%d", intb[i]);
    }
    printf("\n_________________\n");

//chek if finish
    for (int i = 0; i < len; ++i) {
        finish += intb[i];
    }
    if (finish == len)
        return sum;

    for (int i = 0; i < len; i++) {
        int d = shortsPath_cmd(head, nodes[start], nodes[end]);
        if (intb[i] != 1 && d != INT_MAX) {
            int *boo1 = (int *) malloc(len * sizeof(int));
            for (int j = 0; j < len; ++j) {
                boo1[j]=intb[j];
            }
            sum += d;
//            printf("********%d******",i);
            int tempMin=dijkstra(head, nodes, len, end, i, boo1, sum);
            if (tempMin < min)
                min = tempMin;
            sum -= d;
            free(boo1);
        }
    }
    return min;
}

void TSP_cmd(pnode head, int *nodes, int len) {
    int min;

    for (int j = 0; j < len; j++) {
        int *boo = (int *) calloc(len, sizeof(int));
        printf("______d______");
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







//int **graph;  // adjacency matrix representing the graph
//
//int inputEdges(node *start, node *end) {
//    edge *temp = start->edges;
//    while (temp != NULL) {
//        if (temp->endpoint->node_num == end->node_num)
//            return temp->weight;
//        temp = temp->next;
//    }
//    return INT_MAX;
//}

//for (int j = 0; j < n; ++j) {
//        for (int i = 0; i < n; i++) {
//            if (i == j) { graph[j][i] = 0; }
//            else {
//                node *start = ReturnNode(nodes[j], head);
//                node *end = ReturnNode(nodes[i], head);
//                graph[j][i] = inputEdges(start, end);
//            }
//        }
//    }

//int *dist;  // distances from the source node
//bool *visited;  // keeps track of visited nodes
//int *k_vertices; // vertices that the user has chosen
//int k; // number of vertices that the user has chosen
//int m;  // number of edges
//
//
//int min_distance() {
//    int min = INT_MAX, min_index;
//
//    for (int v = 0; v < n; v++)
//        if (visited[v] == false && dist[v] <= min)
//            min = dist[v], min_index = v;
//
//    return min_index;
//}
//
//void dijkstra(int src) {
//    for (int i = 0; i < n; i++) {
//        dist[i] = INT_MAX;
//        visited[i] = false;
//    }
//    dist[src] = 0;
//
//    for (int count = 0; count < n - 1; count++) {
//        int u = min_distance();
//        visited[u] = true;
//
//        for (int v = 0; v < n; v++)
//            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX
//                && dist[u] + graph[u][v] < dist[v])
//                dist[v] = dist[u] + graph[u][v];
//    }
//}
//
//void TSP_cmd(node * head, int *nodes, int len) {
//
//    // input the number of nodes and edges
//    n = len;
//    k = len;
//
//    // dynamically allocate memory for the variables:
//    dist = (int *) malloc(n * sizeof(int));
//    visited = (bool *) malloc(n * sizeof(bool));
//    graph = (int **) malloc(n * sizeof(int *));
//    for (int i = 0; i < n; i++) {
//        graph[i] = (int *) malloc(n * sizeof(int));
//    }
//    k_vertices = (int *) malloc(n * sizeof(int));
//
//    // input edges
//    for (int j = 0; j < n; ++j) {
//        for (int i = 0; i < n; i++) {
//            if (i == j) { graph[j][i] = 0; }
//            else {
//                node *start = ReturnNode(nodes[j], head);
//                node *end = ReturnNode(nodes[i], head);
//                graph[j][i] = inputEdges(start, end);
//            }
//        }
//    }
//
//    int min_dist = INT_MAX;
//    for (int i = 0; i < k; i++) {
//        dijkstra(k_vertices[i]);
//        for (int j = 0; j < k; j++) {
//            if (i != j) {
//                if (dist[k_vertices[j]] != INT_MAX) {
//                    min_dist = f_min(min_dist, dist[k_vertices[j]]);
//                }
//            }
//        }
//    }
//    if (min_dist == INT_MAX) {
//        printf("-1\n");
//    } else {
//        printf("%d\n", min_dist);
//    }
//
//    //freeing the allocated memory
//    free(dist);
//    free(visited);
//    for (int i = 0; i < n; i++) {
//        free(graph[i]);
//    }
//    free(graph);
//    free(k_vertices);
//}
