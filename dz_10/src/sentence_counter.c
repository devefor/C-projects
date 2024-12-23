#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "sentence_counter.h"

static bool is_char(char c)
{
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

/**
 * @brief Counts number of words in sentences.
 * 
 * Word is a sequence consist of Latin letter A-Z, a-z, separated by spaces or sign punctuation.
 * 
 * @param sentence Arary of chars send to analyze.
 * 
 * @return Number of words in senteces.
 */
int count_words(const char sentence[256])
{
    int count = 0;
    bool word = false;
    
    for (int i = 0; sentence[i] != '\0'; i++) {
        if (is_char(sentence[i])) {
            if (!word) {
                count++;
                word = true;
            }
        }
        else {
            word = false;
        }
    }

    return count;
}

/**
 * @brief Find the longest sentences in the text file.
 * 
 * Function read text file, definition the longest sentences.
 * 
 * @param filename The name of text file to read.
 * @param longest_sentence Array of char containing the longest sentence.
 * 
 * @return Number of longest sentence in file, -1 if failure - read file error.
 */
int longest_sentence_in_file(const char *filename, char longest_sentence[256])
{
    char lines[256][256] = { '\0' };
    int res = read_lines(filename, lines);
    if (res != 0)
        return -1;

    int max_words = 0;
    int number_sentence = 0;
    for (int i = 0; i < 256 && lines[i][0]; i++) {        
        int words_in_sentence = count_words(lines[i]);
        if (words_in_sentence > max_words) {
            max_words = words_in_sentence;
            number_sentence = i;
            strncpy(longest_sentence, lines[i], 256);
        }
    }

    return number_sentence;
}