#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
void pat(int n)
{
    if (n == 0)
    {
        return;
    }
    pat(n - 1);

    for (int i = 0; i < n; i++)
    {
        printf("*");
    }
    printf("\n");
}

int main()
{

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    scanf("%d", &n);

    pat(n);
    return 0;
}
