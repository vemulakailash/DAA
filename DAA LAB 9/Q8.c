#include <stdio.h>
int main() {
    int n, i, j, temp;
    int start[100], end[100];
    int rooms = 0, maxRooms = 0;
    int s = 0, e = 0;

    printf("Enter number of meetings: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter start and end time of meeting %d: ", i + 1);
        scanf("%d%d", &start[i], &end[i]);
    }

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (start[j] > start[j + 1]) {
                temp = start[j];
                start[j] = start[j + 1];
                start[j + 1] = temp;
            }

            if (end[j] > end[j + 1]) {
                temp = end[j];
                end[j] = end[j + 1];
                end[j + 1] = temp;
            }
        }
    }

    while (s < n) {
        if (start[s] < end[e]) {
            rooms++;
            if (rooms > maxRooms)
                maxRooms = rooms;
            s++;
        } else {
            rooms--;
            e++;
        }
    }

    printf("Minimum number of rooms = %d\n", maxRooms);

    return 0;
}
