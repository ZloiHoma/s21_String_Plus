#include <check.h>
#include <stdio.h>
#include <string.h>

#include "s21_string.h"

START_TEST(strlen_1) {
  char str[512] = "hello world";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(strlen_2) {
  char str[512] = "";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(strlen_3) {
  char str[512] = "qwerty";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(strlen_4) {
  char str[512] = "qwwwwww";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(strlen_5) {
  char str[512] = "q";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(memchr_1) {
  char *str = "qwerty";
  int c = 'q';
  s21_size_t n = 7;
  ck_assert_ptr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(memchr_2) {
  char *str = "qwerty";
  int c = 'q';
  s21_size_t n = 7;
  ck_assert_ptr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(memchr_3) {
  char *str = "qwerty";
  int c = 'd';
  s21_size_t n = 7;
  ck_assert_ptr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(memchr_4) {
  char *str = "qwerty";
  int c = 'w';
  s21_size_t n = 7;
  ck_assert_ptr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(memchr_5) {
  char *str = "qwerty";
  int c = 'w';
  s21_size_t n = 7;
  ck_assert_ptr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(memchr_6) {
  char *str = "qwerty";
  int c = 'w';
  s21_size_t n = 7;
  ck_assert_ptr_eq(memchr(str, c, n), s21_memchr(str, c, n));
}
END_TEST

START_TEST(memcmp_1) {
  char *str1 = "adewsfrgewefgsdg";
  char *str2 = "adsfrgewefgsdgde";
  s21_size_t n = 17;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_2) {
  char *str1 = "aaaaaaaaaaa";
  char *str2 = "adsfrgewefgsdg";
  s21_size_t n = 12;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_4) {
  char *str1 = "";
  char *str2 = "";
  s21_size_t n = 1;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_6) {
  char *str1 = "12345";
  char *str2 = "12345";
  s21_size_t n = 6;
  ck_assert_int_eq(memcmp(str1, str2, n), s21_memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcpy_1) {
  char dest[512] = "hello";
  char src[512] = "world";
  s21_size_t n = 512;
  ck_assert_ptr_eq(memcpy(dest, src, n), s21_memcpy(dest, src, n));
}
END_TEST

START_TEST(memcpy_2) {
  char dest[512] = "hello";
  char src[512] = "";
  s21_size_t n = 512;
  ck_assert_ptr_eq(memcpy(dest, src, n), s21_memcpy(dest, src, n));
}
END_TEST

START_TEST(memcpy_3) {
  char dest[512] = "";
  char src[512] = "hello";
  s21_size_t n = 512;
  ck_assert_ptr_eq(memcpy(dest, src, n), s21_memcpy(dest, src, n));
}
END_TEST

START_TEST(memcpy_4) {
  char dest[512] = "";
  char src[512] = "";
  s21_size_t n = 512;
  ck_assert_ptr_eq(memcpy(dest, src, n), s21_memcpy(dest, src, n));
}
END_TEST

START_TEST(memcpy_5) {
  char dest[512] = "123123123123";
  char src[512] = "123123123123";
  s21_size_t n = 512;
  ck_assert_ptr_eq(memcpy(dest, src, n), s21_memcpy(dest, src, n));
}
END_TEST

START_TEST(memset_1) {
  int c = 67;
  char str[] = "qwerty qwerty";
  s21_size_t n = 3;
  ck_assert_ptr_eq(memset(str, c, n), s21_memset(str, c, n));
}
END_TEST

START_TEST(memset_2) {
  int c = 67;
  char str[] = "qwerty qwerty";
  s21_size_t n = 3;
  ck_assert_ptr_eq(memset(str, c, n), s21_memset(str, c, n));
}
END_TEST

START_TEST(memset_3) {
  int c = 1;
  char str[] = "qwerty qwerty";
  s21_size_t n = 3;
  ck_assert_ptr_eq(memset(str, c, n), s21_memset(str, c, n));
}
END_TEST

START_TEST(memset_4) {
  int c = 90;
  char str[] = "qwerty qwerty";
  s21_size_t n = 3;
  ck_assert_ptr_eq(memset(str, c, n), s21_memset(str, c, n));
}
END_TEST

START_TEST(memset_5) {
  int c = 90;
  char str[] = "qwerty qwerty";
  s21_size_t n = 7;
  ck_assert_ptr_eq(memset(str, c, n), s21_memset(str, c, n));
}
END_TEST

START_TEST(memset_6) {
  int c = 90;
  char str[] = "qwerty qwerty";
  s21_size_t n = 0;
  ck_assert_ptr_eq(memset(str, c, n), s21_memset(str, c, n));
}
END_TEST

START_TEST(strchr_1) {
  char str[512] = "qwertyqwerty";
  int c = 'w';
  ck_assert_pstr_eq(strchr(str, c), s21_strchr(str, c));
}
END_TEST

START_TEST(strchr_2) {
  char str[512] = "qwertyqwerty";
  int c = 'q';
  ck_assert_pstr_eq(strchr(str, c), s21_strchr(str, c));
}
END_TEST

START_TEST(strchr_3) {
  char str[512] = "qqqqqqq";
  int c = 'q';
  ck_assert_pstr_eq(strchr(str, c), s21_strchr(str, c));
}
END_TEST

START_TEST(strchr_4) {
  char str[512] = "qqqqqqq";
  int c = 'w';
  ck_assert_pstr_eq(strchr(str, c), s21_strchr(str, c));
}
END_TEST

START_TEST(strchr_5) {
  char str[512] = "qqqqqqq";
  int c = 'q';
  ck_assert_pstr_eq(strchr(str, c), s21_strchr(str, c));
}
END_TEST

START_TEST(strchr_6) {
  char str[512] = "";
  int c = 'q';
  ck_assert_pstr_eq(strchr(str, c), s21_strchr(str, c));
}
END_TEST

START_TEST(strchr_7) {
  char str[512] = "qwerty";
  int c = 'y';
  ck_assert_pstr_eq(strchr(str, c), s21_strchr(str, c));
}
END_TEST

START_TEST(strcspn_1) {
  char s1[512] = "";
  char s2[512] = "";
  ck_assert_uint_eq(s21_strcspn(s1, s2), strcspn(s1, s2));
}
END_TEST

START_TEST(strcspn_2) {
  char *s1 = "qwertyqwerty";
  char *s2 = "qwe";
  ck_assert_uint_eq(s21_strcspn(s1, s2), strcspn(s1, s2));
}
END_TEST

START_TEST(strcspn_3) {
  char *s1 = "qwertyqwerty";
  char *s2 = "j";
  ck_assert_uint_eq(s21_strcspn(s1, s2), strcspn(s1, s2));
}
END_TEST

START_TEST(strcspn_4) {
  char *s1 = "MRBeast";
  char *s2 = "t";
  ck_assert_uint_eq(s21_strcspn(s1, s2), strcspn(s1, s2));
}
END_TEST

START_TEST(strcspn_5) {
  char *s1 = "MRBeast";
  char *s2 = "MRBeast";
  ck_assert_uint_eq(s21_strcspn(s1, s2), strcspn(s1, s2));
}
END_TEST

START_TEST(strcspn_6) {
  char *s1 = "MRBeast";
  char *s2 = "mrbeast";
  ck_assert_uint_eq(s21_strcspn(s1, s2), strcspn(s1, s2));
}
END_TEST

START_TEST(strcspn_7) {
  char *s1 = "how are u";
  char *s2 = " ";
  ck_assert_uint_eq(s21_strcspn(s1, s2), strcspn(s1, s2));
}
END_TEST

START_TEST(strcspn_8) {
  char *s1 = " ";
  char *s2 = "how are u";
  ck_assert_uint_eq(s21_strcspn(s1, s2), strcspn(s1, s2));
}
END_TEST

START_TEST(strncat_1) {
  char dest[512] = "hi ";
  char src[512] = "how are u";
  s21_size_t n = 10;
  ck_assert_str_eq(s21_strncat(dest, src, n), strncat(dest, src, n));
}
END_TEST

START_TEST(strncat_2) {
  char dest[512] = "";
  char src[512] = "how are u";
  s21_size_t n = 10;
  ck_assert_str_eq(s21_strncat(dest, src, n), strncat(dest, src, n));
}
END_TEST

START_TEST(strncat_3) {
  char dest[512] = "";
  char src[512] = "how are u";
  s21_size_t n = 3;
  ck_assert_str_eq(s21_strncat(dest, src, n), strncat(dest, src, n));
}
END_TEST

START_TEST(strncat_4) {
  char dest[512] = "";
  char src[512] = "how are u";
  s21_size_t n = 0;
  ck_assert_str_eq(s21_strncat(dest, src, n), strncat(dest, src, n));
}
END_TEST

START_TEST(strncat_5) {
  char dest[512] = "qqq";
  char src[512] = "qqq";
  s21_size_t n = 1;
  ck_assert_str_eq(s21_strncat(dest, src, n), strncat(dest, src, n));
}
END_TEST

START_TEST(strncat_6) {
  char dest[512] = "qqq";
  char src[512] = "qqq";
  s21_size_t n = 3;
  ck_assert_str_eq(s21_strncat(dest, src, n), strncat(dest, src, n));
}
END_TEST

START_TEST(strncmp_1) {
  char str1[512] = "qqq";
  char str2[512] = "qqq";
  s21_size_t n = 3;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_4) {
  char str1[512] = "";
  char str2[512] = "";
  s21_size_t n = 3;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_5) {
  char str1[512] = "";
  char str2[512] = "";
  s21_size_t n = 0;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncmp_7) {
  char str1[512] = "hello world";
  char str2[512] = "helloworld";
  s21_size_t n = 5;
  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(strncpy_1) {
  char dest[512] = "vfvfvf";
  char src[512] = "aqaqaq";
  s21_size_t n = 6;
  ck_assert_str_eq(s21_strncpy(dest, src, n), strncpy(dest, src, n));
}
END_TEST

START_TEST(strncpy_2) {
  char dest[512] = "vfvfvf";
  char src[512] = "aqaqaq";
  s21_size_t n = 5;
  ck_assert_str_eq(s21_strncpy(dest, src, n), strncpy(dest, src, n));
}
END_TEST

START_TEST(strncpy_3) {
  char dest[512] = "vfvfvf";
  char src[512] = "";
  s21_size_t n = 5;
  ck_assert_str_eq(s21_strncpy(dest, src, n), strncpy(dest, src, n));
}
END_TEST

START_TEST(strncpy_4) {
  char dest[512] = "";
  char src[512] = "vfvfvf";
  s21_size_t n = 5;
  ck_assert_str_eq(s21_strncpy(dest, src, n), strncpy(dest, src, n));
}
END_TEST

START_TEST(strncpy_5) {
  char dest[512] = "";
  char src[512] = "";
  s21_size_t n = 5;
  ck_assert_str_eq(s21_strncpy(dest, src, n), strncpy(dest, src, n));
}
END_TEST

START_TEST(strncpy_6) {
  char dest[512] = "hello";
  char src[512] = "world";
  s21_size_t n = 0;
  ck_assert_str_eq(s21_strncpy(dest, src, n), strncpy(dest, src, n));
}
END_TEST

START_TEST(strpbrk_1) {
  char str1[512] = "hello";
  char str2[512] = "world";
  ck_assert_str_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_2) {
  char str1[512] = "hello";
  char str2[512] = "hello";
  ck_assert_str_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_3) {
  char str1[512] = "hello";
  char str2[512] = "";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_4) {
  char str1[512] = "";
  char str2[512] = "world";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_5) {
  char str1[512] = "World";
  char str2[512] = "world";
  ck_assert_str_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(strpbrk_6) {
  char str1[512] = "World";
  char str2[512] = "qwe";
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
}
END_TEST

START_TEST(strrchr_1) {
  char str[512] = "World";
  int c = 'W';
  ck_assert_str_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(strrchr_2) {
  char str[512] = "World";
  int c = 'o';
  ck_assert_str_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(strrchr_3) {
  char str[512] = "World";
  int c = 'd';
  ck_assert_str_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(strrchr_4) {
  char str[512] = "";
  int c = 'f';
  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(strrchr_5) {
  char str[512] = "qwerty";
  int c = 'f';
  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(strrchr_6) {
  char str[512] = "f";
  int c = 'f';
  ck_assert_str_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(strstr_1) {
  char haystack[512] = "f";
  char needle[512] = "f";
  ck_assert_str_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_2) {
  char haystack[512] = "full";
  char needle[512] = "f";
  ck_assert_str_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_3) {
  char haystack[512] = "f";
  char needle[512] = "full";
  ck_assert_ptr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_4) {
  char haystack[512] = "full";
  char needle[512] = "qwerty";
  ck_assert_ptr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_5) {
  char haystack[512] = "full ama";
  char needle[512] = "ma";
  ck_assert_str_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(strtok_1) {
  char str[512] = "full ama";
  char delim[512] = " ";
  ck_assert_str_eq(s21_strtok(str, delim), strtok(str, delim));
}
END_TEST

START_TEST(strtok_2) {
  char str[512] = "full ama soa";
  char delim[512] = "o";
  ck_assert_str_eq(s21_strtok(str, delim), strtok(str, delim));
}
END_TEST

START_TEST(strtok_3) {
  char str[512] = "full ama soa";
  char delim[512] = "o";
  ck_assert_str_eq(s21_strtok(str, delim), strtok(str, delim));
}
END_TEST

START_TEST(strtok_4) {
  char str[512] = "full ama soa";
  char delim[512] = "s";
  ck_assert_str_eq(s21_strtok(str, delim), strtok(str, delim));
}
END_TEST

START_TEST(strtok_5) {
  char str[512] = "full ama soa";
  char delim[512] = "";
  ck_assert_str_eq(s21_strtok(str, delim), strtok(str, delim));
}
END_TEST

START_TEST(strtok_6) {
  char str[512] = "full ama soa";
  char delim[512] = "full ama soa";
  ck_assert_ptr_eq(s21_strtok(str, delim), strtok(str, delim));
}
END_TEST

START_TEST(strerror_2) {
  char *case1 = s21_strerror(1);
  char *case2 = strerror(1);
  ck_assert_str_eq(case1, case2);
}
END_TEST

START_TEST(strerror_3) {
  char *case1 = s21_strerror(106);
  char *case2 = strerror(106);
  ck_assert_str_eq(case1, case2);
}
END_TEST

START_TEST(strerror_4) {
  char *case1 = s21_strerror(2);
  char *case2 = strerror(2);
  ck_assert_str_eq(case1, case2);
}
END_TEST

START_TEST(strerror_5) {
  char *case1 = s21_strerror(4);
  char *case2 = strerror(4);
  ck_assert_str_eq(case1, case2);
}
END_TEST

START_TEST(strerror_6) {
  char *case1 = s21_strerror(12);
  char *case2 = strerror(12);
  ck_assert_str_eq(case1, case2);
}
END_TEST

START_TEST(to_lower_1) {
  char *x = "Lorem Ipsum";
  char *got = (char *)s21_to_lower(x);
  ck_assert_str_eq(got, "lorem ipsum");
  if (got) free(got);
}
END_TEST

START_TEST(to_lower_2) {
  char *x = "lorem ipsum\n";
  char *got = (char *)s21_to_lower(x);
  ck_assert_str_eq(got, "lorem ipsum\n");
  if (got) free(got);
}
END_TEST

START_TEST(to_lower_3) {
  char *x = "\"Lorem Ipsum\"";
  char *got = (char *)s21_to_lower(x);
  ck_assert_str_eq(got, "\"lorem ipsum\"");
  if (got) free(got);
}
END_TEST

START_TEST(to_lower_4) {
  char *x = "";
  char *got = (char *)s21_to_lower(x);
  ck_assert_str_eq(got, "");
  if (got) free(got);
}
END_TEST

START_TEST(to_lower_5) {
  char *x = "\tLOREM\tIPSUM\n";
  char *got = (char *)s21_to_lower(x);
  ck_assert_str_eq(got, "\tlorem\tipsum\n");
  if (got) free(got);
}
END_TEST

START_TEST(to_upper_1) {
  char *x = "Lorem Ipsum";
  char *got = (char *)s21_to_upper(x);
  ck_assert_str_eq(got, "LOREM IPSUM");
  if (got) free(got);
}
END_TEST

START_TEST(to_upper_2) {
  char *x = "lorem ipsum\n";
  char *got = (char *)s21_to_upper(x);
  ck_assert_str_eq(got, "LOREM IPSUM\n");
  if (got) free(got);
}
END_TEST

START_TEST(to_upper_3) {
  char *x = "\"Lorem Ipsum\"";
  char *got = (char *)s21_to_upper(x);
  ck_assert_str_eq(got, "\"LOREM IPSUM\"");
  if (got) free(got);
}
END_TEST

START_TEST(to_upper_4) {
  char *x = "";
  char *got = (char *)s21_to_upper(x);
  ck_assert_str_eq(got, "");
  if (got) free(got);
}
END_TEST

START_TEST(to_upper_5) {
  char *x = "\tLOREM\tIPSUM\n";
  char *got = (char *)s21_to_upper(x);
  ck_assert_str_eq(got, "\tLOREM\tIPSUM\n");
  if (got) free(got);
}
END_TEST

START_TEST(trim_all_empty) {
  char str[] = "";
  char trim_ch[] = "";
  char expected[] = "";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(trim_str_empty) {
  char str[] = "";
  char trim_ch[] = "+!0-aeoi2o3i23iuhuhh3O*YADyagsduyoaweq213";
  char expected[] = "";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(trim_empty) {
  char str[] = "+!0-aeoi2o3i23iuhuhh3O*YADyagsduyoaweq213";
  char trim_ch[] = "";
  char expected[] = "+!0-aeoi2o3i23iuhuhh3O*YADyagsduyoaweq213";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(trim_and_str_eq) {
  char str[] = "+!0-aeoi2o3i23iuhuhh3O*YADyagsduyoaweq213";
  char trim_ch[] = "+!0-aeoi2o3i23iuhuhh3O*YADyagsduyoaweq213";
  char expected[] = "";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(trim_1) {
  char str[] = "+!!++Abo+ba++00";
  char trim_ch[] = "+!0-";
  char expected[] = "Abo+ba";
  char *got = (char *)s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(trim_2) {
  char str[] = "Ab000cd0";
  char trim_ch[] = "003";
  char expected[] = "Ab000cd";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(trim_3) {
  char str[] = "DoNotTouch";
  char trim_ch[] = "Not";
  char expected[] = "DoNotTouch";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(trim_4) {
  char str[] = "&* !!sc21 * **";
  char trim_ch[] = "&!* ";
  char expected[] = "sc21";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(trim_5) {
  char str[] = " Good morning!    ";
  char trim_ch[] = " ";
  char expected[] = "Good morning!";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(empty_spaces) {
  char str[] = "        abc         ";
  char trim_ch[] = "";
  char expected[] = "abc";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(null_ptr_trim_chars) {
  char str[] = "        abc         ";
  char *trim_ch = NULL;
  char expected[] = "abc";
  char *got = s21_trim(str, trim_ch);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(insert_1) {
  char str[] = "Shlepa";
  char src[] = "I love my . He is very kind!";
  s21_size_t index = 10;
  char expected[] = "I love my Shlepa. He is very kind!";
  char *got = (char *)s21_insert(src, str, index);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(insert_2) {
  char str[] = "Hello, ";
  char src[] = "Aboba!";
  s21_size_t index = 0;
  char expected[] = "Hello, Aboba!";
  char *got = (char *)s21_insert(src, str, index);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

START_TEST(insert_4) {
  char *src = NULL;
  char *str = NULL;
  s21_size_t index = 100;
  char *expected = NULL;
  char *got = (char *)s21_insert(src, str, index);
  ck_assert_ptr_eq(got, expected);
}
END_TEST

START_TEST(insert_5) {
  char str[] = "Monkey";
  char src[] = "Space  ";
  s21_size_t index = 6;
  char expected[] = "Space Monkey ";
  char *got = (char *)s21_insert(src, str, index);
  ck_assert_str_eq(got, expected);
  if (got) free(got);
}
END_TEST

// // ==================== s21_sprintf ====================

START_TEST(simple_int) {
  char str1[512];
  char str2[512];

  char *format = "This is a simple value %d";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(width_int) {
  char str1[512];
  char str2[512];

  char *format = "%5d";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(plus_width_int) {
  char str1[512];
  char str2[512];

  char *format = "%+12d";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val) {
  char str1[512];
  char str2[512];

  char *format = "%u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val_width) {
  char str1[512];
  char str2[512];

  char *format = "%15u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val_flags) {
  char str1[512];
  char str2[512];

  char *format = "%-16u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val_precision) {
  char str1[512];
  char str2[512];

  char *format = "%.51u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val_many_flags) {
  char str1[512];
  char str2[512];

  char *format = "% 5.51u";
  unsigned int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val_short) {
  char str1[512];
  char str2[512];

  char *format = "%hu";
  unsigned short int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val_long) {
  char str1[512];
  char str2[512];

  char *format = "%lu";
  unsigned long int val = 949149114140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_val_many) {
  char str1[512];
  char str2[512];

  char *format = "%lu, %u, %hu, %.5u, %5.u";
  unsigned long int val = 949149114140;
  ck_assert_int_eq(
      s21_sprintf(str1, format, val, 14, 1441, 14414, 9681),
      sprintf(str2, format, val, (unsigned)14, (unsigned short)1441,
              (unsigned)14414, (unsigned)9681));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(octal_short) {
  char str1[512];
  char str2[512];

  char *format = "%hd";
  short int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(unsigned_zero) {
  char str1[512];
  char str2[512];

  char *format = "%u";
  ck_assert_int_eq(s21_sprintf(str1, format, 0),
                   sprintf(str2, format, (unsigned)0));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(one_char_1) {
  char str1[512];
  char str2[512];

  char *format = "%c";
  char val = 'X';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(one_precision) {
  char str1[512];
  char str2[512];

  char *format = "%.5c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(one_flags) {
  char str1[512];
  char str2[512];

  char *format = "% -5c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(one_width) {
  char str1[512];
  char str2[512];

  char *format = "%15c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(one_many) {
  char str1[512];
  char str2[512];

  char *format = "%-5.3c%c%c%c%c Hello! ABOBA";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val, 'c', 'a', 'b', 'b'),
                   sprintf(str2, format, val, 'c', 'a', 'b', 'b'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(one_many_flags) {
  char str1[512];
  char str2[512];

  char *format = "%-5.3c";
  char val = 'c';
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(string) {
  char str1[512];
  char str2[512];

  char *format = "%s";
  char *val = "I LOVE STRINGS AND TESTS AND SCHOOL21 NO JOKE";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(string_precision) {
  char str1[512];
  char str2[512];

  char *format = "%.15s";
  char *val = "I LOVE STRINGS AND TESTS AND SCHOOL21 NO JOKE";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(string_width) {
  char str1[512];
  char str2[512];

  char *format = "%15s";
  char *val = "69 IS MY FAVORITE NUMBER";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(string_flags) {
  char str1[512];
  char str2[512];

  char *format = "%-15.9s";
  char *val = "69 IS MY FAVORITE NUMBER";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(string_long) {
  char str1[512];
  char str2[512];

  char *format = "%s";
  char *val =
      "69 IS MY FAVORITE NUMBER THIS IS SUPPOSED TO BE A VERY LONG STRING";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(string_many) {
  char str1[512];
  char str2[512];

  char *format = "%s%s%s%s";
  char *val =
      "69 IS MY FAVORITE NUMBER THIS IS SUPPOSED TO BE A VERY LONG STRING";
  char *s1 = "";
  char *s2 = "87418347813748913749871389480913";
  char *s3 = "HAHAABOBASUCKER";
  ck_assert_int_eq(s21_sprintf(str1, format, val, s1, s2, s3),
                   sprintf(str2, format, val, s1, s2, s3));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(string_width_huge) {
  char str1[512];
  char str2[512];
  char *val = "kjafdiuhfjahfjdahf";
  char *format = "%120s";
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(all_empty) {
  char str1[512];
  char str2[512];
  ck_assert_int_eq(s21_sprintf(str1, "abc"), sprintf(str2, "abc"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(empty_format_and_parameters) {
  char str1[512];
  char str2[512];

  ck_assert_int_eq(s21_sprintf(str1, "abc"), sprintf(str2, "abc"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(one_char_2) {
  char str1[512];
  char str2[512];

  ck_assert_int_eq(s21_sprintf(str1, "%c", '\t'), sprintf(str2, "%c", '\t'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(one_string) {
  char str1[512];
  char str2[512];

  ck_assert_int_eq(s21_sprintf(str1, "%s", "Drop Sega PLS"),
                   sprintf(str2, "%s", "Drop Sega PLS"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(many_string) {
  char str1[512];
  char str2[512];

  ck_assert_int_eq(
      s21_sprintf(str1, "%s%s%s%s%s", "Drop", " ", "Sega", " ", "PLS"),
      sprintf(str2, "%s%s%s%s%s", "Drop", " ", "Sega", " ", "PLS"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(one_dec) {
  char str1[512];
  char str2[512];

  ck_assert_int_eq(s21_sprintf(str1, "%d", 666), sprintf(str2, "%d", 666));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(many_dec) {
  char str1[512];
  char str2[512];

  ck_assert_int_eq(s21_sprintf(str1, "%d%d%d%d", -999, 0, 666, -100),
                   sprintf(str2, "%d%d%d%d", -999, 0, 666, -100));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(one_float) {
  char str1[512];
  char str2[512];

  ck_assert_int_eq(s21_sprintf(str1, "%f", 0.0001),
                   sprintf(str2, "%f", 0.0001));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(one_unsigned_dec) {
  char str1[512];
  char str2[512];

  ck_assert_int_eq(s21_sprintf(str1, "%u", 100),
                   sprintf(str2, "%u", (unsigned)100));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(one_char_with_alignment_left) {
  char str1[512];
  char str2[512];

  ck_assert_int_eq(s21_sprintf(str1, "%8c", '\t'), sprintf(str2, "%8c", '\t'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(one_char_with_alignment_right) {
  char str1[512];
  char str2[512];

  ck_assert_int_eq(s21_sprintf(str1, "%-8c", '\t'),
                   sprintf(str2, "%-8c", '\t'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf2) {
  char str1[512];
  char str2[512];
  char format[] = "%1.1f";

  ck_assert_int_eq(s21_sprintf(str1, format, 1.1), sprintf(str2, format, 1.1));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf3) {
  char str1[512];
  char str2[512];
  char format[] = "%8.3c";

  ck_assert_int_eq(s21_sprintf(str1, format, 'a'), sprintf(str2, format, 'a'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf4) {
  char str1[512];
  char str2[512];
  char format[] = "%+5.5d aboba";

  int val = 10000;
  int a = s21_sprintf(str1, format, val);
  int b = sprintf(str2, format, val);
  ck_assert_int_eq(a, b);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf7) {
  char str1[512];
  char str2[512];
  char format[] = "%7.4s";

  ck_assert_int_eq(s21_sprintf(str1, format, "aboba floppa"),
                   sprintf(str2, format, "aboba floppa"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf8) {
  char str1[512];
  char str2[512];
  char format[] = "%6.6u";

  ck_assert_int_eq(s21_sprintf(str1, format, 12341151),
                   sprintf(str2, format, 12341151));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf16) {
  char str1[512];
  char str2[512];
  char format[] = "% c";

  ck_assert_int_eq(s21_sprintf(str1, format, 'a'), sprintf(str2, format, 'a'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf17) {
  char str1[512];
  char str2[512];
  char format[] = "% s";

  ck_assert_int_eq(s21_sprintf(str1, format, "aboba likes floppa"),
                   sprintf(str2, format, "aboba likes floppa"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf18) {
  char str1[512];
  char str2[512];
  char format[] = "% s% c";

  ck_assert_int_eq(s21_sprintf(str1, format, "", 'f'),
                   sprintf(str2, format, "", 'f'));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf19) {
  char str1[512];
  char str2[512];
  char format[] = "%210s";

  ck_assert_int_eq(s21_sprintf(str1, format, "AHHAHAHA\0AHHAHAHAH"),
                   sprintf(str2, format, "AHHAHAHA\0AHHAHAHAH"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf20) {
  char str1[512];
  char str2[512];
  char format[] = "%-115s";

  ck_assert_int_eq(s21_sprintf(str1, format, "Nick her"),
                   sprintf(str2, format, "Nick her"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf26) {
  char str1[512];
  char format[] = "%%%%";

  ck_assert_int_eq(s21_sprintf(str1, format), 2);

  ck_assert_str_eq(str1, "%%");
}
END_TEST

START_TEST(sprintf30) {
  char str1[512];
  char str2[512];
  char format[] = "%-.1d";

  ck_assert_int_eq(s21_sprintf(str1, format, 111), sprintf(str2, format, 111));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(width_char) {
  char str1[512];
  char str2[512];

  char *format = "This is a simple wide char %5c";
  char w = 'c';
  int a = s21_sprintf(str1, format, w);
  int b = sprintf(str2, format, w);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(a, b);
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("Core");
  TCase *tc = tcase_create("Core");
  SRunner *sr = srunner_create(s1);
  int nf;
  suite_add_tcase(s1, tc);

  tcase_add_test(tc, strlen_1);
  tcase_add_test(tc, strlen_2);
  tcase_add_test(tc, strlen_3);
  tcase_add_test(tc, strlen_4);
  tcase_add_test(tc, strlen_5);

  tcase_add_test(tc, memchr_1);
  tcase_add_test(tc, memchr_2);
  tcase_add_test(tc, memchr_3);
  tcase_add_test(tc, memchr_4);
  tcase_add_test(tc, memchr_5);
  tcase_add_test(tc, memchr_6);

  tcase_add_test(tc, memcmp_1);
  tcase_add_test(tc, memcmp_2);
  tcase_add_test(tc, memcmp_4);
  tcase_add_test(tc, memcmp_6);

  tcase_add_test(tc, memcpy_1);
  tcase_add_test(tc, memcpy_2);
  tcase_add_test(tc, memcpy_3);
  tcase_add_test(tc, memcpy_4);
  tcase_add_test(tc, memcpy_5);

  tcase_add_test(tc, memset_1);
  tcase_add_test(tc, memset_2);
  tcase_add_test(tc, memset_3);
  tcase_add_test(tc, memset_4);
  tcase_add_test(tc, memset_5);
  tcase_add_test(tc, memset_6);

  tcase_add_test(tc, strchr_1);
  tcase_add_test(tc, strchr_2);
  tcase_add_test(tc, strchr_3);
  tcase_add_test(tc, strchr_4);
  tcase_add_test(tc, strchr_5);
  tcase_add_test(tc, strchr_6);
  tcase_add_test(tc, strchr_7);

  tcase_add_test(tc, strcspn_1);
  tcase_add_test(tc, strcspn_2);
  tcase_add_test(tc, strcspn_3);
  tcase_add_test(tc, strcspn_4);
  tcase_add_test(tc, strcspn_5);
  tcase_add_test(tc, strcspn_6);
  tcase_add_test(tc, strcspn_7);
  tcase_add_test(tc, strcspn_8);

  tcase_add_test(tc, strncat_1);
  tcase_add_test(tc, strncat_2);
  tcase_add_test(tc, strncat_3);
  tcase_add_test(tc, strncat_4);
  tcase_add_test(tc, strncat_5);
  tcase_add_test(tc, strncat_6);

  tcase_add_test(tc, strncmp_1);
  tcase_add_test(tc, strncmp_4);
  tcase_add_test(tc, strncmp_5);
  tcase_add_test(tc, strncmp_7);

  tcase_add_test(tc, strncpy_1);
  tcase_add_test(tc, strncpy_2);
  tcase_add_test(tc, strncpy_3);
  tcase_add_test(tc, strncpy_4);
  tcase_add_test(tc, strncpy_5);
  tcase_add_test(tc, strncpy_6);

  tcase_add_test(tc, strpbrk_1);
  tcase_add_test(tc, strpbrk_2);
  tcase_add_test(tc, strpbrk_3);
  tcase_add_test(tc, strpbrk_4);
  tcase_add_test(tc, strpbrk_5);
  tcase_add_test(tc, strpbrk_6);

  tcase_add_test(tc, strrchr_1);
  tcase_add_test(tc, strrchr_2);
  tcase_add_test(tc, strrchr_3);
  tcase_add_test(tc, strrchr_4);
  tcase_add_test(tc, strrchr_5);
  tcase_add_test(tc, strrchr_6);

  tcase_add_test(tc, strstr_1);
  tcase_add_test(tc, strstr_2);
  tcase_add_test(tc, strstr_3);
  tcase_add_test(tc, strstr_4);
  tcase_add_test(tc, strstr_5);

  tcase_add_test(tc, strtok_1);
  tcase_add_test(tc, strtok_2);
  tcase_add_test(tc, strtok_3);
  tcase_add_test(tc, strtok_4);
  tcase_add_test(tc, strtok_5);
  tcase_add_test(tc, strtok_6);

  tcase_add_test(tc, strerror_2);
  tcase_add_test(tc, strerror_3);
  tcase_add_test(tc, strerror_4);
  tcase_add_test(tc, strerror_5);
  tcase_add_test(tc, strerror_6);

  // }

  tcase_add_test(tc, to_lower_1);
  tcase_add_test(tc, to_lower_2);
  tcase_add_test(tc, to_lower_3);
  tcase_add_test(tc, to_lower_4);
  tcase_add_test(tc, to_lower_5);

  tcase_add_test(tc, to_upper_1);
  tcase_add_test(tc, to_upper_2);
  tcase_add_test(tc, to_upper_3);
  tcase_add_test(tc, to_upper_4);
  tcase_add_test(tc, to_upper_5);

  tcase_add_test(tc, trim_all_empty);
  tcase_add_test(tc, trim_str_empty);
  tcase_add_test(tc, trim_empty);
  tcase_add_test(tc, trim_and_str_eq);
  tcase_add_test(tc, trim_1);
  tcase_add_test(tc, trim_2);
  tcase_add_test(tc, trim_3);
  tcase_add_test(tc, trim_4);
  tcase_add_test(tc, trim_5);
  tcase_add_test(tc, empty_spaces);
  tcase_add_test(tc, null_ptr_trim_chars);

  tcase_add_test(tc, insert_1);
  tcase_add_test(tc, insert_2);
  tcase_add_test(tc, insert_4);
  tcase_add_test(tc, insert_5);

  //   // ==================== s21_sprintf ====================

  tcase_add_test(tc, simple_int);
  tcase_add_test(tc, width_int);
  tcase_add_test(tc, plus_width_int);
  tcase_add_test(tc, unsigned_val);
  tcase_add_test(tc, unsigned_val_width);
  tcase_add_test(tc, unsigned_val_flags);
  tcase_add_test(tc, unsigned_val_precision);
  tcase_add_test(tc, unsigned_val_many_flags);
  tcase_add_test(tc, unsigned_val_short);
  tcase_add_test(tc, unsigned_val_long);
  tcase_add_test(tc, unsigned_val_many);
  tcase_add_test(tc, octal_short);
  tcase_add_test(tc, unsigned_zero);
  tcase_add_test(tc, one_char_1);
  tcase_add_test(tc, one_precision);
  tcase_add_test(tc, one_flags);
  tcase_add_test(tc, one_width);
  tcase_add_test(tc, one_many);
  tcase_add_test(tc, one_many_flags);
  tcase_add_test(tc, string);
  tcase_add_test(tc, string_precision);
  tcase_add_test(tc, string_width);
  tcase_add_test(tc, string_flags);
  tcase_add_test(tc, string_long);
  tcase_add_test(tc, string_many);
  tcase_add_test(tc, string_width_huge);
  tcase_add_test(tc, all_empty);
  tcase_add_test(tc, empty_format_and_parameters);
  tcase_add_test(tc, one_char_2);
  tcase_add_test(tc, one_string);
  tcase_add_test(tc, many_string);
  tcase_add_test(tc, one_dec);
  tcase_add_test(tc, many_dec);
  tcase_add_test(tc, one_float);
  tcase_add_test(tc, one_unsigned_dec);
  tcase_add_test(tc, one_char_with_alignment_left);
  tcase_add_test(tc, one_char_with_alignment_right);
  tcase_add_test(tc, sprintf2);
  tcase_add_test(tc, sprintf3);
  tcase_add_test(tc, sprintf4);
  tcase_add_test(tc, sprintf7);
  tcase_add_test(tc, sprintf8);
  tcase_add_test(tc, sprintf16);
  tcase_add_test(tc, sprintf17);
  tcase_add_test(tc, sprintf18);
  tcase_add_test(tc, sprintf19);
  tcase_add_test(tc, sprintf20);
  tcase_add_test(tc, sprintf30);
  tcase_add_test(tc, sprintf26);
  tcase_add_test(tc, width_char);
  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);
  return nf == 0 ? 0 : 1;
}
