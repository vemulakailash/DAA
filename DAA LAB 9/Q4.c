
#include <stdio.h>

int main() {
    int n, i, j, temp;
    int a[100];
    int cost = 0, sum;

    printf("Enter number of sticks: ");
    scanf("%d", &n);

    printf("Enter stick lengths:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    while (n > 1) {
        for (i = 0; i < n - 1; i++) {
            for (j = 0; j < n - i - 1; j++) {
                if (a[j] > a[j + 1]) {
                    temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                }
            }
        }

        sum = a[0] + a[1];
        cost += sum;

        printf("Connect %d and %d: cost = %d\n",
               a[0], a[1], sum);

        a[0] = sum;

        for (i = 1; i < n - 1; i++)
            a[i] = a[i + 1];

        n--;
    }

    printf("Minimum total cost = %d\n", cost);

    return 0;
}
