#include "sort_str.h"
#include "header.h"
#include <stdio.h>    ////////////////
#include <assert.h>

int str_cmp(char* str1, char* str2)
{
    while(*str1 == *str2)
    {
        if(*str1 == '\0')
            break;

        str1++;
        str2++;
    }

    return *str1 - *str2;
}

void change_str(struct string* s1, struct string* s2)
{
    char* buffer_position = s1 -> position;
    s1 -> position = s2 -> position;
    s2 -> position = buffer_position;
    int buffer_length = s1 -> length;
    s1 -> length = s2 -> length;
    s2 -> length = buffer_length;
  /*  char* buffer = *s1;
    *s1 = *s2;
    *s2 = buffer;*/
}

void sort_n_str(struct string* strings, int n)
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n - 1; j++)
           if(str_cmp(strings[j].position, strings[j+1].position) > 0)
                change_str(strings + j, strings + j + 1);

    FILE* negry_pidorasy = fopen("negry_pidorasy.txt", "wb");
    for(int j = 0; j < n; j++)                                // для тестировки норм чтения начала строк
        fprintf(negry_pidorasy,"%p %d\n", strings[j].position, strings[j].length);
        fclose(negry_pidorasy);


}
