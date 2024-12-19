#include <stdio.h>

unsigned long factorial(unsigned int start, unsigned int end);

int main(void)
{
    unsigned int n = 0;
    unsigned int k = 0;
    scanf("%u %u", &n, &k);

    unsigned long divisible = 0;
    unsigned long devider = 0;

    divisible = factorial(1 + k, n);
    devider = factorial(1, n - k);

    printf("%lu\n", divisible / devider);

    return 0;
}

unsigned long factorial(unsigned int start, unsigned int end)
{
    unsigned long f = 1;
    for (unsigned int i = start; i < end + 1; i++)
        f *= i;
    return f;
}