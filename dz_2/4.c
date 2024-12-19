#include <stdint.h>
#include <stdio.h>

int main(void)
{
    uint32_t numb = 0;
    scanf("%u", &numb);

    int32_t buy = 10001;
    int32_t sale = 0;

    while (numb--) {
        int32_t digit = 0;
        scanf("%d", &digit);

        if (digit < buy)
            buy = digit;
        else if (digit - buy > sale)
            sale = digit - buy;
    }

    if (sale > 0)
        printf("%d\n", sale);
    else
        putchar('0');
    return 0;
}