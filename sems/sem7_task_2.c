void* cool_memmove(void* dest, const void* src, unsigned long long bytes)
{
    unsigned char* destination = (unsigned char*)dest;
    const unsigned char* source = (const unsigned char*)src;
    
    if (destination == source)
        return dest;
    
    if (destination > source) {
        for (unsigned long long i = bytes; i > 0; i--)
        destination[i - 1] = source[i - 1];
    }
    else {
        for (unsigned long long i = 0; i < bytes; i++)
        destination[i] = source[i];
    }

    return dest;
}