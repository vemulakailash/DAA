#include <stdio.h>
int parent[100], active[100];
int size[100], sum[100], weight[100];
int adj[100][100], order[100], ans[100];
int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}
void unite(int a, int b) {
    a = find(a);
    b = find(b);

    if (a != b) {
        parent[b] = a;
        size[a] += size[b];
        sum[a] += sum[b];
    }
}
int maximum(int n) {
    int best = 0;

    for (int i = 0; i < n; i++) {
        if (active[i] && find(i) == i && sum[i] > best)
            best = sum[i];
    }

    return best;
}
int main() {
    int n, m, u, v;

    printf("Enter the number of vertices and edges: ");
    scanf("%d%d", &n, &m);
    printf("Enter the weight of each vertex:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d", &weight[i]);
        parent[i] = i;
        size[i] = 1;
        sum[i] = weight[i];
    }
    printf("Enter the edges (u v):\n");

    for (int i = 0; i < m; i++) {
        scanf("%d%d", &u, &v);
        adj[u][v] = adj[v][u] = 1;
    }
    printf("Enter the vertex deletion order:\n");

    for (int i = 0; i < n; i++)
        scanf("%d", &order[i]);

    for (int i = n - 1; i >= 0; i--) {
        ans[i] = maximum(n);

        u = order[i];
        active[u] = 1;

        for (int j = 0; j < n; j++) {
            if (adj[u][j] && active[j])
                unite(u, j);
        }
    }
    printf("Maximum component weights after each deletion:\n");
    for (int i = 0; i < n; i++)
        printf("%d\n", ans[i]);

    return 0;
}