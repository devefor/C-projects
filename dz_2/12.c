#include <stdio.h>
#include <stdint.h>

void order(uint32_t bracket, uint8_t amount, uint8_t numb_zero, uint8_t numb_unit, int8_t stage, uint32_t start_bracket);

int main(void)
{
    uint8_t numb = 0;
    if (scanf("%hhu", &numb)) {

        if (numb < 1 && numb > 9)
            return 0;

        uint32_t bracket = 0;
        uint32_t start = 0;
        for (int i = 0; i < numb; i++)
            start |= 0b10 << 2 * i;

        order(bracket, numb, 0, 0, 2 * numb - 1, start);
    }

    return 0;
}

void order(uint32_t bracket, uint8_t amount, uint8_t numb_zero, uint8_t numb_unit, int8_t stage, uint32_t start_bracket)
{
    if (numb_zero < numb_unit)
        order(bracket, amount, numb_zero + 1, numb_unit, stage - 1, start_bracket);

    if (numb_unit < amount) {
        bracket |= 1 << stage;
        order(bracket, amount, numb_zero, numb_unit + 1, stage - 1, start_bracket);
    }

    if (bracket >= start_bracket && stage == -1) {
        for (int i = 2 * amount - 1; i > -1; i--)
            if (bracket & 1 << i) putchar('{');
            else putchar('}');

        putchar('\n');
    }
}