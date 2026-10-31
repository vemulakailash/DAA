#include <stdio.h>
int movesForRow(int n, int k)
{
    int d = n - k;
    int moves = 0;
    for (int x = d; x > 0; x -= 2)
        moves += x;
    moves += k * (k - 1) / 2;
    return moves;
}
int main()
{
    int n;
    int bestMoves = 1000000;
    int bestK = 1;
    printf("Enter number of rows: ");
    scanf("%d", &n);
    if (n <= 0)
    {
        printf("Invalid input\n");
        return 0;
    }
    for (int k = 1; k <= n; k++)
    {
        int moves = movesForRow(n, k);

        if (moves < bestMoves)
        {
            bestMoves = moves;
            bestK = k;
        }
    }
    int totalCoins = n * (n + 1) / 2;
    int formulaMoves = totalCoins / 3;
    printf("Total coins = %d\n", totalCoins);
    printf("Best base row = %d\n", bestK);
    printf("Minimum moves = %d\n", bestMoves);
    printf("Formula result = %d\n", formulaMoves);
    if (bestMoves == formulaMoves)
        printf("Validation successful: results match.\n");
    else
        printf("Validation failed.\n");
    return 0;
}

