#include "s21_string.h"

int check(char buffer, const char *trim_chars, int len_trim) {
  for (int i = 0; i < len_trim; i++) {
    if (buffer == trim_chars[i]) {
      return 1;
    }
  }
  return 0;
}

void *s21_trim(const char *src, const char *trim_chars) {
  if (src == s21_NULL) {
    return s21_NULL;
  }

  int len = strlen(src);
  int len_trim = trim_chars ? strlen(trim_chars) : 0;
  char *buffer = malloc(len + 1);

  if (buffer == s21_NULL) {
    return s21_NULL;
  }

  int count = 0, start = 0, end = 0;

  if (trim_chars == s21_NULL || len_trim == 0) {
    trim_chars = " ";
    len_trim = 1;
  }

  while (check(src[start], trim_chars, len_trim)) {
    start++;
  }

  end = len - 1;

  while (check(src[end], trim_chars, len_trim)) {
    end--;
  }

  for (int i = start; i < end + 1; i++) {
    buffer[count++] = src[i];
  }

  buffer[count++] = '\0';
  return buffer;
}
