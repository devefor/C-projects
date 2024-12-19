#include <stdint.h>
#include <stdio.h>

int main(void)
{
    uint64_t str = 0;
    int8_t c = 0;
    uint32_t word = 0;

    uint16_t sum = 0;

    while ((c = getchar()) != '\n') {
        str |= 1 << (c - 97);
    }

    while ((c = getchar()) != '\0') {
        if (c == '\n' || c == ' ') {
            if (str == word)
                sum += 1;
            word = 0;
            if (c == '\n')
                break;
        } else
            word |= 1 << (c - 97);
    }

    printf("%hu\n", sum);
    return 0;
}