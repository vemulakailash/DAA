/*3. Implement the Longest Common Subsequence (LCS) algorithm using Dynamic
Programming. Given two strings, find the length of their longest common subsequence and
display the subsequence. Analyze the complexity of the algorithm.*/
#include <stdio.h>
#include <string.h>
int main() {
    char a[100], b[100];
    scanf("%s", a);
    scanf("%s", b);
    int n = strlen(a);
    int m = strlen(b);

    int dp[100][100] = {0};

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {

            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                if (dp[i - 1][j] > dp[i][j - 1])
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = dp[i][j - 1];
            }
        }
    }
    printf("%d", dp[n][m]);
    return 0;
}
/*
4. Write a program to implement Matrix Chain Multiplication using Dynamic Programming.
Given the dimensions of N-1 matrices in an array arr[], determine the minimum number of
scalar multiplications required to multiply the complete matrix chain.
Input:
N= 4
arr[] = {10, 30, 5, 60}
Output:
4500
Time Complexity:O(N3) 
*/
#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);

    int arr[100];
    int dp[100][100] = {0};

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for (int len = 2; len < n; len++) {
        for (int i = 1; i < n - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = 999999;
            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k + 1][j]
                         + arr[i - 1] * arr[k] * arr[j];

                if (cost < dp[i][j])
                    dp[i][j] = cost;
            }
        }
    }
    printf("%d", dp[1][n - 1]);
    return 0;
}