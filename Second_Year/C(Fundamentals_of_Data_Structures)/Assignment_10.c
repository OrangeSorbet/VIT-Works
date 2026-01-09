#include <stdio.h>
#include <stdlib.h>
#include "5.stack_queue_func.h"

char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void DFS(int **graph, int size) {
    int start = 0;
    int *visited = calloc(size, sizeof(int));
    Stack s;
    s_init(&s);
    s_push(&s, start);

    while(!s_empty(&s)) {
        int jump = s_pop(&s);
        printf("%c ", alphabet[jump]);

        if(!visited[jump]) {
            visited[jump] = 1;
            for(int i = size-1; i >= 0; i--) {
                if(graph[jump][i] && !visited[i]) s_push(&s, i);
            }
        }
    }
}

void BFS(int **graph, int size) {
    int start = 0;
    int *visited = calloc(size, sizeof(int));
    Queue q;
    q_init(&q);

    q_enq(&q, start);
    visited[start] = 1;

    while (!q_empty(&q)) {
        int jump = q_deq(&q);
        printf("%c ", alphabet[jump]);

        for (int i = 0; i < size; i++) {
            if (graph[jump][i] && !visited[i]) {
                visited[i] = 1;
                q_enq(&q, i);
            }
        }
    }
}

int main() {
    int size;
    printf("Enter size (square matrix): ");
    scanf("%d", &size);

    int **arr = malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) arr[i] = calloc(size, sizeof(int));

    int count = 1;
    while (1) {
        int x, y;
        
        printf("Enter the coordinates of connection %d", count);
        printf("Enter x coord (0-%d): ", size - 1);
        if((scanf("%d", &x)) != 1 || x >= size || x < 0) {
            printf("Invalid input!\n");
            while(getchar() != '\n');
            continue;
        };

        printf("Enter y coord (0-%d): ", size - 1);
        if((scanf("%d", &y)) != 1 || y >= size || y < 0) {
            printf("Invalid input!\n");
            while(getchar() != '\n');
            continue;
        };

        arr[x][y] = 1;
        printf("Added connection!");
        count++;

        char cont;
        printf("Continue? (y/n): ");
        scanf(" %c", &cont);

        if (cont != 'y' && cont != 'Y')
            break;
    }

    printf("\nFinal matrix:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }
    while(1) {
        printf("What traversal?\n");
        printf("----------------\n");
        printf("1. Breadth First\n");
        printf("2. Depth First\n");
        int choice;
        printf("Enter choice - ");
        if(scanf("%d", &choice) != 1 || choice > 2 || choice < 1) {
            printf("Please enter 1/2 - ");
            while(getchar() != '\n');
            continue;
        }

        if(choice == 1) BFS(arr, size);
        else DFS(arr, size);
        break;
    }

    for (int i = 0; i < size; i++)
        free(arr[i]);
    free(arr);
}