#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 100005
#define MAXL 11
#define HASH 262147

char words[MAXN][MAXL];
int table[HASH];

int distA[MAXN], distB[MAXN];

int frontA[MAXN], frontB[MAXN];

unsigned int hashWord(char *s) {
    unsigned int h = 5381;

    while (*s)
        h = h * 33 + (unsigned char)*s++;

    return h % HASH;
}

int findWord(char *s) {
    unsigned int h = hashWord(s);

    while (table[h] != -1) {
        if (strcmp(words[table[h]], s) == 0)
            return table[h];

        h = (h + 1) % HASH;
    }

    return -1;
}

void insertWord(int id) {
    unsigned int h = hashWord(words[id]);

    while (table[h] != -1)
        h = (h + 1) % HASH;

    table[h] = id;
}

int expand(int *front, int *size,
           int *dist, int *otherDist) {

    int next[MAXN];
    int nextSize = 0;

    for (int i = 0; i < *size; i++) {
        int u = front[i];

        char temp[MAXL];
        strcpy(temp, words[u]);

        for (int j = 0; temp[j]; j++) {
            char original = temp[j];

            for (char c = 'a'; c <= 'z'; c++) {
                if (c == original)
                    continue;

                temp[j] = c;

                int v = findWord(temp);

                if (v != -1) {
                    if (otherDist[v] != -1) {
                        return dist[u] + 1 + otherDist[v];
                    }

                    if (dist[v] == -1) {
                        dist[v] = dist[u] + 1;
                        next[nextSize++] = v;
                    }
                }
            }

            temp[j] = original;
        }
    }

    for (int i = 0; i < nextSize; i++)
        front[i] = next[i];

    *size = nextSize;

    return -1;
}

int main() {
    int n;

    printf("Enter number of dictionary words: ");
    scanf("%d", &n);

    memset(table, -1, sizeof(table));

    for (int i = 0; i < n; i++) {
        scanf("%10s", words[i]);
        insertWord(i);
    }

    char A[MAXL], B[MAXL];

    printf("Enter starting and target words: ");
    scanf("%10s%10s", A, B);

    int start = findWord(A);
    int target = findWord(B);

    if (target == -1) {
        printf("Target word not found\n");
        return 0;
    }

    if (strcmp(A, B) == 0) {
        printf("Minimum mutations: 0\n");
        return 0;
    }

    if (start == -1) {
        strcpy(words[n], A);
        start = n;
        insertWord(n);
        n++;
    }

    for (int i = 0; i < n; i++) {
        distA[i] = -1;
        distB[i] = -1;
    }

    int sizeA = 1, sizeB = 1;

    frontA[0] = start;
    frontB[0] = target;

    distA[start] = 0;
    distB[target] = 0;

    int answer = -1;

    while (sizeA > 0 && sizeB > 0) {

        if (sizeA <= sizeB) {
            answer = expand(
                frontA, &sizeA,
                distA, distB
            );
        } else {
            answer = expand(
                frontB, &sizeB,
                distB, distA
            );
        }

        if (answer != -1)
            break;
    }

    if (answer == -1)
        printf("No valid transformation exists: -1\n");
    else
        printf("Minimum mutations: %d\n", answer);

    return 0;
}