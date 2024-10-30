void* cool_memset(void* str, int c, unsigned long long n)
{
    unsigned char* pointer = (unsigned char*)str;

    for (unsigned long long i = 0; i < n; i++)
        pointer[i] = (unsigned char)c;

    return str;
}