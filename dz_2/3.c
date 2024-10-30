#include <stdio.h>

int main(void) {

    int numb;
    scanf("%d", &numb);

    int max_new, max_mean, max_old, min_new, min_old;

    max_new = max_mean = max_old = ~__INT_MAX__;
    min_new = min_old = __INT_MAX__;

    while (numb)
    {
        int digit = 0;
        scanf("%d", &digit);

        if (digit >= max_new)
        {
            max_old = max_mean;
            max_mean = max_new;
            max_new = digit;
        } 
        else if (digit >= max_mean) 
        {
            max_old = max_mean;
            max_mean = digit;
        }
        else if (digit > max_old) max_old = digit;

        if (digit <= min_new)
        {
            min_old = min_new;
            min_new = digit;
        }
        else if (digit < min_old) min_old = digit;
        numb--;
    }

    if (max_new * max_mean * max_old > max_new * min_new * min_old) printf("%d\n", max_new * max_mean * max_old);
    else printf("%d\n", max_new * min_new * min_old);
    return 0;
}