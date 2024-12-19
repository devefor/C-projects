#include <stdio.h>

void Fib(unsigned long int now, unsigned long int next, int numb);

int main(void)
{
    int numb = 0;
    scanf("%d", &numb);

    Fib(0, 1, numb);

    return 0;
}

void Fib(unsigned long int now, unsigned long int next, int numb)
{
    if (numb > 1) {
        Fib(next, now + next, numb - 1);
        printf(" ");
    }

    printf("%ld", now);
}