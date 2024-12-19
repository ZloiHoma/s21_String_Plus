#include "s21_string.h"

void tochnost(char format[], char akukaku[], char shirina[], int *i, char *flag,
              int *check) {
  zero(akukaku);
  int len = 0, len1 = 0;
  if (format[*i] == '.') {
    (*i)++;
    while (format[*i] >= '0' && format[*i] <= '9') {
      akukaku[len++] = format[*i];
      (*i)++;
    }
  }
  akukaku[len] = '\0';

  zero(shirina);
  flags(format, flag, i);

  len = 0;
  while (format[*i] >= '0' && format[*i] <= '9') {
    shirina[len++] = format[*i];
    (*i)++;
  }
  shirina[len] = '\0';

  if (format[*i] == '.') {
    (*i)++;
    *check = 1;
    while (format[*i] >= '0' && format[*i] <= '9') {
      akukaku[len1++] = format[*i];
      (*i)++;
    }
    akukaku[len1] = '\0';
  }
}

void percent(char str[], char buf[], int len, int *index) {
  for (int i = 0; i < len / 2 - 1; i++) {
    str[(*index)++] = buf[i];
  }
}

int s21_sprintf(char *str, char *format, ...) {
  int i = 0, index = 0, check = 0, len_percent = 0;
  char akukaku[500] = {'\0'}, shirina[1000] = {'\0'}, *s, flag = '0',
       num2[1000] = {'\0'}, num[1000] = {'\0'}, buff[1000] = {'\0'}, *buf,
       buf_precent[100], axyet[100] = {'\0'};

  va_list ap;
  va_start(ap, format);

  while (format[i]) {
    if (format[i] == '%') {
      i++;
      if (format[i - 1] == '%' && format[i] == '%') {
        buf_precent[len_percent++] = '%';
      }
      tochnost(format, akukaku, shirina, &i, &flag, &check);
      switch (format[i]) {
        case 'd': {
          int d = va_arg(ap, int);
          case_d(d, flag, num, akukaku, shirina);
          add_char(str, num, &index);
          zero(num);
          break;
        }
        case 'c': {
          char c = (char)va_arg(ap, int);
          buff[0] = c;
          buff[1] = '\0';
          case_c(buff, flag, shirina);
          add_char(str, buff, &index);
          break;
        }
        case 'f': {
          double f = va_arg(ap, double);
          buf = case_f(f, flag, akukaku, shirina);
          add_char(str, buf, &index);
          free(buf);
          break;
        }
        case 's': {
          s = va_arg(ap, char *);
          if (check == 0) {
            case_s(s, flag, shirina, akukaku, axyet);
            add_char(str, axyet, &index);
          } else {
            case_s(s, flag, shirina, akukaku, axyet);
            space(axyet, ciferki1(shirina));
            add_char(str, axyet, &index);
          }
          break;
        }
        case 'u': {
          unsigned long int u = 0;
          if (flag == 'l') {
            u = va_arg(ap, unsigned long int);
          } else {
            u = va_arg(ap, unsigned int);
          }
          case_u(u, flag, num2, akukaku, shirina);
          add_char(str, num2, &index);
          zero(num2);
          break;
        }
        default:
          str[index++] = format[i];
          break;
      }
    } else {
      str[index++] = format[i];
    }
    i++;
  }
  percent(str, buf_precent, len_percent, &index);
  str[index] = '\0';
  index = (int)strlen(str);
  va_end(ap);
  return index;
}

void flags(char format[], char *flag, int *i) {
  *flag = '0';
  while (format[*i] == '+' || format[*i] == '-' || format[*i] == ' ' ||
         format[*i] == 'h' || format[*i] == 'l') {
    *flag = format[*i];
    (*i)++;
  }
}

void add_char(char *str, char *s, int *index) {
  int i = 0;
  while (s[i] != '\0') {
    str[*index] = s[i];
    (*index)++;
    i++;
  }
}

