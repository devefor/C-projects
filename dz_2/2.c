#include <stdio.h>

int main(void)
{
    unsigned int numb = 0;
    scanf("%u", &numb);

    numb = ~numb;
    unsigned char shift = 0;

    while (numb) {
        numb <<= 1;
        shift++;
        if ((numb & 1 << 31) == 0)
            break;
    }

    if (shift == 32)
        printf("1\n");
    else
        printf("%u\n", numb >> shift);
    return 0;
}