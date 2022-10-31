#include "sort_str.h"
#include "header.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int str_cmp(struct string str1, struct string str2)
{
    while(!isalnum(*(str1.position)) && *(str1.position) != '\0')
        str1.position++;

    while(!isalnum(*(str2.position)) && *(str2.position) != '\0')
        str2.position++;


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

    while(isalnum(*(str1.position + pos1)) == 0 && pos1 > 0)
        pos1--;

    while(isalnum(*(str2.position + pos2)) == 0 && pos2 > 0)
        pos2--;

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
    string temp = *s1;
    *s1 = *s2;
    *s2 = temp;
}

void sort_n_str(struct string* strings, int n)
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n - 1; j++)
           if(str_cmp(*(strings + j), *(strings + j + 1)) > 0)
                change_str(strings + j, strings + j + 1);

    if(DEBUG == 1)
    {
    FILE* negry_pidorasy = fopen("negry_pidorasy.txt", "wb");
    for(int j = 0; j < n; j++)                                // для тестировки норм чтения начала строк
        fprintf(negry_pidorasy,"%p %d\n", strings[j].position, strings[j].length);
        fclose(negry_pidorasy);
    }
}

void sort_n_str_reverse(struct string* strings, int n)
{
     for(int i = 0; i < n; i++)
        for(int j = 0; j < n - 1; j++)
           if(str_cmp_reverse(*(strings + j), *(strings + j + 1)) > 0)
                change_str(strings + j, strings + j + 1);

    if(DEBUG == 1)
    {
    FILE* churki_pidorasy = fopen("churki_pidorasy.txt", "wb");
    for(int j = 0; j < n; j++)                                // для тестировки норм чтения начала строк
        fprintf(churki_pidorasy,"%p %d\n", strings[j].position, strings[j].length);
        fclose(churki_pidorasy);
    }
}
