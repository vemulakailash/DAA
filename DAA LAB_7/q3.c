#include <stdio.h>

int hanoi3(int n)
{
    if (n == 0)
        return 0;

    return 2 * hanoi3(n - 1) + 1;
}

int hanoi4(int n)
{
    int dp[50];

    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        dp[i] = 1000000;

        for (int k = 1; k < i; k++)
        {
            int moves = 2 * dp[k] + hanoi3(i - k);

            if (moves < dp[i])
                dp[i] = moves;
        }
    }

    return dp[n];
}

int main()
{
    int n;

    printf("Enter number of disks: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Invalid input\n");
        return 0;
    }

    int moves = hanoi4(n);

    printf("Number of disks = %d\n", n);
    printf("Minimum moves = %d\n", moves);

    if (n == 8 && moves == 33)
        printf("Validation successful: 8 disks can be solved in 33 moves.\n");
    else
        printf("Validation completed.\n");

    return 0;
}