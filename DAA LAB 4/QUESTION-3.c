/*
Algorithm:
1. Read n integers into array S, and read k and T.
2. Sort S using merge sort.
3. Select k-1 elements from S using recursion.
4. For each selection, calculate:
      required = T - sum
5. Use binary search to find required in the remaining
   elements of S.
6. If required is found, k elements add up to T.
7. If no required element is found for any selection,
   then no k elements add up to T.

Time Complexity: O(n^(k-1) log n)
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
int binarySearch(int a[],int l,int r,int key)
{
    while(l<=r)
    {
        int m=(l+r)/2;

        if(a[m]==key)
            return m;
        else if(a[m]<key)
            l=m+1;
        else
            r=m-1;
    }

    return -1;
}
int findK(int a[],int n,int k,int T,int index,int count,int sum)
{
    if(count==k-1)
    {
        int required=T-sum;

        if(binarySearch(a,index,n-1,required)!=-1)
            return 1;

        return 0;
    }
    for(int i=index;i<n;i++)
    {
        if(findK(a,n,k,T,i+1,count+1,sum+a[i]))
            return 1;
    }
    return 0;
}
int main()
{
    int n,k,T;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    int S[n];
    printf("Enter elements:\n");
    for(int i=0;i<n;i++)
        scanf("%d",&S[i]);
    printf("Enter k: ");
    scanf("%d",&k);
    printf("Enter T: ");
    scanf("%d",&T);
    mergeSort(S,0,n-1);
    if(k<2||k>n)
    {
        printf("Invalid value of k\n");
        return 0;
    }
    if(findK(S,n,k,T,0,0,0))
        printf("%d elements with sum %d exist\n",k,T);
    else
        printf("No %d elements with sum %d exist\n",k,T);

    return 0;
}