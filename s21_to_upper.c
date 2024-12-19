#include "s21_string.h"

void *s21_to_upper(const char *str) {
  char *upper = s21_NULL;
  if (str) {
    upper = (char *)malloc((s21_strlen(str) + 1) * sizeof(char));
  }
  if (upper) {
    s21_strncpy(upper, str, s21_strlen(str) + 1);
    for (char *x = upper; *x; x++) {
      if (*x >= 'a' && *x <= 'z') {
        *x -= 32;
      }
    }
  }
  return (void *)upper;
}
