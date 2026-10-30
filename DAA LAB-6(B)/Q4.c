/*4. Sorting via reversal procedure: Suppose you are given a permutation p of the integers 1 to n, and seek to sort them to be in increasing order [1,...,n]. 
The only operation at your disposal is reverse(p,i,j), which reverses the elements of a subsequence pi,...,pj in the permutation.
 For example, the permutation [1,4,3,2,5] one reversal (of the second through fourth elements) suffices to sort.
 • Mathematically, show that it is possible to sort any permutation using O(n) reversals. 
 • Now suppose that the cost of reverse(p,i,j) is equal to its length, the number of elements in the range, |j −i|+1.
  Design an algorithm that sorts p in O(nlog2n) cost.
  Analyse the running time and cost of your algorithm and prove the correctness.*/
#include<stdio.h>
#define MAX 100
//Reverse elements from index i to j
void reverse(int a[],int i,int j,long long *cost,int *count)
{
    int temp;

    if(i>=j)
        return;

    *cost+=j-i+1;
    (*count)++;

    while(i<j)
    {
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
        i++;
        j--;
    }
}
//Part 1: Sort using at most O(n) reversals
void simpleSort(int a[],int n,long long *cost,int *count)
{
    int i,j;
    for(i=0;i<n-1;i++)
    {
        if(a[i]!=i+1)
        {
            for(j=i+1;j<n;j++)
            {
                if(a[j]==i+1)
                    break;
            }

            reverse(a,i,j,cost,count);
        }
    }
}
//Stable partition using divide and conquer
//Places elements <= value first
//Returns the first index after the <= value elements
int partition(int a[],int l,int r,int value,long long *cost,int *count)
{
    int mid,p1,p2;
    int leftFalse,rightTrue;
    //Using half-open interval [l,r)
    if(r-l==0)
        return l;

    if(r-l==1)
    {
        if(a[l]<=value)
            return l+1;
        else
            return l;
    }

    mid=(l+r)/2;
    p1=partition(a,l,mid,value,cost,count);
    p2=partition(a,mid,r,value,cost,count);
    //Left part:
    //[true elements][false elements]

    //Right part:
    //[true elements][false elements]

    //Rotate false part of left with true part of right
    leftFalse=mid-p1;
    rightTrue=p2-mid;
    if(leftFalse>0 && rightTrue>0)
    {
        reverse(a,p1,mid-1,cost,count);
        reverse(a,mid,p2-1,cost,count);
        reverse(a,p1,p2-1,cost,count);
    }

    return p1+rightTrue;
}

//Part 2: Divide and conquer sorting
void divideSort(int a[],int l,int r,int low,int high,long long *cost,int *count)
{
    int midValue,p;

    if(r-l<=1 || low>=high)
        return;

    midValue=(low+high)/2;

    //Partition into values <= midValue and > midValue
    p=partition(a,l,r,midValue,cost,count);

    //Sort both parts recursively
    divideSort(a,l,p,low,midValue,cost,count);
    divideSort(a,p,r,midValue+1,high,cost,count);
}

//Print array
void printArray(int a[],int n)
{
    int i;

    for(i=0;i<n;i++)
        printf("%d ",a[i]);

    printf("\n");
}

int main()
{
    int a[MAX],b[MAX];
    int n,i;
    long long cost1=0,cost2=0;
    int count1=0,count2=0;

    printf("Enter number of elements: ");
    scanf("%d",&n);

    printf("Enter permutation:\n");

    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        b[i]=a[i];
    }
    //Part 1
    simpleSort(a,n,&cost1,&count1);
    printf("\nPart 1: O(n) Reversals\n");
    printf("Sorted permutation:\n");
    printArray(a,n);
    printf("Number of reversals = %d\n",count1);
    printf("Total reversal cost = %lld\n",cost1);
    //Part 2
    divideSort(b,0,n,1,n,&cost2,&count2);
    printf("\nPart 2: Divide and Conquer\n");
    printf("Sorted permutation:\n");
    printArray(b,n);
    printf("Number of reversals = %d\n",count2);
    printf("Total reversal cost = %lld\n",cost2);
    return 0;
}