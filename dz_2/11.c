#include <stdio.h>

void convert();

int main(void)
{
    char c = getchar();
    if (c != '\n')
    {
        convert();
        printf("%c\n", c);
    }
    return 0;
}

void convert()
{
    char c = getchar();
    if (c != '\n')
    {
        convert();
        printf("%c", c);
    }
}