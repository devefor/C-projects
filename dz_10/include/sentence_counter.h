#ifndef SENTENCE_COUNTER_H
#define SENTECE_COUNTER_H

int read_lines(const char *filename, char lines[256][256]);
int count_words(const char sentence[256]);
int longest_sentence_in_file(const char *filename, char longest_sentence[256]);

#endif