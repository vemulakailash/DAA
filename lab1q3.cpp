#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int bubbleModified(int a[], int n)
{
    int comp = 0, temp, swapped;
    for (int i = 0; i < n - 1; i++)
    {
        swapped = 0;
        for (int j = 0; j < n - i - 1; j++)
        {
            comp++;
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                swapped = 1;
            }
        }
        if (swapped == 0)
            break;
    }
    return comp;
}
int bubbleNormal(int a[], int n)
{
    int comp = 0, temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            comp++;
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    return comp;
}
int main()
{
    FILE *fp = fopen("bubble_compare.dat", "w");
    srand(time(NULL));
    for (int n = 100; n <= 1000; n += 100)
    {
        int a[n], b[n];
        for (int i = 0; i < n; i++)
        {
            a[i] = rand() % 1000;
            b[i] = a[i];
        }
        int c1 = bubbleModified(a, n);
        int c2 = bubbleNormal(b, n);
        fprintf(fp, "%d %d %d\n", n, c1, c2);
        printf("N = %d  Modified = %d  Normal = %d\n", n, c1, c2);
    }
    fclose(fp);
    system("gnuplot -persist -e \"set title 'Bubble Sort Comparison'; \
               set xlabel 'Input Size'; \
               set ylabel 'Comparisons'; \
             plot 'bubble_compare.dat' using 1:2 with linespoints lw 2 title 'Modified Bubble', \
             'bubble_compare.dat' using 1:3 with linespoints lw 2 title 'Normal Bubble'\"");
    return 0;
}
