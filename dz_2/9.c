#include <stdio.h>

int main(void)
{
    unsigned int numb = 0;
    scanf("%u", &numb);

    unsigned long factorial = 1;

    while (numb) factorial *= numb--;
    
    printf("%lu\n", factorial);
    return 0;
}