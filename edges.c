
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <graph.h>


int* shortsPath_cmd(pnode head,int num){
    int *d;
    d=calloc(num,sizeof(int));
    struct GRAPH_NODE_ **father;
    nodes=calloc(num, sizeof(*GRAPH_NODE_));
    for (int i = 0; i < num; ++i) {
        d[i] = INT_MAX;
        nodes[i] = null;
    }
    d[(*head).node_num]=0;
    while (next!=null)
    {
        Extractmin
    }


        free();
        free();
    return d;
    }

node Extractmin(){}

void relax(struct edge_ e,int *d,node vnode,struct GRAPH_NODE_ **father){
    int u=((e.endpoint)->node_num);
    int v=vnode.node_num;
    if(*(d+v) > *(d+u)+e.weight) {
        *(d + v) = (*(d + u) + e.weight);
        *(father+v)=&vnode;
    }
}
//void DecreaseKey(){}


void delete_edge_cmd(pedge next){
    struct edge_ edge1=*next->next;
    if(edge1!=null)
        delete_edge_cmd(node);
    free(next);
}
void numofnodes(node){}

node** TSP_cmd(pnode head,node ** list,int lenlist){
    if(nude!=null &&)
    min(TSP_cmd(),TSP_cmd())



}
int sonofnode(node father,node son){
}

void build_graph_cmd(pnode *head) {
}

void insert_node_cmd(pnode *head){
    if(head->edges!=null)
        delete_edge_cmd(next);


}


void delete_node_cmd(pnode *head)
{
    free(*head->next);
}
void printGraph_cmd(pnode head); //for self debug
void deleteGraph_cmd(pnode* head){
    struct edge_ node=*head->*next;
    if(node!=null)
        delete_node_cmd(node);
    delete_node_cmd(*head);
}
#endif