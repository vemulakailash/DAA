#include <stdio.h>
int parent[100], a[100], b[100];
int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}
void unite(int x, int y) {
    x = find(x);
    y = find(y);

    if (x != y)
        parent[y] = x;
}

void sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int main() {
    int n, m, u, v, count;

    printf("Enter the number of elements and edges: ");
    scanf("%d%d", &n, &m);

    printf("Enter the permutation elements:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        parent[i] = i;
    }

    printf("Enter the allowed swap edges (u v):\n");

    for (int i = 0; i < m; i++) {
        scanf("%d%d", &u, &v);
        unite(u, v);
    }
    for (int i = 0; i < n; i++) {
        if (find(i) != i)
            continue;

        count = 0;

        for (int j = 0; j < n; j++) {
            if (find(j) == i)
                b[count++] = a[j];
        }

        sort(b, count);
        count = 0;

        for (int j = 0; j < n; j++) {
            if (find(j) == i)
                a[j] = b[count++];
        }
    }
    printf("Lexicographically smallest permutation:\n");

    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");

    return 0;
}