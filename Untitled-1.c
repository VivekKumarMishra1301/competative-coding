#include <stdio.h>
#include <stdlib.h>
int main()
{
    char x, y;
    printf("enter the character\n");

    while (1)
    {
        fflush(stdin);
        scanf("%c", &x);

        if (x >= 'A' || x <= 'Z' || x >= 'a' || x <= 'z')
        {
            y = x;
            exit(1);
        }
        else
        {
            printf("enter a valid character\n");
        }
    }
    printf("%d", y);
}