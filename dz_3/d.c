#include <stdio.h>

unsigned short check_string(unsigned char* string);
unsigned short check_column(unsigned char* column);
unsigned short check_square(unsigned char* square);

int main(void)
{
    unsigned char sudoku[9][9] = { 0 };

    char valid = 1;

    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++) {

            if (scanf("%hhu", &sudoku[i][j]) == 1) {
                if (sudoku[i][j] > 9) {
                    printf("invalid\n");
                    return 0;
                }
            }
        }

    for (int i = 0; i < 9; i++) {

        if (check_string(sudoku[i]) != 0x1FF) {
            valid = 0;
            break;
        }
    }

    if (valid == 1) {
        for (int i = 0; i < 9; i++) {

            if (check_column(&sudoku[0][i]) != 0x1FF) {
                valid = 0;
                break;
            }
        }
    }

    if (valid == 1) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {

                if (check_square(&sudoku[i * 3][j * 3]) != 0x1FF) {
                    valid = 0;
                    break;
                }
            }
        }
    }

    valid == 1 ? printf("valid\n") : printf("invalid\n");

    return 0;
}

unsigned short check_string(unsigned char* string)
{
    unsigned short result = 0;

    for (int i = 0; i < 9; i++) {
        result |= 1 << (string[i] - 1);
    }

    return result;
}

unsigned short check_column(unsigned char* column)
{
    unsigned short result = 0;

    for (int i = 0; i < 9; i++) {
        result |= 1 << (column[i * 9] - 1);
    }

    return result;
}

unsigned short check_square(unsigned char* square)
{
    unsigned short result = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result |= 1 << (square[j + i * 9] - 1);
        }
    }

    return result;
}
