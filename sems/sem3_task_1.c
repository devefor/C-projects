#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    int sum = 0;
    while (argc--)
        sum += atoi(*(argv + argc));

    printf("%d", sum);
    return 0;
}