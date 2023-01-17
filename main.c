#include <stdio.h>
#include "edge.h"
#include "algo.h"
#include "node.h"


int main() {

    char c;
    int size;
    node *head = NULL;
    node *start = NULL;
    node *end = NULL;
    int weight, numStart, numEnd;
    scanf("%c", &c);
    while (1) {
        switch (c) {
            case 'A': {
                scanf("%d", &size);
                head = newGraph(size);
                scanf("%c", &c);
                while (1) {
                    if (c == 'n') {
                        if (scanf("%c", &c) != EOF)
                            break;
                        scanf("%d", &numStart);
                        start = ReturnNode(numStart, head);
                        while (1) {
                            if (scanf("%c", &c) != EOF)
                                break;
                            scanf("%d", &numEnd);
                            end = ReturnNode(numEnd, head);
                            scanf("%d", &weight);
                            addEdge(start, end, weight);
                        }
                        if (c != 'n')
                            break;
                    }
                }
                break;
            }
            case 'B': {
                scanf("%d", &numStart);
                start = ReturnNode(numStart, head);
                if (start == NULL)
                    addNode(&head, c);
                deleteEdges(&(start->edges));////delit the firsr edge
                while (1) {
                    if (scanf("%c", &c) != EOF)
                        break;
                    scanf("%d", &numEnd);
                    end = ReturnNode(numEnd, head);
                    scanf("%d", &weight);
                    addEdge(start, end, weight);
                }

            }

            case 'D': {
                scanf("%d", &numStart);
                start = ReturnNode(numStart, head);
                deleteOneNode(start, head);
                scanf("%c",c);

            }
            case 'S': {
                scanf("%d%d", &numStart, &numEnd);
                printf("%d", shortsPath_cmd(head, numStart, numEnd));
                scanf("%c",c);
            }
            case 'T': {
                int numnode;
                scanf("%d", &numnode);
                int *nodesv = (int *) calloc(numnode, sizeof(int));
                for (int i = 0; i < numnode; i++) {
                    scanf("%d", &nodesv[i]);
                }
                TSP_cmd(head, nodesv, numnode);
                free(nodesv);
                scanf("%c",c);

            }
        }
    }
    return 0;
}

//int isTheChar(char c) {///////אפשר לעשות אם לא הצחליח לקבל int
//    return (c == 'A' || c == 'S' || c == 'T' || c == 'D' || c == 'B');
//}



