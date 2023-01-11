#include <stdio.h>

#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include "graph.h"

int main ()
{

    char c;
    int size;
    node *head = NULL;
    node *nodestart = NULL;
    node *nodeend = NULL;
    char weight;
    scanf("%c", &c);
    switch (c) {
        case A: {
            scanf("%d", &size);
            head = newgrap((int) size);
            scanf("%c", &c);
            while (1) {
                if (c == 'n') {
                    scanf("%c", &c);
                    nudestart = RetureNode(c,head);
                    while (1) {
                        scanf("%c",&c);
                        if (c == 'n' || isTheChar(c))
                            break;
                        nudeend = RetureNode(c,head);
                        scanf("%c", &weight);
                        addedge(nodestart , nodeend,weight);
                    }
                    if (isTheChar(c))
                        break;
                }
            }
            break;
        }
        case B: {
            scanf("%c",&c);
            nodestart = NULL;
            nodestart = RetureNode(c);
            if (nodestart == NULL)
                addnode(&head, c);
            deletedges(&(nodestart->edges));////delit the firsr edge


            while (1) {
                scanf("%c", &c);
                if (isTheChar(c))
                    break;
                nudeend = RetureNode(c,head);
                scanf("%c",&weight);
                addedge(nodeend, weight);
            }

        }
    }
    case D: {
        scanf("%c",&c);
        nodestart = NULL;
        nodestart = RetureNode(c);
        deleteOneNode(nodestart);
    }
    case S: {
    }
    case T: {
    }
//    default:
return  0;
}

int isTheChar(char c) {///////אפשר לעשות אם לא הצחליח לקבל int
    return (c == 'A' || c == 'S' || c == 'T' || c == 'D' || c == 'B');
}

node* RetureNode(char c, node *head) {
    int t = (int) c;
    node *node1 = head;
    while ((node1)->node_num != t && (node1)->next != NULL) {
        node1 = node1->next;
    }
    if ((node1)->node_num == t)
        return node1;
    return NULL;
}