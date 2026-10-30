#include <stdio.h>

int adj[100][100], color[100], q[100];

int main() {
    int n, m, u, v, i, j;
    int front, rear, x, k, ok;

    printf("Enter the number of vertices and edges: ");
    scanf("%d%d", &n, &m);

    for (i = 0; i < n; i++)
        color[i] = -1;

    printf("Enter the edges (u v):\n");

    for (i = 0; i < m; i++) {
        scanf("%d%d", &u, &v);

        adj[u][v] = adj[v][u] = 1;
        ok = 1;

        for (j = 0; j < n; j++)
            color[j] = -1;

        for (j = 0; j < n && ok; j++) {
            if (color[j] != -1)
                continue;

            front = rear = 0;
            q[rear++] = j;
            color[j] = 0;

            while (front < rear && ok) {
                x = q[front++];

                for (k = 0; k < n; k++) {
                    if (adj[x][k]) {
                        if (color[k] == -1) {
                            color[k] = 1 - color[x];
                            q[rear++] = k;
                        } else if (color[k] == color[x]) {
                            ok = 0;
                            break;
                        }
                    }
                }
            }
        }

        if (ok) {
            printf("Edge accepted. Graph is bipartite.\n");
        } else {
            printf("Edge rejected. Graph is not bipartite.\n");
            adj[u][v] = adj[v][u] = 0;
        }
    }

    return 0;
}