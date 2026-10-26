#include <stdio.h>

int graph[20][20], visited[20], n;

void BFS(int start) {
    int queue[20];
    int front = 0, rear = 0;
    int v, i;

    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        v = queue[front++];
        printf("%d ", v);

        for (i = 0; i < n; i++) {
            if (graph[v][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

int main() {
    int i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    for (i = 0; i < n; i++) {
        visited[i] = 0;
    }

    printf("BFS Traversal: ");
    BFS(start);

    return 0;
}