void convert(int number, char str[], int base) {
  char tmp[BUFF_SIZE] = {'\0'};
  int idx = BUFF_SIZE - 2;

  bool neg = number < 0 ? 1 : 0;
  number = neg ? number / (-1) : number;

  if (number == 0) tmp[idx] = '0';

  while (number > 0) {
    idx--;
    tmp[idx] = "0123456789"[number % base];
    number /= base;
  }

  int j = 0;
  if (neg && base == 10) {
    str[j++] = '-';
  }

  while (tmp[idx]) {
    str[j++] = tmp[idx++];
  }
  str[j] = '\0';
}

void unsigned_convert(unsigned long int number, char str[], int base) {
  char tmp[BUFF_SIZE] = {'\0'};
  int idx = BUFF_SIZE - 2;

  if (number == 0) {
    tmp[idx] = '0';
  } else {
    while (number > 0) {
      tmp[idx--] = "0123456789ABCDEF"[number % base];
      number /= base;
    }
    idx++;
  }

  int j = 0;
  while (tmp[idx]) {
    str[j++] = tmp[idx++];
  }
  str[j] = '\0';
}

char *float_to_string(double num, int precision) {
  char str[BUFF_SIZE] = {'\0'};
  char buffer[BUFF_SIZE] = {'\0'};
  int index = 0;

  int integer_part = (int)num;
  convert(integer_part, str, 10);
  add_char(buffer, str, &index);

  long double decimal_part = fabs(num - integer_part);
  if (precision > 0) {
    buffer[index++] = '.';
    for (int i = 0; i < precision; i++) {
      decimal_part *= 10;
      int digit = (int)decimal_part;

      if (digit >= 10) {
        digit = 9;
      }

      buffer[index++] = '0' + digit;
      decimal_part -= digit;

      decimal_part = round(decimal_part * pow(10, precision - i - 1)) /
                     pow(10, precision - i - 1);
    }
  }

  buffer[index] = '\0';
  char *b = malloc(strlen(buffer) + 1);
  if (b != s21_NULL) {
    simple_strcpy(b, buffer);
  }
  return b;
}

