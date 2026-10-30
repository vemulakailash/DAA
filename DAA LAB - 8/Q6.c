/* 5. [Maximum Sum Increasing Subsequence] Given an array of n positive integers A = [a0,a1,...,an→1], 
find the maximum possible sum of a strictly increasing subsequence.
 By choosing the proper input representation,
 write a program in C to validate your algorithm and derive the complexity analysis of your algorithm.*/
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
        dp[i][0]=i;

    for(int j=0;j<=n;j++)
        dp[0][j]=j;

    // Calculate edit distance
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            // If characters are same
            if(a[i-1]==b[j-1])
                dp[i][j]=dp[i-1][j-1];

            // Otherwise choose minimum operation
            else
            {
                int insert=dp[i][j-1]+1;
                int delete=dp[i-1][j]+1;
                int replace=dp[i-1][j-1]+1;

                dp[i][j]=insert;

                if(delete<dp[i][j])
                    dp[i][j]=delete;

                if(replace<dp[i][j])
                    dp[i][j]=replace;
            }
        }
    }
    // Print minimum operations
    printf("Edit distance = %d\n",dp[m][n]);

    // Traceback
    int i=m,j=n;

    printf("Operations:\n");

    while(i>0 || j>0)
    {
        // Characters are same
        if(i>0 && j>0 && a[i-1]==b[j-1])
        {
            i--;
            j--;
        }
        // Replacement
        else if(i>0 && j>0 && dp[i][j]==dp[i-1][j-1]+1)
        {
            printf("Replace %c with %c\n",a[i-1],b[j-1]);
            i--;
            j--;
        }
        // Deletion
        else if(i>0 && dp[i][j]==dp[i-1][j]+1)
        {
            printf("Delete %c\n",a[i-1]);
            i--;
        }
        // Insertion
        else
        {
            printf("Insert %c\n",b[j-1]);
            j--;
        }
    }
    return 0;
}