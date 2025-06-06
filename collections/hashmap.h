#ifndef __MAP___
#define __MAP__
#include "../standard/hash.h"
#include <stdbool.h>
#include <stdlib.h>

typedef enum {
  INT,
  LONG,
  STRING,
  STRUCT

} Key_Val;

typedef struct {
  void *key;
  void *value;
  void *next;
} Entry;

typedef struct {
  Entry **buckets;
  int size;
  int capacity;
} HashMap;

bool put(HashMap *map, void *key, void *value, Key_Val k_val) {
  switch (k_val) {
  case STRING: {
    long hash = hash_fnv1(key, strlen((char *)key));
    int index = hash % map->capacity;
    Entry *e = map->buckets[index];
    if (e) {
      while (e) {
        if (e->next == NULL) {
          e->next = (Entry *)malloc(sizeof(Entry));
          Entry *ent = (Entry *)e->next;
          ent->key = key;
          ent->value = value;
          ent->next = NULL;
          return 1;
        }
        e = (Entry *)e->next;
      }
    } else {
      e = (Entry *)malloc(sizeof(Entry));

      e->key = strdup((char *)key);
      e->next = NULL;
      e->value = value;
      return 1;
    }
    break;
  }

  case INT: {

    long hash = hash_fnv1(key, sizeof(*(int *)key));
    int index = hash % map->capacity;
    Entry *e = map->buckets[index];
    if (e) {
      while (e) {
        if (e->next == NULL) {
          e->next = (Entry *)malloc(sizeof(Entry));
          Entry *ent = (Entry *)e->next;
          ent->key = key;
          ent->value = value;
          ent->next = NULL;
          return 1;
        }
        e = (Entry *)e->next;
      }
    } else {
      e = (Entry *)malloc(sizeof(Entry));
      e->key = key;
      e->next = NULL;
      e->value = value;
      return 1;
    }
    break;
  }

  default:
    return 0;
    break;
  }
}

Entry *get(HashMap *map, void *key, Key_Val k_val) {

  switch (k_val) {
  case STRING: {
    long hash = hash_fnv1(key, strlen((char *)key));
    return map->buckets[hash % map->capacity];
    break;
  }
  case INT: {
    long hash = hash_fnv1(key, sizeof(*(int *)key));
    return map->buckets[hash % map->capacity];
    break;
  }

  default:
  return NULL;
    break;
  }
}

void free_map(HashMap *map) {
  for (int x = 0; x < map->capacity; x++) {
    Entry *e = map->buckets[x];
    if (e) {
      Entry *nex = (Entry *)e->next;
      while (nex) {
        Entry *temp = (Entry *)nex->next;
        free(nex->key);
        free(nex->value);
        free(nex);
        nex = temp;
      }
      free(e);
    }
  }
  free(map);
}

#endif