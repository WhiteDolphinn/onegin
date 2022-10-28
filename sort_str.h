#ifndef SORT_STR_H
#define SORT_STR_H
int str_cmp(struct string str1, struct string str2);
int str_cmp_reverse(struct string str1, struct string str2);
void change_str(struct string* s1, struct string* s2);
void sort_n_str(struct string* strings, int n);
void sort_n_str_reverse(struct string* strings, int n);
#endif
