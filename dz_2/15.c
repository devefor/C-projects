#include <stdio.h>

int main(void)
{
    int numb = 0;
    scanf("%d", &numb);

    for (int i = 1; i < numb + 1; i++) {
        for (int j = i; j < numb; j++)
            putchar('0');
        for (int j = i; j > 0; j--)
            putchar('1');
        putchar('\n');
    }

    return 0;
}