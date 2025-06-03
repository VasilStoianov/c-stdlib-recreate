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


#endif