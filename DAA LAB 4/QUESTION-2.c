/*
Algorithm:
1. Read two sets S1 and S2, each containing n elements.
2. Sort S2 using merge sort.
3. For every element a in S1:
      required = x - a
4. Perform binary search for required in S2.
5. If required is found:
      A pair exists whose sum is x.
6. If no required value is found:
      No such pair exists.

Time Complexity:
Sorting S2 = O(n log n)
n binary searches = O(n log n)
Total = O(n log n)

Space Complexity: O(n)
*/
#include <stdio.h>
void merge(int a[],int l,int m,int r)
{
    int i=l,j=m+1,k=0;
    int temp[r-l+1];

    while(i<=m&&j<=r)
    {
        if(a[i]<a[j])
            temp[k++]=a[i++];
        else
            temp[k++]=a[j++];
    }

    while(i<=m)
        temp[k++]=a[i++];

    while(j<=r)
        temp[k++]=a[j++];

    for(i=l,k=0;i<=r;i++,k++)
        a[i]=temp[k];
}
void mergeSort(int a[],int l,int r)
{
    if(l<r)
    {
        int m=(l+r)/2;
        mergeSort(a,l,m);
        mergeSort(a,m+1,r);
        merge(a,l,m,r);
    }
}
int binarySearch(int a[],int n,int key)
{
    int l=0,r=n-1;

    while(l<=r)
    {
        int m=(l+r)/2;

        if(a[m]==key)
            return 1;
        else if(a[m]<key)
            l=m+1;
        else
            r=m-1;
    }

    return 0;
}
int main()
{
    int n,x;

    printf("Enter size of sets: ");
    scanf("%d",&n);

    int S1[n],S2[n];

    printf("Enter elements of S1:\n");
    for(int i=0;i<n;i++)
        scanf("%d",&S1[i]);

    printf("Enter elements of S2:\n");
    for(int i=0;i<n;i++)
        scanf("%d",&S2[i]);

    printf("Enter x: ");
    scanf("%d",&x);

    mergeSort(S2,0,n-1);

    for(int i=0;i<n;i++)
    {
        int required=x-S1[i];

        if(binarySearch(S2,n,required))
        {
            printf("Pair found: %d + %d = %d\n",S1[i],required,x);
            return 0;
        }
    }
    printf("No pair found\n");
    return 0;
}