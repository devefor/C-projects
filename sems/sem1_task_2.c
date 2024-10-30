#include <stdio.h>

int main(void)
{
    unsigned int literals = 0;
    unsigned int repestrs = 0;
    char c = '0';

    while ((c = getchar()) != '\n')
    {
        if ((c >= 97) && (c <= 122))        // В ASCII 97 - a, 122 - z
        {
            if (literals & 1 << (c - 97)) repestrs |= 1 << (c - 97);
            else literals |= 1 << (c - 97);
        }
    }

    for (char i = 0; i < 26; i++) if (!(repestrs & (1 << i)) && (literals & (1 << i))) printf("%c", i + 97);
    
    if (repestrs == literals) printf("N");

    return 0;
    
}