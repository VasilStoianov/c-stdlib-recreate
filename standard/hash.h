#ifndef _STANDARD_
#define _STANDARD_
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

unsigned long hash_fnv1(void *data, size_t size) {
  unsigned long hash = 2166136261u;
  const unsigned char *bytes = (const unsigned char *)data;

  for (size_t x = 0; x < size; x++) {

    hash ^= bytes[x];
    hash *= 16777619;
    hash &= 0xFFFFFFFFFFFFFFFF;

  }

  return hash;
}

unsigned long hash_djb2(char *str) {

  unsigned long hash = 5381;
  int c;

  while ((c = *str++)) {
    hash = ((hash << 5) + hash) + c;
  }

  return hash;
}



#endif