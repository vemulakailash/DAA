#include <stdio.h>
int main() {
    int n, a[100];

    printf("Enter n: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int pos1 = (n + 1) / 2;
    int pos2 = (n + 2) / 2;
    int m1 = 0, m2 = 0;

    for (int i = 0; i < n; i++) {
        int count = 0;

        for (int j = 0; j < n; j++)
            if (a[j] < a[i])
                count++;

        if (count == pos1 - 1)
            m1 = a[i];

        if (count == pos2 - 1)
            m2 = a[i];
    }
    printf("Median = %.1f", (m1 + m2) / 2.0);

    return 0;
}