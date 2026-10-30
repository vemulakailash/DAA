/*
Algorithm:
1. Read n intervals (l,r).
2. Create 2n events.
3. Store:
      Left endpoint  -> +1
      Right endpoint -> -1
4. Sort all events by point.
5. If two events have the same point, process
   the starting endpoint before the ending endpoint.
6. Set current=0 and maximum=0.
7. Traverse the sorted events:
      If event is a start, increase current.
      If event is an end, decrease current.
8. Whenever current>maximum:
      maximum=current
      point=event point.
9. The stored point is inside the largest number
   of intervals.

Time Complexity: O(n log n)
Space Complexity: O(n)
*/
#include <stdio.h>
struct Event
{
    int point;
    int type;
};
void merge(struct Event a[],int l,int m,int r)
{
    int i=l,j=m+1,k=0;
    struct Event temp[r-l+1];

    while(i<=m&&j<=r)
    {
        if(a[i].point<a[j].point||
          (a[i].point==a[j].point&&a[i].type>a[j].type))
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
void mergeSort(struct Event a[],int l,int r)
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
    struct Event events[2*n];
    printf("Enter left and right endpoints:\n");

    for(int i=0;i<n;i++)
    {
        int l,r;
        scanf("%d %d",&l,&r);

        events[2*i].point=l;
        events[2*i].type=1;

        events[2*i+1].point=r;
        events[2*i+1].type=-1;
    }
    mergeSort(events,0,2*n-1);

    int current=0;
    int maximum=0;
    int maxPoint=0;
    
    for(int i=0;i<2*n;i++)
    {
        if(events[i].type==1)
            current++;
        else
            current--;

        if(current>maximum)
        {
            maximum=current;
            maxPoint=events[i].point;
        }
    }
    printf("Point: %d\n",maxPoint);
    printf("Maximum intervals: %d\n",maximum);
    return 0;
}