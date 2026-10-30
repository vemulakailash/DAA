/*
Algorithm:
1. Read the entry time ai and exit time bi for each person.
2. Create an array of 2n events.
3. Store:
      Entry time  -> +1
      Exit time   -> -1
4. Sort all 2n events by time.
5. Set current = 0 and maximum = 0.
6. Traverse the sorted events:
      If event is an entry, increase current.
      If event is an exit, decrease current.
7. Whenever current > maximum:
      maximum = current
      time = current event time
8. The recorded time is the time when the most people
   were simultaneously present.

Time Complexity: O(n log n)
Space Complexity: O(n)
*/
#include <stdio.h>
struct Event
{
    int time;
    int type;
};
void merge(struct Event a[],int l,int m,int r)
{
    int i=l,j=m+1,k=0;
    struct Event temp[r-l+1];

    while(i<=m&&j<=r)
    {
        if(a[i].time<a[j].time)
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
    printf("Enter number of persons: ");
    scanf("%d",&n);
    struct Event events[2*n];
    printf("Enter entry and exit times:\n");
    for(int i=0;i<n;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);

        events[2*i].time=a;
        events[2*i].type=1;

        events[2*i+1].time=b;
        events[2*i+1].type=-1;
    }
    mergeSort(events,0,2*n-1);

    int current=0;
    int maximum=0;
    int maxTime=0;

    for(int i=0;i<2*n;i++)
    {
        if(events[i].type==1)
            current++;
        else
            current--;

        if(current>maximum)
        {
            maximum=current;
            maxTime=events[i].time;
        }
    }
    printf("Maximum people present: %d\n",maximum);
    printf("Time: %d\n",maxTime);
    return 0;
}