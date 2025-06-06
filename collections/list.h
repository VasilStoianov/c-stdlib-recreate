#ifndef __LIST__
#define __LIST__
#include "../standard/types.h"
#include <stdlib.h>

typedef struct {
  void *value;
} ListE;

typedef struct {
  ListE **entries;
  int size;
  int capacity;
} ArrayList;

boolean add(ArrayList *list, void *value, usize size) {
  ListE *val = (ListE *)malloc(size);
  if (list->capacity == list->size + 4) {
    list->capacity *= 2;
    list->entries = realloc(list->entries, list->capacity * sizeof(ListE *));
  }
  list->entries[list->size] = malloc(sizeof(ListE *));
  list->entries[list->size]->value = malloc(size);
  if (list->entries[list->size]->value) {
    memcpy(list->entries[list->size++]->value, value, size);
    return true;
  }
  return false;
}

ListE *get(ArrayList *list, usize index) {
  if (index >= list->size)
    return NULL;
  return list->entries[index];
}

void create_list(ArrayList *list) {

  list = malloc(sizeof(ArrayList));
  list->capacity = 15;
  list->size = 0;
}



#endif