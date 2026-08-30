#include<stdio.h>
void add(int A[16][16],int B[16][16],int C[16][16],int n)
{
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            C[i][j]=A[i][j]+B[i][j];
}
void sub(int A[16][16],int B[16][16],int C[16][16],int n)
{
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            C[i][j]=A[i][j]-B[i][j];
}
void multiply(int A[16][16],int B[16][16],int C[16][16],int n)
{
    int i,j,m;
    int A1[16][16],A2[16][16];
    int B1[16][16],B2[16][16];
    int X[16][16],Y[16][16];
    int P[16][16],Q[16][16];
    int T[16][16],U[16][16];

    if(n==1)
    {
        C[0][0]=A[0][0]*B[0][0];
        return;
    }

    m=n/2;

    for(i=0;i<m;i++)
        for(j=0;j<m;j++)
        {
            A1[i][j]=A[i][j];
            A2[i][j]=A[i][j+m];

            B1[i][j]=B[i][j];
            B2[i][j]=B[i][j+m];
        }

    add(A1,A2,X,m);
    add(B1,B2,Y,m);
    multiply(X,Y,P,m);

    sub(A1,A2,X,m);
    sub(B1,B2,Y,m);
    multiply(X,Y,Q,m);

    add(P,Q,T,m);
    sub(P,Q,U,m);

    for(i=0;i<m;i++)
        for(j=0;j<m;j++)
        {
            C[i][j]=T[i][j]/2;
            C[i][j+m]=U[i][j]/2;
            C[i+m][j]=U[i][j]/2;
            C[i+m][j+m]=T[i][j]/2;
        }
}
int main()
{
    int A[16][16],B[16][16],C[16][16];
    int n,i,j;

    printf("Enter n: ");
    scanf("%d",&n);

    printf("Enter first matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&A[i][j]);

    printf("Enter second matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&B[i][j]);

    multiply(A,B,C,n);

    printf("Result matrix:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%d ",C[i][j]);
        printf("\n");
    }
    return 0;
}