#include "text_writer.h"

void text_writer(FILE* file, struct string* strings, int n)
{
    for(int i = 0; i < n; i++)
    {
            fprintf(file, "%s", strings[i].position);
    }

}
