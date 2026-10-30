#include <stdio.h>
int main() {
    int n, i, max, min, pos, temp;
    int a[100], best;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);

        if (a[i] % 2 != 0)
            a[i] *= 2;
    }

    best = 1000000000;

    while (1) {
        max = a[0];
        min = a[0];
        pos = 0;

        for (i = 1; i < n; i++) {
            if (a[i] > max) {
                max = a[i];
                pos = i;
            }

            if (a[i] < min)
                min = a[i];
        }

        temp = max - min;

        if (temp < best)
            best = temp;

        if (max % 2 != 0)
            break;

        a[pos] = max / 2;
    }

    printf("Minimum deviation = %d\n", best);

    return 0;
}
