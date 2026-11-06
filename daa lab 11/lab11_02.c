#include <stdio.h>
#include <stdlib.h>

#define MAX 100005

int adj[MAX][100];
int degree[MAX];

int dist[MAX];
int owner[MAX];

int queue[MAX];

int main() {
    int n, m;

    printf("Enter vertices and edges: ");
    scanf("%d%d", &n, &m);

    printf("Enter undirected edges:\n");

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);

        adj[u][degree[u]++] = v;
        adj[v][degree[v]++] = u;
    }

    int k, R;

    printf("Enter number of hubs and radius: ");
    scanf("%d%d", &k, &R);

    for (int i = 1; i <= n; i++) {
        dist[i] = -1;
        owner[i] = -1;
    }

    int front = 0, rear = 0;

    printf("Enter hub vertices in increasing index order:\n");

    for (int i = 1; i <= k; i++) {
        int h;
        scanf("%d", &h);

        if (dist[h] == -1) {
            dist[h] = 0;
            owner[h] = i;
            queue[rear++] = h;
        }
    }

    while (front < rear) {
        int u = queue[front++];

        if (dist[u] == R)
            continue;

        for (int i = 0; i < degree[u]; i++) {
            int v = adj[u][i];

            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                owner[v] = owner[u];

                queue[rear++] = v;
            }
        }
    }

    printf("\nVertex\tOwner\tDistance\n");

    for (int i = 1; i <= n; i++) {
        printf("%d\t%d\t%d\n",
               i, owner[i], dist[i]);
    }

    return 0;
}