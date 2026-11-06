#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 1005
#define INF LLONG_MAX

typedef struct {
    int v, w, parity;
} Node;

typedef struct {
    Node a[1000000];
    int front, rear;
} Deque;

void pushFront(Deque *q, Node x) {
    q->front--;
    q->a[q->front] = x;
}

void pushBack(Deque *q, Node x) {
    q->a[q->rear++] = x;
}

Node popFront(Deque *q) {
    return q->a[q->front++];
}

typedef struct {
    int to, weight, next;
} Edge;

Edge edges[20005];
int head[MAX], edgeCount = 0;

void addEdge(int u, int v, int w) {
    edges[edgeCount].to = v;
    edges[edgeCount].weight = w;
    edges[edgeCount].next = head[u];
    head[u] = edgeCount++;
}

int main() {
    int n, m, s;
    long long C;

    printf("Enter vertices, edges, source and penalty: ");
    scanf("%d %d %d %lld", &n, &m, &s, &C);

    for (int i = 1; i <= n; i++)
        head[i] = -1;

    printf("Enter directed edges (u v weight):\n");

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
    }

    long long dist[MAX][2];

    for (int i = 1; i <= n; i++)
        dist[i][0] = dist[i][1] = INF;

    Deque q;
    q.front = q.rear = 500000;

    dist[s][0] = 0;

    Node start = {s, 0, 0};
    pushFront(&q, start);

    while (q.front < q.rear) {
        Node cur = popFront(&q);

        int u = cur.v;
        int p = cur.parity;

        if (cur.w != dist[u][p])
            continue;

        for (int i = head[u]; i != -1; i = edges[i].next) {
            int v = edges[i].to;
            int w = edges[i].weight;
            int np = p ^ w;

            if (dist[u][p] + w < dist[v][np]) {
                dist[v][np] = dist[u][p] + w;

                Node next = {v, (int)dist[v][np], np};
                next.w = dist[v][np];

                if (w == 0)
                    pushFront(&q, next);
                else
                    pushBack(&q, next);
            }
        }
    }

    printf("\nMinimum Effective Costs:\n");

    for (int i = 1; i <= n; i++) {
        if (dist[i][0] == INF && dist[i][1] == INF) {
            printf("Vertex %d: Unreachable\n", i);
        } else {
            long long ans = dist[i][0];

            if (dist[i][1] != INF &&
                dist[i][1] + C < ans)
                ans = dist[i][1] + C;

            printf("Vertex %d: %lld\n", i, ans);
        }
    }

    return 0;
}