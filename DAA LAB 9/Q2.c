
#include <stdio.h>
int main() {
    int n, i, j, min1, min2;
    int f[100], parent[200], left[200], right[200];
    char s[100];

    printf("Enter number of symbols: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter symbol and frequency: ");
        scanf(" %c %d", &s[i], &f[i]);
        parent[i] = -1;
        left[i] = right[i] = -1;
    }

    for (i = n; i < 2 * n - 1; i++) {
        min1 = min2 = -1;

        for (j = 0; j < i; j++) {
            if (parent[j] != -1)
                continue;

            if (min1 == -1 || f[j] < f[min1]) {
                min2 = min1;
                min1 = j;
            } else if (min2 == -1 || f[j] < f[min2]) {
                min2 = j;
            }
        }

        f[i] = f[min1] + f[min2];
        left[i] = min1;
        right[i] = min2;
        parent[min1] = parent[min2] = i;
        parent[i] = -1;
    }

    printf("\nHuffman Codes:\n");

    for (i = 0; i < n; i++) {
        int node = i, top = 0, path[100];
        int p;

        while (parent[node] != -1) {
            p = parent[node];

            if (left[p] == node)
                path[top++] = 0;
            else
                path[top++] = 1;

            node = p;
        }

        printf("%c: ", s[i]);

        if (top == 0)
            printf("0");

        while (top > 0)
            printf("%d", path[--top]);

        printf("\n");
    }

    return 0;
}
