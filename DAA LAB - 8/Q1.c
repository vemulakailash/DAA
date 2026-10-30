/*Q1.[MinimumCoinChange]GivenanintegerarrayofcoindenominationsC = {c1,c2,...,cn} representing coins of di!erent values,
 and an integer target amount V ,findtheminimum number of coins needed to make up that amount. 
 You may assume an infinite supply of each coin denomination. If that amount of money cannot be made up by any combination of the coins, return →1. By choosing the proper input representation,
 write a program in C to validate your algorithm and derive the complexity analysis of your algorithm.*/
#include<stdio.h>
int main()
{
    int n,V;
    int c[100],dp[1000];

// Read number of coins
    printf("Enter number of coins: ");
    scanf("%d",&n);

// Read coin values
    printf("Enter coin values: ");
    for(int i=0;i<n;i++)
        scanf("%d",&c[i]);

// Read target amount
    printf("Enter target amount: ");
    scanf("%d",&V);

// 0 coins are needed for amount 0
    dp[0]=0;

// Set initial value
    for(int i=1;i<=V;i++)
        dp[i]=9999;

// Find minimum coins
    for(int i=1;i<=V;i++)
    {
        // Check every coin
        for(int j=0;j<n;j++)
        {
            // Check if coin can be used
            if(c[j]<=i && dp[i-c[j]]+1<dp[i])
                dp[i]=dp[i-c[j]]+1;
        }
    }

// Print answer
    if(dp[V]==9999)
        printf("Minimum coins = -1");
    else
        printf("Minimum coins = %d",dp[V]);

    return 0;
}