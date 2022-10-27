#include <stdio.h>
#include <locale.h>
#include <malloc.h>
#include "text_reader.h"
#include "sort_str.h"
#include "header.h"


int main()
{
    setlocale(LC_ALL, "");
    const char* name_of_file = "onega.txt";
    FILE* onegin = fopen(name_of_file, "rb");
    FILE* onegin2 = fopen("bebra.txt", "wb");
    char* text = text_reader(onegin, name_of_file);
    fclose(onegin);
    struct string* strings = begin_of_str_position(text, num_of_symbols(name_of_file));
  //  fprintf(onegin2,"%s", text);
    fclose(onegin2);
    free(text);
    free(strings);       ///////////////////
    return 0;
}

