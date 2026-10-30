//1. Write a program to find the nth Fibonacci number using Dynamic Programming.
#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    int dp[100];
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
     dp[i] = dp[i - 1] + dp[i - 2];
    printf("%d", dp[n]);
    return 0;
}
