#include "s21_string.h"
void *s21_to_lower(const char *str) {
  char *lower = s21_NULL;
  if (str) {
    lower = (char *)malloc((s21_strlen(str) + 1) * sizeof(char));
  }
  if (lower) {
    s21_strncpy(lower, str, s21_strlen(str) + 1);
    for (char *i = lower; *i; i++) {
      if (*i >= 'A' && *i <= 'Z') {
        *i += 32;
      }
    }
  }
  return (void *)lower;
}