/*Q2.
 [Coin Change:Total number of ways] Given an array of distinct positive integers representing coin denominations 
C = {c1,c2,...,cn} and a target amount V , find the total number of distinct combinations of coins that sum up to V .
 You may assume an infinite supply of each coin denomination. 
The order of coins does not matter (e.g., 1 + 2 and 2 +1 are considered the same combination). 
By choosing the proper input representation,
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
// 1 way to make amount 0
    dp[0]=1;
// Initially no ways to make other amounts
    for(int i=1;i<=V;i++)
        dp[i]=0;
// Calculate total number of ways
    for(int i=0;i<n;i++)
    {
        // Check all amounts from coin value to V
        for(int j=c[i];j<=V;j++)
        {
            dp[j]=dp[j]+dp[j-c[i]];
        }
    }
// Print answer
    printf("Total number of ways = %d",dp[V]);
    return 0;
}