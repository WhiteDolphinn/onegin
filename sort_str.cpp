#include "sort_str.h"

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

void change_str(char** s1, char** s2)
{
    char* buffer = *s1;
    *s1 = *s2;
    *s2 = buffer;
}

void sort_n_str(char* text, char** positions)
{


}
