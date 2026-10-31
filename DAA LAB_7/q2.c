#include <stdio.h>

int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

int eggDrop(int eggs, int floors)
{
    int dp[20][101];

    for (int e = 1; e <= eggs; e++)
    {
        dp[e][0] = 0;
        dp[e][1] = 1;
    }

    for (int f = 0; f <= floors; f++)
        dp[1][f] = f;

    for (int e = 2; e <= eggs; e++)
    {
        for (int f = 2; f <= floors; f++)
        {
            dp[e][f] = 1000000;

            for (int x = 1; x <= f; x++)
            {
                int attempts = 1 + max(dp[e - 1][x - 1],
                                        dp[e][f - x]);

                if (attempts < dp[e][f])
                    dp[e][f] = attempts;
            }
        }
    }

    return dp[eggs][floors];
}

int main()
{
    int eggs, floors;

    printf("Enter number of eggs: ");
    scanf("%d", &eggs);

    printf("Enter number of floors: ");
    scanf("%d", &floors);

    if (eggs <= 0 || floors < 0)
    {
        printf("Invalid input\n");
        return 0;
    }

    int result = eggDrop(eggs, floors);

    printf("Number of eggs = %d\n", eggs);
    printf("Number of floors = %d\n", floors);
    printf("Minimum droppings = %d\n", result);

    return 0;
}