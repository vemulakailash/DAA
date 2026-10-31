#include <stdio.h>

int switches[100];

void toggle(int i)
{
    switches[i] = 1 - switches[i];
}

void solve(int n)
{
    if (n == 0)
        return;

    if (n == 1)
    {
        toggle(0);
        return;
    }

    solve(n - 1);
    toggle(n - 1);
    solve(n - 1);
}

int main()
{
    int n;

    printf("Enter number of switches: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Invalid input\n");
        return 0;
    }

    for (int i = 0; i < n; i++)
        switches[i] = 1;

    solve(n);

    printf("Final switch states:\n");

    for (int i = 0; i < n; i++)
        printf("%d ", switches[i]);

    printf("\n");

    int successful = 1;

    for (int i = 0; i < n; i++)
    {
        if (switches[i] != 0)
            successful = 0;
    }

    if (successful)
        printf("Validation successful: all switches are OFF.\n");
    else
        printf("Validation failed.\n");

    return 0;
}