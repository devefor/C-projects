#include <stdio.h>
#include "sentence_counter.h"

/**
 * @brief Reads sentences from a file and write them in lines.
 * 
 * Function read file line by line and parses sentences.
 * Result of parse write in lines array.
 * 
 * @param filename The name of text file to read.
 * @param lines Char array for write in them parses sentences. Each row contain one sentence.
 * 
 * @return 0 if success, -1 if failure - file not found or read error.
 */
int read_lines(const char *filename, char lines[256][256])
{
    FILE *fl = fopen(filename, "r");
    if (fl == NULL)
        return 1;
    
    int id_sentence = 0;
    int id_symbol = 0;
    char symbol;
    while ((symbol = fgetc(fl)) != EOF) {
        if (symbol == '.') {
            if (id_symbol > 0) {
                lines[id_sentence++][id_symbol] = '\0';
                if (id_sentence > 255) {
                    fclose(fl);
                    return 2;
                }
            }
            id_symbol = 0;
        }
        else {
            if (id_symbol < 255) {
                lines[id_sentence][id_symbol++] = symbol;
            }
            else {
                fclose(fl);
                return 3;
            }
        }
    }

    if (id_symbol > 0 && id_symbol < 256)
        lines[id_sentence][id_symbol] = '\0';
    
    fclose(fl);
    return 0;
}