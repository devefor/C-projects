#include <stdio.h>

int main(void)
{
    int numb = 0;
    scanf("%d", &numb);


    for (int i = 1; i < numb + 1; i++)
    {
        for (int j = i; j < numb; j++) putchar('.');
        for (int j = 2 * i - 1; j > 0; j--) putchar('*');
        for (int j = i; j < numb; j++) putchar('.');
        putchar('\n');
    }
    
    return 0;
}