#include <stdio.h>

int main(void)
{
    unsigned short numb = 0;
    unsigned int capacity = 0;

    unsigned long sum = 0;

    if (scanf("%hu", &numb))
        if (scanf("%u", &capacity)) {

            unsigned int water = capacity;
            for (size_t i = 0; i < numb; i++) {

                unsigned int plant = 0;
                if (scanf("%u", &plant)) {

                    if (water >= plant) {
                        sum += 1;
                        water -= plant;
                    } else {
                        water = capacity;
                        water -= plant;
                        sum += i + i + 1;
                    }
                }
            }
        }

    printf("%lu\n", sum);
    return 0;
}