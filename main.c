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
//                printf("aaaaaaaaaaaaaaaaaaaaaaaaaaaa");
                deleteGraph(&head);
                scanf(" %d", &size);
                head = newGraph(size);
//                printf("\n");
//                printGraph_cmd(head);
//                printf("ggg");
                scanf(" %c", &tv);
                while (1) {
                    if (tv == 'n') {
                        tv = 'w';
//                        printf("nnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnn\n");
                        scanf(" %d", &numStart);
                        start = ReturnNode(numStart, head);
//                        printf("%d", start->node_num);
//                    printf("bjkbjl,2");
                        setedge(head, &flag, start, &tv);
//                    printf("uuuuuuuuuuuuuuuuu");
                    }
                    if (tv != 'n')
                        break;
                }
                break;
            }
            case 'B': {
//                printf("bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb\n");
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
//                printf("dddddddddddddddddddddddddddddddddddddddddddd\n");
                scanf(" %d", &numStart);
                start = ReturnNode(numStart, head);
                if (head->node_num == start->node_num) {
                    deleteOneNode(start, head);
                    head = head->next;
                    free(start);
                } else{
                    node *temp=head;
                    deleteOneNode(start, head);
                    while (temp->next->node_num != start->node_num)
                        temp=temp->next;
                    temp->next=temp->next->next;
                    free(start);
                }
//                printGraph_cmd(head);
                if (scanf(" %c", &tv) == EOF)
                    flag = 0;
                break;

            }
            case 'S': {
//                printf("ssssssssssssssssssssssssssssssssssssssssssss\n");
                scanf(" %d", &numStart);
                scanf(" %d", &numEnd);
                int min=shortsPath_cmd(head, numStart, numEnd);
                if(min==INT_MAX)
                    min=-1;
                printf("Dijsktra shortest path: %d \n", min);
                if (scanf(" %c", &tv) == EOF)
                    flag = 0;
                break;
            }
            case 'T': {
//                printf("tttttttttttttttttttttttttttttttttttttt\n");
                int numnode;
//                printf(("2\n"));
                scanf(" %d", &numnode);
//                printf(("2\n"));
                int *arr_node = (int *) calloc(numnode, sizeof(int));
                if (arr_node == NULL) {
                        printf("problem with memory");
                        exit(1);
                    }
//                printf("-------%d\n",numnode);
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
//    printGraph_cmd(head);
    deleteGraph(&head);
//    printf("\ngraph deleted\n");
    return 0;
}


void setedge(node *head, int *flag, node *start, char *tv) {
    int numEnd, weight;
    node *end = NULL;
    while (1) {
        if (scanf(" %d", &numEnd) != 1) {  //EoF or char
            if (scanf(" %s", tv) == EOF)   //end of file
                *flag = 0;
            return;
        }
        end = ReturnNode(numEnd, head);
        if (scanf(" %d", &weight) == 1) {
            addEdge(start, end, weight);
//            printGraph_cmd(head);
        }
    }
}

//int isTheChar(char c) {///////אפשר לעשות אם לא הצחליח לקבל int
//    return (c == 'A' || c == 'S' || c == 'T' || c == 'D' || c == 'B');
//}


int containnum(node *head, int start) {
    if (head == NULL)
        return 0;
    while (head != NULL && head->node_num != start)
        head = head->next;

    if (head == NULL)
        return 0;
    return 1;
}
