#ifndef _STANDARD_
#define _STANDARD_
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define WORD_LENGTH 8 // Define the length of the generated word
#define CHARSET                                                                \
  "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789" // Characters
                                                                   // to pick
                                                                   // from

unsigned long hash_fnv1(void *data, size_t size) {
  unsigned long hash = 2166136261u;
  const unsigned char *bytes = (const unsigned char *)data;

  for (int x = 0; x < size; x++) {

    hash ^= bytes[x];
    hash *= 16777619;
  }

  return hash;
}

unsigned long hash_djb2(char *str) {

  int hash = 5381;
  int c;

  while ((c = *str++)) {
    hash = ((hash << 5) + hash) + c;
  }

  return hash;
}

unsigned long hash2(char *str) {

  size_t len = strlen(str);
  unsigned long hsh = 555123;
  for (int x = 0; x < len; x++) {

    char c = str[x];

    hsh = (hsh + c) << x;
    hsh *= 11232;
  }
  return hsh;
}

char *generate_random_string(char *word, int length) {

  int charset_length = strlen(CHARSET);
  for (int x = 0; x < length; x++) {
    word[x] = CHARSET[rand() % charset_length];
  }
  word[length] = '\0';
}

char **generate_random_word_array(int length_array, int length_word) {

  char **str = (char **)malloc(length_array * (length_word * sizeof(char *)));

  for (int x = 0; x < length_array; x++) {
    str[x] = (char *)malloc(length_word * sizeof(char *));
    generate_random_string(str[x], length_word);
    printf("%s \n", str[x]);
  }

  return str;
}

#endif