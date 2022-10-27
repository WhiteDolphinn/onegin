#include "text_reader.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <malloc.h>

int num_of_symbols(const char* name_of_file)
{
    struct stat st = {};
    if (stat(name_of_file, &st) == -1)
        return -1;

    return st.st_size;
}

char* text_reader(FILE* onegin, const char* name_of_file)
{
    const int SIZE = num_of_symbols(name_of_file);
    char* text = (char*)calloc(SIZE+1, sizeof(char));

    if(text == nullptr)
    {
        printf("I can't read this file(((\n");
        return nullptr;
    }
    int size_text = fread(text, sizeof(char), SIZE, onegin);

    char* temp = (char*)realloc(text, sizeof(char) * size_text);

    if(temp == nullptr)
    {
        printf("I can't read this text((((\n");
        return nullptr;
    }

    text = temp;
    return text;
}

int num_of_lines(char* text)
{
    char* cur_position = nullptr;
    int i = 0;
    for(cur_position = strchr(text, '\n'); cur_position != nullptr; cur_position = strchr(cur_position + 1, '\n'), i++)
        *cur_position = '\0';
    return i+1;
}

char** begin_of_str_position(char* text, const int SIZE_SYMBOLS)
{
    printf("%d\n", SIZE_SYMBOLS);
    const int SIZE_LINES = num_of_lines(text);
    char** positions = (char**)calloc(SIZE_LINES+1, sizeof(char*));

    if(positions == nullptr)
    {
        printf("I can't numeric strings(((\n");
        return nullptr;
    }

    char* cur_position = 0;
    *positions = text;
    int i = 1;

    for(cur_position = strchr(text, '\0'); cur_position != nullptr && cur_position < text + SIZE_SYMBOLS;      //yhtht
        cur_position = strchr(cur_position + 1, '\0'), i++)
    {
        *(positions + i) = cur_position + 1;
    }

    FILE* zalupa = fopen("zalupa.txt", "w");
    for(int j = 0; j < i; j++)
        fprintf(zalupa,"%p\n", *(positions + j));
        fclose(zalupa);
    return positions;
}