#include <stdio.h>
#include <string.h>

void read_array(short* array, unsigned int length);
void convert_array(short* array, unsigned int length);
void print_array(short* array, unsigned int length);

int main(void)
{
    unsigned int numb = 0;

    if (scanf("%u", &numb)) {
        short digits[numb];
        memset(digits, '\0', numb);

        read_array(digits, numb);
        convert_array(digits, numb);
        print_array(digits, numb);
    }

    return 0;
}

void read_array(short* array, unsigned int length)
{
    for (size_t i = 0; i < length; i++) {
        short digit = 0;
        if (scanf("%hd", &digit)) {
            array[i] = digit;
        }
    }
}

void convert_array(short* array, unsigned int length)
{
    for (size_t i = 0; i < length / 2; i++) {
        short element = array[length - (i + 1)];
        array[length - (i + 1)] = array[i];
        array[i] = element;
    }
}

void print_array(short* array, unsigned int length)
{
    if (length > 1) {
        for (size_t i = 0; i < length - 1; i++) {
            printf("%hd ", array[i]);
        }
    }
    printf("%hd\n", array[length - 1]);
}
