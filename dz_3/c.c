#include <stdio.h>

size_t check_len(const char* str);
void delete_transfer(char* str);
char* my_strncat(char* dest, char* src, size_t n);

int main(void)
{
    char str_1[256] = { 0 };
    char str_2[256] = { 0 };

    if (fgets(str_1, 256, stdin) != NULL)
        delete_transfer(str_1);

    if (fgets(str_2, 256, stdin) != NULL)
        delete_transfer(str_2);

    size_t numb = 0;
    if (scanf("%zu", &numb) == 1) {
        my_strncat(str_1, str_2, numb);
        printf("%s\n", str_1);
    }

    return 0;
}

size_t check_len(const char* str)
{
    size_t len = 0;
    while (*(str++) != '\0')
        len++;

    return len;
}

void delete_transfer(char* str)
{
    size_t len = check_len(str);
    if (str[len - 1] == '\n')
        str[len - 1] = '\0';
}

char* my_strncat(char* dest, char* src, size_t n)
{
    if (n == 0)
        return dest;

    char* destination = dest;
    while (*destination != '\0')
        destination++;

    while (n > 0) {
        if (*src == '\0')
            break;

        *(destination++) = *(src++);
        n--;
    }
    *destination = '\0';

    return dest;
}