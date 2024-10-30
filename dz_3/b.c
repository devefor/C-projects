#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define IP_STORAGE "/tmp/ip_store.txt"

uint32_t input_ip(void);
void request(FILE* fl);
void check(uint8_t* ip_check, uint32_t numb, FILE* fl);

int main(void)
{
    FILE* fl = fopen(IP_STORAGE, "w+b");
    if (fl) {
        for (uint32_t i = 0; i < UINT32_MAX / 8; i++)
            putc(0, fl);
    } else {
        perror("Failed to open file");
        return -1;
    }
    fclose(fl);

    fl = fopen(IP_STORAGE, "r+b");
    if (fl) {
        uint32_t numb = 0;

        if (scanf("%u", &numb)) {
            while (numb--)
                request(fl);
        }
    } else {
        perror("Failed to open file");
        return -1;
    }
    fclose(fl);

    fl = fopen(IP_STORAGE, "rb");
    if (fl) {
        uint32_t numb = 0;
        if (scanf("%u", &numb)) {

            uint8_t ip_check[numb];
            memset(ip_check, '\0', numb);

            for (uint32_t i = 0; i < numb; i++)
                check(ip_check, i, fl);

            for (uint32_t i = 0; i < numb; i++)
                ip_check[i] == 1 ? printf("yes\n") : printf("no\n");
        }
    } else {
        perror("Failed to open file");
        return -1;
    }
    fclose(fl);

    return 0;
}

uint32_t input_ip(void)
{
    uint32_t ip_addr = 0;
    if (scanf("%hhu.%hhu.%hhu.%hhu", (uint8_t*)&ip_addr + 3, (uint8_t*)&ip_addr + 2,
            (uint8_t*)&ip_addr + 1, (uint8_t*)&ip_addr)
        != 4)
        return 0;
    return ip_addr;
}

void request(FILE* fl)
{
    uint32_t ip_addr = input_ip();
    fseek(fl, ip_addr / 8, SEEK_SET);

    uint8_t byte = 0;
    if (fread(&byte, 1, 1, fl) != 1)
        return;

    byte |= 1 << (ip_addr % 8);
    fseek(fl, ip_addr / 8, SEEK_SET);
    if (fwrite(&byte, 1, 1, fl) != 1)
        return;
}

void check(uint8_t* ip_check, uint32_t numb, FILE* fl)
{
    uint32_t ip_addr = input_ip();
    fseek(fl, ip_addr / 8, SEEK_SET);

    uint8_t byte = 0;
    if (fread(&byte, 1, 1, fl) == 1) {
        if (byte & (1 << (ip_addr % 8))) {
            ip_check[numb] = 1;
        }
    }
}