#include <stdio.h>
#include <string.h>

#define BUF_SIZE 256

unsigned int amount_word(char *str, FILE *fl);

int main(void)
{
    FILE *fl = fopen("text.txt", "r");
    if (fl == NULL)
    {
        perror("Failed to open file");
        return -1;
    }

    unsigned int len_str = 0;

    char buf[BUF_SIZE] = "";
    char sentence[BUF_SIZE] = "";

    while(1)
    {
        unsigned int temp_len = amount_word(buf, fl);
        if (temp_len == 0)
            break;
        
        if (temp_len > len_str)
        {
            len_str = temp_len;
            strcpy(sentence, buf);
        }
    }

    puts(sentence);
    printf("%u\n", len_str);

    fclose(fl);

    return 0;
}

unsigned int amount_word(char *str, FILE *fl)
{
    unsigned int len = 0;
    char end[2] = "";
    unsigned char i = 0;

    while((end[1] != EOF) && (strcmp(end, ".\n") != 0) && (strcmp(end, ". ") != 0))
    {
        if (end[1] == ' ')
            len++;

        end[0] = end[1];
        end[1] = getc(fl);

        if (end[1] == EOF) break;

        str[i++] = end[1];
    }

    if (str[i-1] != '.')
        str[i-1] = '\0';

    if (end[1] == EOF && i == 0)
        return 0;

    return len + 1;
}