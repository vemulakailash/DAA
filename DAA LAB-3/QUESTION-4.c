#include<stdio.h>
void add(int A[10][10],int B[10][10],int C[10][10],int n)
{
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            C[i][j]=A[i][j]+B[i][j];
}
void sub(int A[10][10],int B[10][10],int C[10][10],int n)
{
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            C[i][j]=A[i][j]-B[i][j];
}
void strassen(int A[10][10],int B[10][10],int C[10][10],int n)
{
    int i,j,k,m;
    int A11[10][10],A12[10][10],A21[10][10],A22[10][10];
    int B11[10][10],B12[10][10],B21[10][10],B22[10][10];
    int M1[10][10],M2[10][10],M3[10][10],M4[10][10];
    int M5[10][10],M6[10][10],M7[10][10];
    int T1[10][10],T2[10][10];
    int C11[10][10],C12[10][10],C21[10][10],C22[10][10];

    if(n==1)
    {
        C[0][0]=A[0][0]*B[0][0];
        return;
    }

    m=n/2;

    for(i=0;i<m;i++)
        for(j=0;j<m;j++)
        {
            A11[i][j]=A[i][j];
            A12[i][j]=A[i][j+m];
            A21[i][j]=A[i+m][j];
            A22[i][j]=A[i+m][j+m];

            B11[i][j]=B[i][j];
            B12[i][j]=B[i][j+m];
            B21[i][j]=B[i+m][j];
            B22[i][j]=B[i+m][j+m];
        }
    add(A11,A22,T1,m);
    add(B11,B22,T2,m);
    strassen(T1,T2,M1,m);

    add(A21,A22,T1,m);
    strassen(T1,B11,M2,m);

    sub(B12,B22,T2,m);
    strassen(A11,T2,M3,m);

    sub(B21,B11,T2,m);
    strassen(A22,T2,M4,m);

    add(A11,A12,T1,m);
    strassen(T1,B22,M5,m);

    sub(A21,A11,T1,m);
    add(B11,B12,T2,m);
    strassen(T1,T2,M6,m);

    sub(A12,A22,T1,m);
    add(B21,B22,T2,m);
    strassen(T1,T2,M7,m);

    add(M1,M4,T1,m);
    sub(T1,M5,T2,m);
    add(T2,M7,C11,m);

    add(M3,M5,C12,m);
    add(M2,M4,C21,m);

    add(M1,M3,T1,m);
    sub(T1,M2,T2,m);
    add(T2,M6,C22,m);

    for(i=0;i<m;i++)
        for(j=0;j<m;j++)
        {
            C[i][j]=C11[i][j];
            C[i][j+m]=C12[i][j];
            C[i+m][j]=C21[i][j];
            C[i+m][j+m]=C22[i][j];
        }
}
int main()
{
    int A[10][10],B[10][10],C[10][10];
    int n,i,j;
    printf("Enter size of matrix: ");
    scanf("%d",&n);
    printf("Enter first matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&A[i][j]);
    printf("Enter second matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&B[i][j]);
    strassen(A,B,C,n);
    printf("Result matrix:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%d ",C[i][j]);
        printf("\n");
    }
    return 0;
}