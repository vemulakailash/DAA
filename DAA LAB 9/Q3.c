
#include <stdio.h>
int main() {
    int n, i, j, D, F;
    int d[100], f[100], used[100] = {0};
    int fuel, stops = 0, best;

    printf("Enter target distance and initial fuel: ");
    scanf("%d%d", &D, &F);

    printf("Enter number of stations: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter distance and fuel at station %d: ", i + 1);
        scanf("%d%d", &d[i], &f[i]);
    }

    fuel = F;

    while (fuel < D) {
        best = -1;

        for (i = 0; i < n; i++) {
            if (!used[i] && d[i] <= fuel) {
                if (best == -1 || f[i] > f[best])
                    best = i;
            }
        }

        if (best == -1) {
            printf("Minimum stops = -1\n");
            return 0;
        }

        fuel += f[best];
        used[best] = 1;
        stops++;
    }

    printf("Minimum stops = %d\n", stops);

    return 0;
}