int ciferki1(char akukaku[]) {
  char cifri[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
  int b = 0, idx = 0;
  while (idx != (int)strlen(akukaku)) {
    for (int i = 0; i < 10; i++) {
      if (akukaku[idx] == cifri[i]) {
        b += i;
        if ((int)strlen(akukaku) > (idx + 1)) {
          b *= 10;
        }
        idx++;
      }
    }
  }
  return b;
}

void noliki(char *num, int zeros) {
  int len = strlen(num);
  if (len >= zeros) {
    return;
  }
  char buffer[1000];
  s21_memset(buffer, '0', zeros);
  custom_copy(buffer, num, zeros, len);
  simple_strcpy(num, buffer);
}

void plus(char buf[]) {
  int idx = 0, k = 0;
  char plus[1000];
  plus[idx++] = '+';
  for (int i = 0; i < (int)strlen(buf) + 1; i++) {
    plus[idx++] = buf[i];
  }
  for (int j = 0; j < (int)strlen(plus); j++) {
    buf[j] = plus[j];
    k++;
  }
  buf[k] = '\0';
}

void space(char buf[], int shift) {
  int len = strlen(buf);
  int idx = 0, shift_1 = shift;
  char space[1000];

  if (shift > len) {
    shift_1 -= len;
    while (shift_1 != 0) {
      space[idx++] = ' ';
      shift_1--;
    }
    for (int i = 0; i < (int)strlen(buf) + (int)strlen(space); i++) {
      space[idx++] = buf[i];
    }
    space[idx++] = '\0';
    int k = 0;
    for (int j = 0; j < (int)strlen(space) + 1; j++) {
      buf[j] = space[j];
      k++;
    }
    buf[k] = '\0';
  }
}

void space_1(char buf[], int shift) {
  int idx = 0, shift_1 = shift;
  char space[1000];
  int len = strlen(buf);
  if (shift > len) {
    shift_1 -= len;
  }
  for (int j = 0; j < (int)strlen(buf); j++) {
    space[j] = buf[j];
    idx++;
  }
  while (shift_1 > 0) {
    space[idx++] = ' ';
    shift_1--;
  }

  for (int j = 0; j < shift; j++) {
    buf[j] = space[j];
  }
}

void zero(char buf[]) {
  for (int i = 0; i < (int)strlen(buf) + 1; i++) {
    buf[i] = '\0';
  }
}

void case_d(int d, char flag, char num[], char akukaku[], char shirina[]) {
  convert(d, num, 10);

  int ciferki = ciferki1(akukaku);
  int shift = ciferki1(shirina);
  zero(shirina);
  zero(akukaku);

  if (ciferki != 0) {
    noliki(num, ciferki);
  }
  if (flag == '+') {
    plus(num);
  }
  if (flag == 'h') {
    d = (short)d;
  }
  if (flag == 'l') {
    d = (long)d;
  }

  if (flag == ' ') {
    if (d > 0) {
      int len = strlen(num);
      space(num, len + 1);
    }
  }

  if (flag == '-') {
    space_1(num, shift);
  } else if (shift != 0) {
    space(num, shift);
  }
}

char *case_f(double f, char flag, char akukaku[], char shirina[]) {
  int ciferki = ciferki1(akukaku);
  if (ciferki == 0) {
    ciferki = 6;
  }
  char *buf = float_to_string(f, ciferki);

  int shift = ciferki1(shirina);

  if ((int)strlen(buf) <= shift) {
    if (flag == '-') {
      space_1(buf, shift);
    } else if (flag != '-') {
      space(buf, shift);
    }
  }

  if (ciferki != 0) {
    noliki(buf, ciferki);
  }

  if (flag == '+') {
    plus(buf);
  }

  if (flag == ' ') {
    if (f > 0) {
      int len = strlen(buf);
      space(buf, len + 1);
    }
  }

  return buf;
}

void accuracy(char *s, int ciferki) {
  int len = (int)strlen(s);

  for (int i = 0; i < len; i++) {
    if (i > ciferki - 1) {
      s[i] = '\0';
    }
  }
}

void case_s(char *s, char flag, char shirina[], char akukaku[], char buffer[]) {
  int shift = ciferki1(shirina);
  int ciferki = ciferki1(akukaku);
  zero(shirina);
  zero(akukaku);
  int len = (int)strlen(s);
  for (int i = 0; i < len; i++) {
    buffer[i] = s[i];
  }
  buffer[len] = '\0';

  if (ciferki != 0) {
    accuracy(buffer, ciferki);
  }

  if (flag == '-') {
    space_1(buffer, shift);
  } else if (flag != '-' && shift != 0) {
    space(buffer, shift);
  }
}

void case_u(unsigned long int d, char flag, char num[], char akukaku[],
            char shirina[]) {
  unsigned_convert(d, num, 10);
  int ciferki = ciferki1(akukaku);
  int shift = ciferki1(shirina);
  zero(shirina);
  zero(akukaku);

  if (ciferki != 0) {
    noliki(num, ciferki);
  }

  if (flag == '-') {
    space_1(num, shift);
  } else if (shift != 0) {
    space(num, shift);
  }
}

void case_c(char buff[], char flag, char shirina[]) {
  int shift = ciferki1(shirina);
  zero(shirina);

  if (flag == '-') {
    space_1(buff, shift);
  } else if (shift != 0) {
    space(buff, shift);
  }
}

void simple_strcpy(char *destination, const char *source) {
  int idx = 0;
  for (int i = 0; source[i] != '\0'; i++) {
    destination[i] = source[i];
    idx++;
  }
  destination[idx] = '\0';
}

void custom_copy(char *buffer, const char *num, int zeros, int len) {
  char *start_position = buffer + (zeros - len);
  simple_strcpy(start_position, num);
}
