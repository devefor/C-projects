#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 10000

int main(void)
{
    char read_str[MAX_LEN + 1] = { 0 };
    unsigned short info_length[MAX_LEN + 1][2] = { 0 };
    char info_letter[128][2] = { 0 };

    unsigned short amount_input = 0;

    if (scanf("%hu\n", &amount_input) != 0) {
        for (unsigned short i = 0; i < amount_input; i++) {
            if (fgets(read_str, MAX_LEN, stdin) != NULL) {

                unsigned int length = strlen(read_str) - 1;
                if (length > MAX_LEN || length == 0)
                    continue;
                
                if (read_str[length] == '\n')
                    read_str[length] = 0;
                
                unsigned int j = 0;
                while (j < 10001) {
                    if (read_str[j] < 32 || read_str[j] > 126)
                        break;
                    j++;
                }

                if (j < (length - 1))
                    continue;                   
                    
                length--;
                if (info_length[length][0] == 0)
                    info_length[length][0] = i + 1;
                info_length[length][1]++;

                unsigned char letter = read_str[0] - 32;
                if (info_letter[letter][0] == 0)
                    info_letter[letter][0] = i + 1;
                info_letter[letter][1]++;
            }
        }
    }

    if (scanf("%hu\n", &amount_input) != 0) {
        for (unsigned short i = 0; i < amount_input; i++) {
            if (fgets(read_str, MAX_LEN, stdin) != NULL) {

                char symbol = read_str[0];
                char* number_letter = read_str + 1;

                if (symbol == 'S') {
                    unsigned int length = (unsigned int)atoll(number_letter) - 1;
                    if (length > 0 && length <= MAX_LEN)
                        if ((info_length[length][0] != 0))
                            printf("%d,%d\n", info_length[length][0], info_length[length][1]);
                        else
                            printf("NO!\n");  
                    else
                        printf("NO!\n");
                } else if (symbol == 'L') {
                    unsigned char letter = (unsigned char)number_letter[0];
                    if (letter >= 32 && letter <= 126)
                        if (info_letter[letter - 32][0] != 0)
                            printf("%d,%d\n", info_letter[letter - 32][0], info_letter[letter - 32][1]);
                        else    
                            printf("NO!\n");
                    else    
                        printf("NO!\n");
                }
            }
        }
    }
    return 0;
}
