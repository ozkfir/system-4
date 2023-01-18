#include <stdio.h>
#include "edge.h"
#include "algo.h"
#include "node.h"
#include <ctype.h>
#include <stdlib.h>
#include "graph.h"
#include <math.h>

int main() {
    char c;
    int size,flag=1;
    node *head = NULL;
    node *start = NULL;
    node *end = NULL;
    int weight, numStart, numEnd;
    printf("a");
    scanf("%c", &c);
    while (flag) {
        switch (c) {
            case 'A': {
                printf("a");
                deleteGraph(&head);
                scanf("%d", &size);
                head = newGraph(size);
                scanf("%c", &c);
                while (1) {
                    if (c == 'n') {
                        printf("n");
                        scanf("%d", &numStart);
                        start = ReturnNode(numStart, head);
                        while (1) {
                            if ( scanf("%c", &c)!= EOF) {
                                break;
                            }
                            if(scanf("%d", &numEnd)==EOF) {
                                flag = 0;
                                break;
                            }
                            end = ReturnNode(numEnd, head);
                            scanf("%d", &weight);
                            addEdge(start, end, weight);
                        }
                    }
                    if (c != 'n')
                        break;
                }
                break;
            }
            case 'B': {
                scanf("%d", &numStart);
                start = ReturnNode(numStart, head);
                if (start == NULL)
                    addNode(&head, c);
                else {
                    deleteEdges(&(start->edges));////delit the firsr edge
                }
                while (1) {
                    if ( scanf("%c", &c)!= EOF) {
                        break;
                    }
                    if(scanf("%d", &numEnd)==EOF) {
                        flag = 0;
                        break;
                    }
                    end = ReturnNode(numEnd, head);
                    scanf("%d", &weight);
                    addEdge(start, end, weight);
                }

            }
            case 'D': {
                scanf("%d", &numStart);
                start = ReturnNode(numStart, head);
                deleteOneNode(start, head);
                if(scanf("%c", &c)==EOF)
                    flag=0;
                break;

            }
            case 'S': {
                scanf("%d%d", &numStart, &numEnd);
                printf("%d", shortsPath_cmd(head, numStart, numEnd));
                if(scanf("%c", &c)==EOF)
                    flag=0;
                break;
            }
            case 'T': {
                int numnode;
                scanf("%d", &numnode);
                int *arr_node = (int *) calloc(numnode, sizeof(int));
                for (int i = 0; i < numnode; i++) {
                    scanf("%d", &arr_node[i]);
                }

                TSP_cmd(head, arr_node, numnode);
                free(arr_node);
                if(scanf("%c", &c)==EOF)
                    flag=0;
                break;
            }
            default:
                break;
        }
    }
    return 0;
}

//int isTheChar(char c) {///////אפשר לעשות אם לא הצחליח לקבל int
//    return (c == 'A' || c == 'S' || c == 'T' || c == 'D' || c == 'B');
//}



