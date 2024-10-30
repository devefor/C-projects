int* cool_int_arr_dup(const int* arr, unsigned long long size, void* (*malloc_func)(unsigned long long num))
{
    int* duplicate = (int*)malloc_func(sizeof(int) * size);
    if (duplicate == (void*)0)
        return (void*)0;

    while (size) {
        size--;
        duplicate[size] = arr[size];
    }

    return duplicate;
}