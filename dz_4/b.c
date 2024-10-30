const char* cool_strstr(const char* str1, const char* str2)
{
    if (*str2 == '\0')
        return str1;

    while (*str1 != '\0') {
        if (*str1 == *str2) {
            const char* string_1 = str1;
            const char* string_2 = str2;

            while (*(string_1++) == *(string_2++))
                if (*string_2 == '\0')
                    return str1;
        }
        str1++;
    }
    return (void*)0;
}