#include "sort_str.h"
#include "header.h"
#include <stdio.h>
#include <string.h>

int str_cmp(struct string str1, struct string str2)
{
    while(*(str1.position) == *(str2.position))
    {
        if(*(str1.position) == '\0')
            break;

        str1.position++;
        str2.position++;
    }
    return *(str1.position) - *(str2.position);
}

int str_cmp_reverse(struct string str1, struct string str2)
{
    int pos1 = str1.length;
    int pos2 = str2.length;
    while(*((str1.position) + pos1) == *((str2.position) + pos2))
    {
        if(pos1 < 1 || pos2 < 1)
            break;

        pos1--;
        pos2--;
    }
    return *((str1.position) + pos1) - *((str2.position) + pos2);
}

void change_str(struct string* s1, struct string* s2)
{
    char* buffer_position = s1 -> position;
    s1 -> position = s2 -> position;
    s2 -> position = buffer_position;
    int buffer_length = s1 -> length;
    s1 -> length = s2 -> length;
    s2 -> length = buffer_length;
}

void sort_n_str(struct string* strings, int n)
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n - 1; j++)
           if(str_cmp(*(strings + j), *(strings + j + 1)) > 0)
                change_str(strings + j, strings + j + 1);

    FILE* negry_pidorasy = fopen("negry_pidorasy.txt", "wb");
    for(int j = 0; j < n; j++)                                // для тестировки норм чтения начала строк
        fprintf(negry_pidorasy,"%p %d\n", strings[j].position, strings[j].length);
        fclose(negry_pidorasy);
}

void sort_n_str_reverse(struct string* strings, int n)
{
     for(int i = 0; i < n; i++)
        for(int j = 0; j < n - 1; j++)
           if(str_cmp_reverse(*(strings + j), *(strings + j + 1)) > 0)
                change_str(strings + j, strings + j + 1);

    FILE* churki_pidorasy = fopen("churki_pidorasy.txt", "wb");
    for(int j = 0; j < n; j++)                                // для тестировки норм чтения начала строк
        fprintf(churki_pidorasy,"%p %d\n", strings[j].position, strings[j].length);
        fclose(churki_pidorasy);
}
