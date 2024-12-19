#include "s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  if (src == s21_NULL || str == s21_NULL) {
    return s21_NULL;
  }

  size_t src_len = strlen(src);
  size_t str_len = strlen(str);
  size_t total_len = src_len + str_len + 1;

  if (total_len <= src_len || total_len <= str_len) {
    return s21_NULL;
  }

  if (start_index > src_len) {
    return s21_NULL;
  }

  char *buf = (char *)malloc(total_len);
  if (buf == s21_NULL) {
    return s21_NULL;
  }

  size_t idx = 0, index = 0;

  for (size_t i = 0; i < start_index; i++) {
    buf[index++] = src[idx++];
  }

  for (size_t i = 0; i < str_len; i++) {
    buf[index++] = str[i];
  }

  for (size_t i = idx; i < src_len; i++) {
    buf[index++] = src[i];
  }

  buf[index] = '\0';

  return buf;
}
