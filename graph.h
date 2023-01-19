

#ifndef SYSTEM_4_GRAPH_H
#define SYSTEM_4_GRAPH_H


typedef struct GRAPH_NODE_ {
    int inqueue;
    int distance;
    int node_num;
    struct edge_ *edges;
    struct GRAPH_NODE_ *next;
} node, *pnode;

typedef struct edge_ {
    int weight;
    struct GRAPH_NODE_ *endpoint;
    struct edge_ *next;
} edge, *pedge;
#endif //SYSTEM_4_GRAPH_H
