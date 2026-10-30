/*4. [Longest Increasing Subsequence] Given an integer array A =[a0,a1,...,an→1], 
find the length of the longest subsequence such that all elements of the subsequence are strictly increasing.
 By choosing the proper input representation, 
write a program in C to validate your algorithm and derive the complexity analysis of your algorithm.*/
#include<stdio.h>
int main()
{
    int n,a[100],dp[100],max=1;

    // Read number of elements
    printf("Enter number of elements: ");
    scanf("%d",&n);

    // Read array elements
    printf("Enter array elements: ");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);

    // Every element is an increasing subsequence of length 1
    for(int i=0;i<n;i++)
        dp[i]=1;

    // Find longest increasing subsequence
    for(int i=1;i<n;i++)
    {
        // Check previous elements
        for(int j=0;j<i;j++)
        {
            // Check if elements are increasing
            if(a[j]<a[i] && dp[j]+1>dp[i])
                dp[i]=dp[j]+1;
        }

        // Store maximum length
        if(dp[i]>max)
            max=dp[i];
    }

    printf("Length of LIS = %d",max);
    return 0;
}