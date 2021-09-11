/*
** EPITECH PROJECT, 2020
** string.h
** File description:
** string include
*/

#ifndef STRING_H
#define STRING_H

typedef struct s_string
{
    char *str;

    void (*init)(struct s_string *, const char *);
    void (*destroy)(struct s_string *);

    void (*assign_s)(struct s_string *, const struct s_string *);
    void (*assign_c)(struct s_string *, const char *);

    void (*append_s)(struct s_string *, const struct s_string *);
    void (*append_c)(struct s_string *, const char *);

    char (*at)(struct s_string *, size_t);
    void (*clear)(struct s_string *);
    int (*size)(const struct s_string *);

    int (*compare_s)(const struct s_string *, const struct s_string *);
    int (*compare_c)(const struct s_string *, const char *);
    size_t (*copy)(const struct s_string *, char *, size_t, size_t);
    const char *(*c_str)(const struct s_string *);
    int (*empty)(const struct s_string *);

    int (*find_s)(const struct s_string *, const struct s_string *, size_t);
    int (*find_c)(const struct s_string *, const char *, size_t);

    void (*insert_c)(struct s_string *, size_t, const char *);
    void (*insert_s)(struct s_string *, size_t, const struct s_string *);
    int (*to_int)(const struct s_string *);
} string_t;

// Create
void string_init(string_t *, const char *);
void string_destroy(string_t *);

// Asign
void assign_s(string_t *this, const string_t *str);
void assign_c(string_t *this, const char *str);

// Append
void append_s(string_t *this, const string_t *ap);
void append_c(string_t *this, const char *ap);

// At
char at(string_t *this, size_t pos);
void clear(string_t *this);
int size(const string_t *this);

// Copy/Compare
int compare_s(const string_t *this, const string_t *str);
int compare_c(const string_t *this, const char *str);
size_t copy(const string_t *this, char *s, size_t n, size_t pos);
const char *c_str(const string_t *this);
int empty(const string_t *this);

// Find
int find_s(const string_t *this, const string_t *str, size_t pos);
int find_c(const string_t *this, const char *str, size_t pos);

// Insert
void insert_c(string_t *this, size_t pos, const char *str);
void insert_s(string_t *this, size_t pos, const string_t *str);

// Utils
int to_int(const string_t *this);

#endif