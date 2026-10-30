#include <stdio.h>

int parent[100], size[100], sum[100];

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

int main() {
    int n, m, K, u, v, maximum;

    printf("Enter the number of vertices, edges and size limit K: ");
    scanf("%d%d%d", &n, &m, &K);

    printf("Enter the weight of each vertex:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d", &sum[i]);
        parent[i] = i;
        size[i] = 1;
    }

    printf("Enter the edges (u v):\n");

    for (int i = 0; i < m; i++) {
        scanf("%d%d", &u, &v);

        unite(u, v);

        maximum = 0;

        for (int j = 0; j < n; j++) {
            if (find(j) == j && size[j] <= K) {
                if (sum[j] > maximum)
                    maximum = sum[j];
            }
        }

        printf("Maximum component weight: %d\n", maximum);
    }

    return 0;
}