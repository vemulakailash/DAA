#include <stdio.h>
#define MAX 100
long long w[MAX], cost[MAX][MAX], sum[MAX][MAX];
int split[MAX][MAX];

void printTree(int i, int j) {
    if (i == j) {
        printf("%d", i + 1);
        return;
    }

    printf("(");
    printTree(i, split[i][j]);
    printf(",");
    printTree(split[i][j] + 1, j);
    printf(")");
}

int main() {
    int n, i, j, k, len;

    printf("Enter number of weights: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX) {
        printf("Invalid number of weights\n");
        return 0;
    }

    printf("Enter weights in order:\n");
    for (i = 0; i < n; i++) {
        scanf("%lld", &w[i]);

        if (w[i] <= 0) {
            printf("Weights must be positive\n");
            return 0;
        }
    }

    for (i = 0; i < n; i++) {
        cost[i][i] = 0;
        sum[i][i] = w[i];
    }

    for (len = 2; len <= n; len++) {
        for (i = 0; i <= n - len; i++) {
            j = i + len - 1;
            sum[i][j] = sum[i][j - 1] + w[j];
            cost[i][j] = 1000000000000000LL;

            for (k = i; k < j; k++) {
                long long value = cost[i][k]
                                + cost[k + 1][j]
                                + sum[i][j];

                if (value < cost[i][j]) {
                    cost[i][j] = value;
                    split[i][j] = k;
                }
            }
        }
    }

    printf("Minimum weighted depth cost = %lld\n",
           cost[0][n - 1]);

    printf("Optimal alphabetic tree: ");
    printTree(0, n - 1);
    printf("\n");

    return 0;
}
