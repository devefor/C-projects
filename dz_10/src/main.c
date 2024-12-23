#include <stdio.h>
#include "sentence_counter.h"

int main(int argc, char* argv[])
{
    if (argc != 2) {
        printf("FILE NOT SPECIFIED\n");
        return -1;
    }

    const char* filename = argv[1];
    char sentence[256] = { '\0' };
    int number = longest_sentence_in_file(filename, sentence);
    if (number == -1) {
        printf("READ FILE: %s - ERROR\n", filename);
        perror("");
        return -1;
    }
    
    printf("Longest sentence in %s:\n%s\n", filename, sentence);
    printf("Sentences has %d words.\nNumber sentece is %d", count_words(sentence), number);
    return 0;
}