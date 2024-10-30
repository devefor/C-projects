#include <stdio.h>
#include <string.h>

#define BUF_SIZE 256

unsigned int amount_word(char *str);

int main(void)
{
    FILE *fl = fopen("lines.txt", "r");
    if (fl == NULL)
    {
        perror("Failed to open file");
        return -1;
    }

    unsigned int len_str = 0;
    char buf[BUF_SIZE] = "";
    char file_str[BUF_SIZE] = "";
    
    while(!feof(fl))
    {
        if (fgets(buf, BUF_SIZE, fl) == NULL) break;
        unsigned int temp_len = amount_word(buf);
        if (temp_len > len_str)
        {
            len_str = temp_len;
            strcpy(file_str, buf);
        }
        
    }

    puts(file_str);
    printf("%d\n", len_str);

    fclose(fl);
    
    return 0;
}

unsigned int amount_word(char *str)
{
    unsigned int len = 0;

    while(*str != '\n')
    {
        if (*str == ' ') len++;
        str++;
    }

    return len + 1;
}