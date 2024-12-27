#include <stdio.h>
#include <stdint.h>

int main(void) {
    uint8_t step = 0;

    if (scanf("%hhu", &step) != 1)
        return  -1;

    uint32_t sposob = 0;
    if (step % 2 == 0)
        sposob += 2;
    else
        sposob++;

    for (uint8_t i = 1; i < (step + 1) / 2; i++) {
        sposob += step - i;
    }

    printf("%u\n", sposob);
    return 0;
}