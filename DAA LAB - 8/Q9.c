/*9. [Collatz Conjecture] (Open Unsolved Problem): The Collatz Conjecture (also known as the 3n+1 problem or Ulam conjecture)
 defines a recurrence relation for any strictly positive integer n: T(n)= )︄n 2 if n is even 3n +1 if n is odd 
 The sequence repeatedly applies this function until n = 1. 
 Although unproven and still an open problem, it is conjectured that the sequence reaches 1 for all positive integers. 
Write a modular C program to analyse the trajectory of a user-provided starting value n ↔ 1 and across an interval [a,b].*/
#include<stdio.h>
int main()
{
    long long a,b,n,count;

    // Read range
    printf("Enter starting value: ");
    scanf("%lld",&a);

    printf("Enter ending value: ");
    scanf("%lld",&b);
    // Check every number in the range
    for(n=a;n<=b;n++)
    {
        long long x=n;
        count=0;

        printf("\n%d: ",n);

        // Generate Collatz sequence
        while(x!=1)
        {
            printf("%lld ",x);

            // If even, divide by 2
            if(x%2==0)
                x=x/2;

            // If odd, multiply by 3 and add 1
            else
                x=3*x+1;

            count++;
        }

        printf("1");
        printf("  Steps = %lld",count);
    }
    return 0;
}