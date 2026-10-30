#include <stdio.h>
#include <string.h>
#define N 20
#define LEN 2000

int overlap(char a[], char b[]) {
    int i, k;
    int n = strlen(a), m = strlen(b);

    for (k = n < m ? n : m; k > 0; k--) {
        for (i = 0; i < k; i++) {
            if (a[n - k + i] != b[i])
                break;
        }

        if (i == k)
            return k;
    }

    return 0;
}
int main() {
    int n, i, j, x, y, best, ov;
    char s[N][LEN], temp[LEN];

    printf("Enter number of strings: ");
    scanf("%d", &n);

    if (n < 1 || n > N) {
        printf("Invalid number of strings\n");
        return 0;
    }

    for (i = 0; i < n; i++) {
        printf("Enter string %d: ", i + 1);
        scanf("%1999s", s[i]);
    }
    while (n > 1) {
        best = 0;
        x = y = -1;

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (i == j)
                    continue;

                ov = overlap(s[i], s[j]);

                if (ov > best) {
                    best = ov;
                    x = i;
                    y = j;
                }
            }
        }
        if (x == -1) {
            x = 0;
            y = 1;
            best = 0;
        }

        strcat(s[x], s[y] + best);

        printf("Merged string: %s\n", s[x]);

        for (i = y; i < n - 1; i++)
            strcpy(s[i], s[i + 1]);

        n--;
    }
    printf("Greedy superstring = %s\n", s[0]);
    return 0;
}
