#include <stdio.h>
struct Item {
    int id;
    double v, w, rate;
    int used;
};

int main() {
    int n, i, step;
    double W, total = 0, remaining;
    struct Item a[100];

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter knapsack capacity: ");
    scanf("%lf", &W);

    for (i = 0; i < n; i++) {
        a[i].id = i + 1;
        a[i].used = 0;

        printf("Enter value, weight and decay rate for item %d: ", i + 1);
        scanf("%lf %lf %lf", &a[i].v, &a[i].w, &a[i].rate);
    }

    remaining = W;

    for (step = 0; step < n && remaining > 0; step++) {
        int best = -1;
        double bestDensity = 0;

        for (i = 0; i < n; i++) {
            double density;

            if (a[i].used || a[i].w <= 0)
                continue;

            density = a[i].v / a[i].w - a[i].rate * step;

            if (density > bestDensity) {
                bestDensity = density;
                best = i;
            }
        }

        if (best == -1)
            break;

        double take = remaining < a[best].w
                    ? remaining : a[best].w;

        double value = take * bestDensity;

        printf("Step %d: Item %d, weight taken = %.2f, value = %.2f\n",
               step, a[best].id, take, value);

        total += value;
        remaining -= take;
        a[best].used = 1;
    }

    printf("Total value = %.2f\n", total);
    printf("Unused capacity = %.2f\n", remaining);

    return 0;
}
