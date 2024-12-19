#include <stdio.h>

int main(void)
{
    unsigned int numBottles = 0;
    unsigned int numExchange = 0;
    scanf("%u %u", &numBottles, &numExchange);

    unsigned char drink = 0;
    unsigned char remain = 0;
    while (numBottles) {
        drink += numBottles;
        numBottles += remain;
        remain = numBottles % numExchange;
        numBottles /= numExchange;
    }

    printf("%d\n", drink);
    return 0;
}
