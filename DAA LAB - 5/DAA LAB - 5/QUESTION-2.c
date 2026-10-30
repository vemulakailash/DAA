#include <stdio.h>
int main() {
    int n, k, a[100];
    printf("Enter n: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter k: ");
    scanf("%d", &k);

    for (int i = 0; i < n; i++) {
        int count = 0;

        for (int j = 0; j < n; j++)
            if (a[j] < a[i])
                count++;

        if (count == k - 1) {
            printf("Kth smallest = %d", a[i]);
            return 0;
        }
    }

    return 0;
}