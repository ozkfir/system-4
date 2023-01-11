#ifndef GRAPH_
#define GRAPH_

typedef struct GRAPH_NODE_ *pnode;;

typedef struct edge_ {
    int weight;
    pnode endpoint;
    struct edge_ *next;
} edge, *pedge;


typedef struct GRAPH_NODE_ {
    int node_num;
    pedge edges;
    struct GRAPH_NODE_ *next;
} node, *pnode;

void build_graph_cmd(pnode *head);
void insert_node_cmd(pnode *head);
void delete_node_cmd(pnode *head);
void printGraph_cmd(pnode head); //for self debug
void deleteGraph_cmd(pnode* head);
void shortsPath_cmd(pnode head);
void TSP_cmd(pnode head);

void deleteOneNode(node *node1, node *head);
void deletSpecificEdge(edge **edge1, node *node1);
int isTheChar(char c);
node* RetureNode(char c, node *head);
node* newnode(int num);
node* newgrap(int p,int index);
edge* newedge(node * node1,int num);
void addnode(node **node1,int num);
void addedge(node * nodestart,node *nodeend,int num;
void deletegraphead(node ** node1);
void deletegrap(node * node1);
void deletedges(edge ** edge1);
#endif
