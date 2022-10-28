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
   // printf("%d\n", str1 -> position - str2 -> position);
    return *(str1.position) - *(str2.position);
}

/*static int str_cmp_reverse(struct string* str1, struct string* str2)
{
    size_t pos1 = strlen(str1);
    size_t pos2 = strlen(str2);

    while(*(str1 + pos1) == *(str2 +pos2))
    {
        if(pos2 < 1 || pos1 < 1)
            break;

        pos1--;
        pos2--;
    }

    return *(str1 + pos1) - *(str2 + pos2);
}*/

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
           if(str_cmp(*(strings + j), *(strings + j + 1)) > 0)
                change_str(strings + j, strings + j + 1);

    FILE* negry_pidorasy = fopen("negry_pidorasy.txt", "wb");
    for(int j = 0; j < n; j++)                                // для тестировки норм чтения начала строк
        fprintf(negry_pidorasy,"%p %d\n", strings[j].position, strings[j].length);
        fclose(negry_pidorasy);
}

/*void sort_n_str_reverse(struct string* strings, int n)
{
     for(int i = 0; i < n; i++)
        for(int j = 0; j < n - 1; j++)
            if(str_cmp_reverse(strings[j].position, strings[j+1].position) > 0))
}*/
