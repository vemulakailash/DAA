#include <stdio.h>
#include <stdlib.h>
int binary(int a[],int n,int x,int *c){
    int l=0,r=n-1;
    while(l<=r){
        int m=(l+r)/2;
        (*c)++;
        if(a[m]==x)return m;
        if(a[m]<x)l=m+1;
        else r=m-1;
    }
    return -1;
}
int ternary(int a[],int n,int x,int *c){
    int l=0,r=n-1;
    while(l<=r){
        int m1=l+(r-l)/3; 
        int m2=r-(r-l)/3;
        (*c)++;
        if(a[m1]==x)return m1;
        (*c)++;
        if(a[m2]==x)return m2;
        if(x<a[m1])r=m1-1;
        else if(x>a[m2])l=m2+1;
        else{
            l=m1+1;
            r=m2-1;
        }
    }
    return -1;
}
int main(){
    int *a,n,x,i,k,cb,ct,b,t;
    FILE *f;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    a=malloc(n*sizeof(int));
    printf("Enter sorted array:\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("Enter element to search: ");
    scanf("%d",&x);
    cb=0;
    ct=0;
    b=binary(a,n,x,&cb);
    t=ternary(a,n,x,&ct);
    if(b!=-1)
        printf("\nBinary Search: Found at position %d",b+1);
    else
        printf("\nBinary Search: Not Found");
    if(t!=-1)
        printf("\nTernary Search: Found at position %d",t+1);
    else
        printf("\nTernary Search: Not Found");
    printf("\nBinary comparisons: %d",cb);
    printf("\nTernary comparisons: %d\n",ct);
    f=fopen("data.txt","w");
    for(k=1;k<=n;k++){
        cb=0;
        ct=0;
        binary(a,k,x,&cb);
        ternary(a,k,x,&ct);
        fprintf(f,"%d %d %d\n",k,cb,ct);
    }
    fclose(f);
    f=fopen("plot.gnu","w");
    fprintf(f,"set title 'Binary Search vs Ternary Search'\n");
    fprintf(f,"set xlabel 'Input Size (n)'\n");
    fprintf(f,"set ylabel 'Number of Comparisons'\n");
    fprintf(f,"set grid\n");
    fprintf(f,"plot 'data.txt' using 1:2 with linespoints title 'Binary Search','data.txt' using 1:3 with linespoints title 'Ternary Search'\n");
    fprintf(f,"pause -1\n");
    fclose(f);
    system("gnuplot -p plot.gnu");
    free(a);
    return 0;
}