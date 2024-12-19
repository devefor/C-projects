#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void read_array(char* array, unsigned int length);
void shift_array(char* array, unsigned int length, unsigned int shift);
void print_array(char* array, unsigned int length);

int main(void)
{
    unsigned int numb, shift;
    numb = shift = 0;

    if (scanf("%u %u", &numb, &shift)) {
        char arr[numb];
        memset(arr, '\0', numb);

        read_array(arr, numb);
        shift_array(arr, numb, shift);
        print_array(arr, numb);
    }

    return 0;
}

void read_array(char* array, unsigned int length)
{
    for (size_t i = 0; i < length; i++) {
        char digit = 0;
        if (scanf("%hhd", &digit))
            array[i] = digit;
    }
}

void shift_array(char* array, unsigned int length, unsigned int shift)
{
    shift %= length;
    char temp_array[length];

    memcpy(temp_array, array, length);
    memcpy(array, &temp_array[shift], length - shift);
    memcpy(array + (length - shift), temp_array, shift);
}

void print_array(char* array, unsigned int length)
{
    if (length > 1) {
        for (size_t i = 0; i < length - 1; i++)
            printf("%hhd ", array[i]);
    }
    printf("%hhd\n", array[length - 1]);
}