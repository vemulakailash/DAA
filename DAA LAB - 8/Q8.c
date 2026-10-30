/*8. [Optimal Binary Search Trees (OBST)] Given a set of n distinct sorted keys K = ↑k1,k2,...,kn↓
 with search probabilities p1,p2,...,pn, and n+1dummykeys d0,d1,...,dn
  representing searches not in K with probabilities q0,q1,...,qn,findtheminimumexpected search cost of a binary search tree.
   By choosing the proper input representation,
 write a program in C to validate your procedures and derive the complexity analysis of your algorithm.*/
#include<stdio.h>
int main()
{
    int n;
    float p[20],q[20],cost[20][20],w[20][20];

    // Read number of keys
    printf("Enter number of keys: ");
    scanf("%d",&n);

    // Read probabilities of successful searches
    printf("Enter p values: ");
    for(int i=1;i<=n;i++)
        scanf("%f",&p[i]);

    // Read probabilities of unsuccessful searches
    printf("Enter q values: ");
    for(int i=0;i<=n;i++)
        scanf("%f",&q[i]);

    // Initialize cost and weight
    for(int i=1;i<=n+1;i++)
    {
        cost[i][i-1]=q[i-1];
        w[i][i-1]=q[i-1];
    }
    // Calculate OBST cost
    for(int length=1;length<=n;length++)
    {
        for(int i=1;i<=n-length+1;i++)
        {
            int j=i+length-1;

            w[i][j]=w[i][j-1]+p[j]+q[j];

            cost[i][j]=999999;

            // Try every key as root
            for(int r=i;r<=j;r++)
            {
                float left=cost[i][r-1];
                float right=cost[r+1][j];

                if(left+right+w[i][j]<cost[i][j])
                    cost[i][j]=left+right+w[i][j];
            }
        }
    }
    // Print minimum expected cost
    printf("Minimum expected search cost = %.2f",cost[1][n]);
    return 0;
}