#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  unsigned char *ptr = (unsigned char *)str;
  for (s21_size_t i = 0; i < n; i++) {
    if (ptr[i] == c) {
      return (void *)&ptr[i];
    }
  }
  return s21_NULL;
}

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  if (!n) return 0;
  while (--n && *(char *)str1 == *(char *)str2) {
    str1 = (char *)str1 + 1;
    str2 = (char *)str2 + 1;
  }
  return (*((unsigned char *)str1) - *((unsigned char *)str2));
}

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  if (dest == s21_NULL || src == s21_NULL) {
    return s21_NULL;
  }

  unsigned char *c_dest = (unsigned char *)dest;
  const unsigned char *c_src = (const unsigned char *)src;

  for (s21_size_t i = 0; i < n; i++) {
    c_dest[i] = c_src[i];
  }
  return dest;
}

void *s21_memset(void *str, int c, s21_size_t n) {
  unsigned char *buff = (unsigned char *)str;
  for (s21_size_t i = 0; i < n; i++) {
    buff[i] = (unsigned char)c;
  }
  return buff;
}

char *s21_strchr(const char *str, int c) {
  char *result = s21_NULL;
  for (s21_size_t i = 0; str[i] != '\0'; i++) {
    if (str[i] == c) {
      result = ((char *)str) + i;
      break;
    }
  }
  if (c == '\0') {
    result = ((char *)str) + s21_strlen(str);
  }
  return result;
}

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t count = 0;

  while (*str1) {
    const char *s2 = str2;
    while (*s2) {
      if (*str1 == *s2) {
        return count;
      }
      s2++;
    }
    str1++;
    count++;
  }
  return count;
}

s21_size_t s21_strlen(const char *str) {
  s21_size_t lenght = 0;
  while (str[lenght] != '\0') {
    lenght++;
  }
  return lenght;
}

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  (void)n;
  s21_size_t x, y;
  for (x = 0; dest[x] != '\0'; x++)
    ;
  for (y = 0; src[y] != '\0'; y++) {
    dest[x + y] = src[y];
  }
  dest[x + y] = '\0';
  return dest;
}

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  s21_size_t i;
  for (i = 0; i < n && str1[i] != '\0' && str2[i] != '\0' && str1[i] == str2[i];
       i++)
    ;
  if (i == n || str1[i] == '\0' || str2[i] == '\0') {
    return 0;  // Если достигнута максимальная длина или одна из строк
               // закончилась, считаем строки равными
  }
  return (int)str1[i] - (int)str2[i];  // Возвращаем разницу кодов символов как
                                       // int, чтобы избежать переполнения
}

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  for (s21_size_t i = 0; i < n; i++) {
    dest[i] = src[i];
  }
  return dest;
}

char *s21_strpbrk(const char *str1, const char *str2) {
  char *result = s21_NULL;
  int x = 0, y = 0;
  while (str1[x] != '\0' && result == s21_NULL) {
    y = 0;
    while (str2[y] != '\0' && result == s21_NULL) {
      if (str1[x] == str2[y]) {
        result = (char *)&str1[x];
        break;
      }
      y++;
    }
    x++;
  }
  return result;
}

char *s21_strrchr(const char *str, int c) {
  char *result = s21_NULL;
  char res = (char)c;
  s21_size_t len = s21_strlen(str);

  for (s21_size_t i = 0; i < len; i++) {
    if (str[i] == res) {
      result = (char *)&str[i];
    }
  }

  if (res == '\0') {
    result = (char *)&str[len];
  }

  return result;
}

char *s21_strstr(const char *haystack, const char *needle) {
  char *result = s21_NULL;
  for (s21_size_t i = 0; haystack[i] != '\0'; i++) {
    s21_size_t j = 0;
    while (haystack[i + j] == needle[j] && needle[j] != '\0') {
      j++;
    }
    if (needle[j] == '\0') {
      result = (char *)&haystack[i];
      break;
    }
  }
  return result;
}

char *s21_strtok(char *str, const char *delim) {
  static char *s21_strtok_last = s21_NULL;
  if (str) {
    s21_strtok_last = str;
  } else {
    if (!s21_strtok_last) return s21_NULL;
    str = s21_strtok_last;
  }

  while (*str) {
    const char *de = delim;
    int isdelim = 0;
    while (*de) {
      if (*de == *str) {
        isdelim = 1;
        break;
      }
      de++;
    }
    if (!isdelim) break;
    str++;
  }

  if (*str == '\0') {
    s21_strtok_last = s21_NULL;
    return s21_NULL;
  }

  char *token = str;

  while (*str) {
    const char *de = delim;
    while (*de) {
      if (*str == *de) {
        *str = '\0';
        s21_strtok_last = str + 1;
        return token;
      }
      de++;
    }
    str++;
  }

  s21_strtok_last = s21_NULL;
  return token;
}
