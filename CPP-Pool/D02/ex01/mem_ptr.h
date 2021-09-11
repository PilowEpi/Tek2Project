#ifndef MEMPT_H
#define MEMPT_H

typedef struct s_str_op
{
    char *str1;
    char *str2;
    char *res;
}str_op_t;


void add_str(const char *str1, const char *str2, char **res);
void add_str_struct(str_op_t *str_op);

#endif