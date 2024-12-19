#include <stdio.h>

#define ALFABET 26

void check_letter(char c, unsigned short* literals);
void print_amount_literals(unsigned short* literals);

int main(void)
{
    FILE* fl = fopen("lines.txt", "r");
    if (fl == NULL) {
        perror("Failed to open file");
        return -1;
    }

    unsigned short literals[ALFABET] = { 0 };
    char c = '\0';

    while (!feof(fl)) {
        c = getc(fl);
        check_letter(c, literals);
    }

    print_amount_literals(literals);

    fclose(fl);

    return 0;
}

void check_letter(char c, unsigned short* literals)
{
    if ((c >= 65) && (c <= 90)) // В ASCII 65 - A, 90 - Z
        literals[c - 'A']++;

    if ((c >= 97) && (c <= 122)) // В ASCII 97 - a, 122 - z
        literals[c - 'a']++;
}

void print_amount_literals(unsigned short* literals)
{
    for (int i = 0; i < ALFABET; i++) {
        printf("%c: %d\n", i + 'a', literals[i]);
    }
}