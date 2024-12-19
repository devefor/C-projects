#include <stdio.h>

int main(void)
{
    unsigned long int numb = 0;
    int count = 0;

    scanf("%ld", &numb);

    printf("0x%lx%n\n", numb, &count);

    printf("%d", count);

    return 0;
}
