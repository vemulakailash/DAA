
#include <stdio.h>
#include <string.h>
int main() {
    char s[100], ans[100];
    int freq[256] = {0}, wait[256] = {0};
    int n, k, i, j, best, possible = 1;

    printf("Enter string: ");
    scanf("%99s", s);

    printf("Enter K: ");
    scanf("%d", &k);

    n = strlen(s);

    if (k < 0) {
        printf("Invalid K\n");
        return 0;
    }

    if (k <= 1) {
        printf("Rearranged string = %s\n", s);
        return 0;
    }

    for (i = 0; i < n; i++)
        freq[(unsigned char)s[i]]++;

    for (i = 0; i < n; i++) {
        best = -1;

        for (j = 0; j < 256; j++) {
            if (freq[j] > 0 && wait[j] <= i) {
                if (best == -1 || freq[j] > freq[best])
                    best = j;
            }
        }

        if (best == -1) {
            possible = 0;
            break;
        }

        ans[i] = best;
        freq[best]--;
        wait[best] = i + k;
    }

    ans[i] = '\0';

    if (possible)
        printf("Rearranged string = %s\n", ans);
    else
        printf("Rearranged string = \n");

    return 0;
}
