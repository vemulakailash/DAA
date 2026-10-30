#include <stdio.h>

int parent[1000], land[1000];

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

int unite(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b)
        return 0;

    parent[b] = a;
    return 1;
}

int main() {
    int r, c, k, x, y, id;
    int islands = 0;
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    printf("Enter the number of rows, columns and land additions: ");
    scanf("%d%d%d", &r, &c, &k);

    for (int i = 0; i < r * c; i++)
        parent[i] = i;

    printf("Enter the coordinates of each land cell (row column):\n");

    while (k--) {
        scanf("%d%d", &x, &y);

        id = x * c + y;

        if (land[id]) {
            printf("Number of islands: %d\n", islands);
            continue;
        }

        land[id] = 1;
        islands++;

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx >= 0 && nx < r &&
                ny >= 0 && ny < c &&
                land[nx * c + ny]) {
                islands -= unite(id, nx * c + ny);
            }
        }

        printf("Number of islands: %d\n", islands);
    }

    return 0;
}