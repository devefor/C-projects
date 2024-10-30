#include <stdio.h>
#include <string.h>

void check_buffer(char* buf, int numb, char* clear_buf, int* numb_str);

int main(void)
{
    char buf[256] = { 0 };

    char palindrom[256] = { 0 };
    int pals = 0;

    while (!feof(stdin)) {
        if (fgets(buf, 256, stdin) == NULL)
            break;

        int numb = strlen(buf);
        char clear_buf[256] = { 0 };
        int numb_str = 0;

        check_buffer(buf, numb, clear_buf, &numb_str);

        for (int i = 0; i < numb_str / 2; i++) {
            if (clear_buf[i] != clear_buf[numb_str - (i + 1)]) {
                palindrom[pals] = 1;
                break;
            }
        }

        pals++;
    }

    char amount = 0;
    for (int i = 0; i < pals; i++)
        if (palindrom[i] == 0)
            amount++;

    printf("%hhd\n", amount);

    char pal_exist = 0;
    for (int i = 0; i < pals; i++) {
        if (palindrom[i] == 0) {
            if (pal_exist)
                putchar(' ');
            printf("%d", i);
            pal_exist = 1;
        }
    }

    putchar('\n');

    return 0;
}

void check_buffer(char* buf, int numb, char* clear_buf, int* numb_str)
{
    for (int i = 0; i < numb; i++) {
        // 0 - 9 | a -z
        if ((buf[i] >= 48 && buf[i] <= 57) || (buf[i] >= 97 && buf[i] <= 122)) {
            clear_buf[*numb_str] = buf[i];
            (*numb_str)++;
            continue;
        }
        // A - Z
        if (buf[i] >= 65 && buf[i] <= 90) {
            clear_buf[*numb_str] = buf[i] + 32;
            (*numb_str)++;
        }
    }
}