#include "text_reader.h"
#include "header.h"
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
    {
        *cur_position = '\0';
        *(cur_position-1) = '\n';
    }
    return i+1;
}

struct string* begin_of_str_position(char* text, const int SIZE_SYMBOLS, int* SIZE_LINES)
{
    *SIZE_LINES = num_of_lines(text);
    struct string* pos_and_len = (struct string*)calloc(*SIZE_LINES+1, sizeof(struct string));

    if(pos_and_len == nullptr)
    {
        printf("I can't numeric strings(((\n");
        return nullptr;
    }

    int cur_position = 0;
    pos_and_len -> position = text;
    int i = 1;
    int str_len = 0;

    for( ; cur_position < SIZE_SYMBOLS && i < *SIZE_LINES; cur_position++, str_len++)
    {
        if(*(text + cur_position) != '\0')
            continue;

        pos_and_len[i].position = text + cur_position + 1;
        pos_and_len[i-1].length = str_len;
        i++;

        str_len = 0;
    }
        //pos_and_len[i-1].position = text + cur_position + 1;
        pos_and_len[i].length = SIZE_SYMBOLS - cur_position;

   /* for(cur_position = strchr(text, '\0'); cur_position != nullptr && cur_position < text + SIZE_SYMBOLS;
        cur_position = strchr(cur_position + 1, '\0'), i++)
    {
        pos_and_len[i].position = cur_position + 1;

        //pos_and_len[i-1].length = strlen(pos_and_len[i-1].position);
        pos_and_len[i-1].length = (size_t)pos_and_len[i].position - (size_t)pos_and_len[i-1].position;
    }
      //  pos_and_len[i-1].length = strlen(pos_and_len[i-1].position);
        pos_and_len[i-1].length = (size_t)pos_and_len[i-1].position - (size_t)pos_and_len[i-2].position;*/

    FILE* zalupa = fopen("zalupa.txt", "w");
    for(int j = 0; j < i; j++)                                // для тестировки норм чтения начала строк
        fprintf(zalupa,"%p %d\n", pos_and_len[j].position, pos_and_len[j].length);
        fclose(zalupa);
    return pos_and_len;
}

/*int currLine = 1;
int strLen = 0;
int i = 0;
for ( ; i < charsCountInOnegin; ++i, ++strLen)
{
    if (ch != '\0')
        continue;

    strings[currLine].start = oneginString + i + 1;
    strings[currLine++].length = strLen;

    strLen = 0;
}*/
