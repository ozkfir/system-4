#include <stdio.h>
#include "edge.h"
#include "algo.h"
#include "node.h"
#include <ctype.h>
#include <stdlib.h>
#include "graph.h"
#include <math.h>

int containnum(node *head, int start);

void setedge(node *head, int *flag, node *start, char *tv);

int main() {
    char tv;
    int size, flag = 1;
    node *head = NULL;
    node *start = NULL;
    int numStart, numEnd;
    scanf(" %c", &tv);
    while (flag) {
        switch (tv) {
            case 'A': {
                deleteGraph(&head);
                scanf(" %d", &size);
                head = newGraph(size);
                scanf(" %c", &tv);
                while (1) {
                    if (tv == 'n') {
                        tv = 'w';
                        scanf(" %d", &numStart);
                        start = ReturnNode(numStart, head);
                        setedge(head, &flag, start, &tv);
                    }
                    if (tv != 'n')
                        break;
                }
                break;
            }
            case 'B': {
                scanf(" %d", &numStart);
                if (!containnum(head, numStart))
                    addNode(&head, numStart);
                else {
                    start = ReturnNode(numStart, head);
                    deleteEdges(&(start->edges));////delit the firsr edge
                }
                start = ReturnNode(numStart, head);
                setedge(head, &flag, start, &tv);
                break;
            }
            case 'D': {
                scanf(" %d", &numStart);
                start = ReturnNode(numStart, head);
                if (head->node_num == start->node_num) {
                    deleteOneNode(start, head);
                    head = head->next;
                    free(start);
                } else {
                    node *temp = head;
                    deleteOneNode(start, head);
                    while (temp->next->node_num != start->node_num)
                        temp = temp->next;
                    temp->next = temp->next->next;
                    free(start);
                }
                if (scanf(" %c", &tv) == EOF)
                    flag = 0;
                break;

            }
            case 'S': {
                scanf(" %d", &numStart);
                scanf(" %d", &numEnd);
                int min = shortsPath_cmd(head, numStart, numEnd);
                if (min == INT_MAX)
                    min = -1;
                printf("Dijsktra shortest path: %d \n", min);
                if (scanf(" %c", &tv) == EOF)
                    flag = 0;
                break;
            }
            case 'T': {
                int numnode;
                scanf(" %d", &numnode);
                int *arr_node = (int *) calloc(numnode, sizeof(int));
                if (arr_node == NULL) {
                    printf("problem with memory");
                    exit(1);
                }
                for (int i = 0; i < numnode; i++) {
                    scanf(" %d", &arr_node[i]);
                }

                TSP_cmd(head, arr_node, numnode);
                free(arr_node);
                if (scanf(" %c", &tv) == EOF)
                    flag = 0;
                break;
            }
            default:
                break;
        }
    }
    deleteGraph(&head);
    return 0;
}


void setedge(node *head, int *flag, node *start, char *tv) {
    int numEnd, weight;
    node *end = NULL;
    while (1) {
        if (scanf(" %d", &numEnd) != 1) {
            if (scanf(" %s", tv) == EOF)
                *flag = 0;
            return;
        }
        end = ReturnNode(numEnd, head);
        if (scanf(" %d", &weight) == 1) {
            addEdge(start, end, weight);
        }
    }
}


int containnum(node *head, int start) {
    if (head == NULL)
        return 0;
    while (head != NULL && head->node_num != start)
        head = head->next;

    if (head == NULL)
        return 0;
    return 1;
}
