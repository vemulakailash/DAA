/*7. [Rod Cutting with Reconstruction] Given a rod of length n inches and an array of prices P =[p1,p2,...,pn],
 where pi denotes the market price of a rod piece of length i inches, determine:
  (i) The maximum revenue obtainable by cutting up the rod and selling the pieces. 
  (ii) The exact lengths of the pieces that constitute the optimal decomposition (reconstruction).
   Cuts are integral and can be made in any combination (including leaving the rod uncut),
    and the sum of the piece lengths must equal n. By choosing the proper input representation,
 write a program in C to validate your algorithm and derive the complexity analysis of your algorithm.*/
#include<stdio.h>
int main()
{
    int n,p[100],dp[100],cut[100];
    // Read rod length
    printf("Enter rod length: ");
    scanf("%d",&n);

    // Read prices
    printf("Enter prices: ");
    for(int i=1;i<=n;i++)
        scanf("%d",&p[i]);
        
    dp[0]=0;

    // Find maximum revenue
    for(int i=1;i<=n;i++)
    {
        dp[i]=0;

        // Try every possible first cut
        for(int j=1;j<=i;j++)
        {
            if(p[j]+dp[i-j]>dp[i])
            {
                dp[i]=p[j]+dp[i-j];
                cut[i]=j;
            }
        }
    }
    // Print maximum revenue
    printf("Maximum revenue = %d\n",dp[n]);
    // Print selected pieces
    printf("Pieces: ");
    while(n>0)
    {
        printf("%d ",cut[n]);
        n=n-cut[n];
    }
    return 0;
}