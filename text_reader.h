#ifndef TEXT_READER_H
#define TEXT_READER_H
#include <stdio.h>

int num_of_symbols(const char* name_of_file);
char* text_reader(FILE* onegin, const char* name_of_file);
int num_of_lines(char* text);
struct string* begin_of_str_position(char* text, const int SIZE_SYMBOLS);
#endif
