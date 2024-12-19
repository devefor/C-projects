#include <stdint.h>
#include <stdio.h>

int main(void)
{
    uint32_t numb = 0;
    scanf("%u", &numb);

    uint16_t rigth = numb & 0xFFFF;
    uint16_t left = 0;
    numb = numb >> 16;
    for (uint8_t i = 0; i < 16; i++) {
        left = (left << 1) | (numb & 0x1);
        numb >>= 1;
    }

    if (rigth == left)
        printf("true\n");
    else
        printf("false\n");
    return 0;
}