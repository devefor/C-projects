#include <stdio.h>

int main(void)
{
    unsigned int numb = 0;
    long uniq = 0;
    if (scanf("%u", &numb) == 1) {

    int digit = 0;
    while (numb--)
        if (scanf("%d", &digit) == 1) uniq ^= digit;
    }
    printf("%ld\n", uniq);
    return 0;
}