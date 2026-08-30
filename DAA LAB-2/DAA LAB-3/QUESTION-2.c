#include <stdio.h>
int findDefective(int a[], int l, int r)
{
    if(l == r)
        return l;

    int mid = (l + r) / 2;

    if(a[l] == a[mid])
        return findDefective(a, mid + 1, r);
    else
        return findDefective(a, l, mid);
}
int main()
{
    int a[100], n, i, pos;
    printf("Enter number of coins: ");
    scanf("%d", &n);
    printf("Enter coin weights:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    pos = findDefective(a, 0, n - 1);
    if(a[pos] < a[0])
        printf("Defective coin is at position %d\n", pos + 1);
    else
        printf("No defective coin\n");
    return 0;
}