#include <stdio.h>

int main()
{
    int n, a, max = 0;
    printf("enter the number of terms :");
    scanf("%d", &n);
    printf("Enter the terms");
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a);
        if (a > max || i == 1)
        {
            max = a;
        }
    }
    printf("the max=%d", max);
}