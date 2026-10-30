/*
Algorithm:
1. Read n intervals (x,y).
2. Sort the intervals by their starting point x.
3. Set the first interval as the current interval.
4. Traverse the remaining intervals.
5. If the next interval starts before or at the current
   interval's ending point, merge them:
      current.end = max(current.end,next.end)
6. Otherwise, store the current interval and start a new one.
7. Store the last interval.
8. Print the merged intervals.

Time Complexity: O(n log n)
Space Complexity: O(n)
*/
#include <stdio.h>
struct Interval
{
    int start;
    int end;
};
void merge(struct Interval a[],int l,int m,int r)
{
    int i=l,j=m+1,k=0;
    struct Interval temp[r-l+1];

    while(i<=m&&j<=r)
    {
        if(a[i].start<a[j].start)
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
void mergeSort(struct Interval a[],int l,int r)
{
    if(l<r)
    {
        int m=(l+r)/2;
        mergeSort(a,l,m);
        mergeSort(a,m+1,r);
        merge(a,l,m,r);
    }
}
int main()
{
    int n;
    printf("Enter number of intervals: ");
    scanf("%d",&n);

    struct Interval a[n],result[n];

    printf("Enter intervals:\n");

    for(int i=0;i<n;i++)
        scanf("%d %d",&a[i].start,&a[i].end);

    mergeSort(a,0,n-1);

    int count=0;
    int start=a[0].start;
    int end=a[0].end;
    for(int i=1;i<n;i++)
    {
        if(a[i].start<=end)
        {
            if(a[i].end>end)
                end=a[i].end;
        }
        else
        {
            result[count].start=start;
            result[count].end=end;
            count++;

            start=a[i].start;
            end=a[i].end;
        }
    }
    result[count].start=start;
    result[count].end=end;
    count++;

    printf("Merged intervals:\n");

    for(int i=0;i<count;i++)
        printf("(%d,%d) ",result[i].start,result[i].end);

    return 0;
}