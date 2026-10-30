/*5. [Maximum Sum Increasing Subsequence] Given an array of n positive integers A = [a0,a1,...,an→1], 
find the maximum possible sum of a strictly increasing subsequence. 
By choosing the proper input representation,
 write a program in C to validate your algorithm and derive the complexity analysis of your algorithm.*/
#include<stdio.h>
int main()
{
    int n,a[100],dp[100],max;
    // Read number of elements
    printf("Enter number of elements: ");
    scanf("%d",&n);

    // Read array elements
    printf("Enter array elements: ");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);

    // Initially, sum is the element itself
    for(int i=0;i<n;i++)
        dp[i]=a[i];

    // Find maximum sum increasing subsequence
    for(int i=1;i<n;i++)
    {
        // Check previous elements
        for(int j=0;j<i;j++)
        {
            // Check if elements are increasing
            if(a[j]<a[i] && dp[j]+a[i]>dp[i])
                dp[i]=dp[j]+a[i];
        }
    }
    // Find maximum sum
    max=dp[0];

    for(int i=1;i<n;i++)
    {
        if(dp[i]>max)
            max=dp[i];
    }
    printf("Maximum sum = %d",max);

    return 0;
}