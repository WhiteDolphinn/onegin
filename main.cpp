#include <stdio.h>
#include <locale.h>
#include <malloc.h>
#include "text_reader.h"
#include "sort_str.h"
#include "header.h"
#include "text_writer.h"
#include <stdlib.h>


int main()
{
    setlocale(LC_ALL, "");

    const char* name_of_file = "onega.txt";
    FILE* onegin = fopen(name_of_file, "rb");
    FILE* onegin2 = fopen("bebra.txt", "w");
    FILE* onegin3 = fopen("sort_rev.txt", "w");

    char* text = text_reader(onegin, name_of_file);
    fclose(onegin);

    int SIZE_LINES = 0;

    struct string* strings = begin_of_str_position(text, num_of_symbols(name_of_file), &SIZE_LINES);

    sort_n_str(strings, SIZE_LINES);
    text_writer(onegin2, strings, SIZE_LINES);

    sort_n_str_reverse(strings, SIZE_LINES);
    text_writer(onegin3, strings, SIZE_LINES);

    fclose(onegin2);
    free(text);
    free(strings);
    return 0;
}

