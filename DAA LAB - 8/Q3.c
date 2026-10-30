/*3. [Longest Common Subsequence (LCS)] Given two sequences X = ↑x1,x2,...,xm↓ and Y = ↑y1,y2,...,yn↓, 
compute the length of their longest common subsequence and reconstruct the actual subsequence string.
 By choosing the proper input representation,
 write a program in C to validate your algorithm and derive the complexity analysis of your algorithm*/
#include<stdio.h>
#include<string.h>
int main()
{
    char a[100],b[100];
    int dp[100][100];
    // Read first string
    printf("Enter first string: ");
    scanf("%s",a);
    // Read second string
    printf("Enter second string: ");
    scanf("%s",b);

    int m=strlen(a);
    int n=strlen(b);

    // Initialize first row and column
    for(int i=0;i<=m;i++)
        dp[i][0]=0;

    for(int j=0;j<=n;j++)
        dp[0][j]=0;

    // Find LCS length
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            // If characters are same
            if(a[i-1]==b[j-1])
                dp[i][j]=dp[i-1][j-1]+1;

            // Otherwise take maximum
            else if(dp[i-1][j]>dp[i][j-1])
                dp[i][j]=dp[i-1][j];
            else
                dp[i][j]=dp[i][j-1];
        }
    }
    // Print LCS length
    printf("LCS length = %d\n",dp[m][n]);

    // Reconstruct LCS
    char lcs[100];
    int k=dp[m][n];
    lcs[k]='\0';

    int i=m,j=n;
    while(i>0 && j>0)
    {
        // Matching characters belong to LCS
        if(a[i-1]==b[j-1])
        {
            lcs[k-1]=a[i-1];
            i--;
            j--;
            k--;
        }

        // Move to larger value
        else if(dp[i-1][j]>dp[i][j-1])
            i--;
        else
            j--;
    }
    // Print actual LCS
    printf("LCS = %s",lcs);
    return 0;
}