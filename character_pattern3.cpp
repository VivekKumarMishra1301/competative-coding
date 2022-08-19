#include <stdio.h>
#include <stdlib.h>
int main()
{
    char x, y;
    printf("enter the character\n");
    int j = 1;
    while (j)
    {
        fflush(stdin);
        scanf("%c", &x);

        if (x >= 'A' && x <= 'Z' || x >= 'a' && x <= 'z')
        {

            j = 0;
        }
        else
        {

            printf("enter a valid character\n");
        }
    }
    printf("%d", x);
}