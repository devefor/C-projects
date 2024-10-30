#include <stdio.h>
#include <stdint.h>

int main(void)
{
    uint8_t previous = 0;
    uint8_t now = 0;

    int8_t c = '\0';
    while ((c = getchar()))
    {
        if (c >= 48 && c <= 57) now = now * 10 + (c - '0');
        else if ((c == 32 || c == '\n') && now)
        {
            if (previous >= now)
            {
                putchar('0');
                return 0;
            }   
            previous = now;
            now = 0;           
        }
        if (c == '\n') break;
    }

    putchar('1');
    return 0; 
}