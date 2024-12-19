#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/*
Дан массив длины N чисел с плавающей запятой одинарной точности (float).
Массив упорядочен, но циклически сдвинут на k элементов вправо (k - неизвестно), например:
1 2 3 4 5 --> сдвиг на k=2 вправо --> 4 5 1 2 3
Далее на вход подаются M чисел.
Требуется указать их позиции в массиве начиная с 1, если числа в массиве не найдено, то вывести 0.
Учтите, что числа считаются равными, если их модули отличаются не более, чем на eps.

Формат входных данных:
10^(-6)<=eps<=10^(-3)
1<=N<=10^6
-10<=xi<=10
1<=M<=10^6
-10<=yi<=10
На вход:
1. eps (float)
2. Число N
3. N float-овых чисел через пробел (xi)
4. Число M
5. M float-овых чисел, каждый на новой строке (yi)

Выход:
M ответов, каждый на новой строке. Позиция в массиве, если число найдено, 0, если не найдено.
Сложность:
O(Mlog(N)) по времени и O(N) по памяти
*/

int32_t search_shift(int32_t N, float* array);
int32_t binary_search(float value, int32_t start, int32_t end, float eps, float* array);
void check_value(float value, int32_t shift, int32_t end, float eps, float* array);

int main(void)
{
    float eps = 0.0;
    if (scanf("%f", &eps) != 1)
        return -1;

    int32_t N = 0;
    if (scanf("%d", &N) != 1)
        return -1;

    float* sort_arr = (float*)malloc(N * sizeof(float));
    if (sort_arr == NULL)
        return -1;

    for (int32_t i = 0; i < N; i++) {
        float elemet = 0.0;
        if (scanf("%f", &elemet) != 1) {
            free(sort_arr);
            return -1;
        }
        sort_arr[i] = elemet;
    }

    int32_t shift = search_shift(N, sort_arr);

#ifdef OUTPUT
    printf("\nARRAY\n|");
    for (int32_t i = 0; i < N; i++)
        printf(" %f |", sort_arr[i]);
    putchar('\n');
    printf("%d\n\n", shift);
#endif

    int32_t M = 0;
    if (scanf("%d", &M) != 1) {
        free(sort_arr);
        return -1;
    }

    for (int32_t i = 0; i < M; i++) {
        float value = 0.0;
        if (scanf("%f", &value) != 1) {
            free(sort_arr);
            return -1;
        }

        check_value(value, shift, N, eps, sort_arr);
    }

    free(sort_arr);
    return 0;
}

// Находим насколько сдвинут массив (место минимального элемента)
int32_t search_shift(int32_t end, float* array)
{
    int32_t shift = 0;
    end--;
    while (shift < end) {
        int32_t center = shift + (end - shift) / 2;
        if (array[center] > array[end])
            shift = center + 1;
        else
            end = center;
    }
    return shift;
}

// Бинарный поиск в выделенной части массива
int32_t binary_search(float value, int32_t start, int32_t end, float eps, float* array)
{
    while (start <= end) {
        int32_t center = start + (end - start) / 2;
        if ((array[center] - value) <= eps && (array[center] - value) >= -eps) {
            return center;
        } else if (array[center] < value)
            start = center + 1;
        else
            end = center - 1;
    }

    return -1;
}

// Просматриваем в обоих частях массива
void check_value(float value, int32_t shift, int32_t end, float eps, float* array)
{
    int32_t summary = binary_search(value, 0, shift - 1, eps, array) + 1 + binary_search(value, shift, end - 1, eps, array) + 1;

    printf("%d\n", summary);
}