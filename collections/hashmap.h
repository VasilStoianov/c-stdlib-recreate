#ifndef __MAP___
#define __MAP__
#include <stdlib.h>

typedef struct {
  void *key;
  void *value;
  struct Entry *next;
} Entry;

typedef struct {
  Entry **buckets;
  int size;
  int capacity;
} HashMap;

unsigned long hash(void *data, size_t size) {
  unsigned long hash = 2166136261u;
  const unsigned char *bytes = (const unsigned char *)data;

  for (int x = 0; x < size; x++) {

    hash ^= bytes[x];
    hash *= 16777619;
  }

  return hash;
}

#endif