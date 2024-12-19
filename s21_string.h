#ifndef S21_STRING_H_
#define S21_STRING_H_

#include <ctype.h>
#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long unsigned s21_size_t;
#define BUFF_SIZE 4000
#define s21_NULL ((void *)0)

char *s21_strtok(char *str, const char *delim);
void *s21_memchr(const void *str, int c, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
s21_size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
s21_size_t s21_strlen(const char *str);
char *s21_strchr(const char *str, int c);
char *s21_strerror(int errnum);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strrchr(const char *str, int c);
char *s21_strpbrk(const char *str1, const char *str2);
int s21_sprintf(char *str, char *format, ...);
void add_char(char *str, char *s, int *index);
void convert(int number, char str[], int base);
char *float_to_string(double num, int ciferki);
int ciferki1(char akukaku[]);
void noliki(char *num, int ciferki);
void plus(char buf[]);
void space(char buf[], int shift);
void flags(char format[], char *flag, int *i);
void space_1(char buf[], int shift);
void zero(char buf[]);
void case_d(int d, char flag, char num[], char akukaku[], char shirina[]);
char *case_f(double f, char flag, char akukaku[], char shirina[]);
void case_s(char *s, char flag, char shirina[], char akukaku[], char buffer[]);
void case_u(unsigned long int d, char flag, char num[], char akukaku[],
            char shirina[]);
void case_c(char buff[], char flag, char shirina[]);
void simple_strcpy(char *destination, const char *source);
void custom_copy(char *buffer, const char *num, int zeros, int len);
void tochnost(char format[], char akukaku[], char shirina[], int *i, char *flag,
              int *check);
void percent(char str[], char buf[], int len, int *index);
void accuracy(char *s, int ciferki);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);
void *s21_to_lower(const char *str);
void *s21_trim(const char *src, const char *trim_chars);
void *s21_to_upper(const char *str);

#endif  // S21_STRING_H_
