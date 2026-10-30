/*
Algorithm:
1. Create three arrays: red[], blue[], yellow[].
2. Read n pairs of number and colour.
3. Store each number according to its colour.
4. Print red[], then blue[], then yellow[].
5. Numbers of the same colour remain sorted because
   the input is already sorted by number.
Time Complexity: O(n)
Space Complexity: O(n)
*/
#include <stdio.h>
int main()
{
    int n;
    printf("Enter number of pairs: ");
    scanf("%d",&n);

    int red[n],blue[n],yellow[n];
    int r=0,b=0,y=0;

    printf("Enter number and colour (R/B/Y):\n");

    for(int i=0;i<n;i++)
    {
        int num;
        char colour;
        scanf("%d %c",&num,&colour);

        if(colour=='R')
            red[r++]=num;
        else if(colour=='B')
            blue[b++]=num;
        else if(colour=='Y')
            yellow[y++]=num;
    }

    printf("\nSorted by colour:\n");

    printf("Red: ");
    for(int i=0;i<r;i++)
        printf("%d ",red[i]);

    printf("\nBlue: ");
    for(int i=0;i<b;i++)
        printf("%d ",blue[i]);

    printf("\nYellow: ");
    for(int i=0;i<y;i++)
        printf("%d ",yellow[i]);

    return 0;
}