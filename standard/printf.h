#ifndef __PRINTF__
#define __PRINTF__
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

void print_f(char *str, ...) {

  va_list args;

  va_start(args, str);
  for (int x = 0; str[x] != '\0'; x++) {

    if (str[x] == '%') {

      switch (str[x + 1]) {
      case '%': {
        putchar('%');
        x += 2;
        break;
      }

      case 's': {
        char *stri = va_arg(args, char *);
        int ind = 0;
        while (stri[ind] != '\0') {
          putchar(stri[ind]);
          ind++;
        }
        x += 2;
        break;
      }
      case 'l': {
        long number = va_arg(args, long);
        long back = 0;
        long multiplyer = 1;
        while (number) {
          long numb = number % 10;
          back *= multiplyer;
          back += numb;
          number /= 10;
          multiplyer = 10;
        }
        while (back) {
          long numb = back % 10;
          putchar(48 + numb);
          back /= 10;
        }
        x += 2;
        break;
      }
      case 'd': {
        int number = va_arg(args, int);
        int back = 0;
        int multiplyer = 1;
        while (number) {
          int numb = number % 10;
          back *= multiplyer;
          back += numb;
          number /= 10;
          multiplyer = 10;
        }
        while (back) {
          int numb = back % 10;
          putchar(48 + numb);
          back /= 10;
        }
        x += 2;
        break;
      }
      case 'c': {
        char cs = va_arg(args, int);
        putchar(cs);
        x += 2;
        break;
      }
      default:
        break;
      }
    }
    putchar(str[x]);
  }
  va_end(args);
}
#endif
