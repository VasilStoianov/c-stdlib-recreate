#ifndef __BM_ALLOC__
#define __BM_ALLOC__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "types.h"

typedef struct mem_block {
  struct mem_block *next;
  size_t size;
  int free;
} mem_block;

static mem_block *HEAD = NULL;
static mem_block *last = NULL;

#define META_SIZE sizeof(mem_block)

mem_block *find_free(size_t size) {

  mem_block *current = HEAD;

  while (current) {

    if (current->size >= size && current->free) {
      return current;
    }
    current = current->next;
  }

  return NULL;
}

void *bm_alloc(size_t size) {

  if (size <= 0)
    return NULL;

  mem_block *block = find_free(size);

  if (block)
    return block + 1;

  block =(mem_block*) sbrk(size + META_SIZE);
  block->size = size;
  block->free = 0;
  block->next = NULL;
  if (!HEAD) {
    HEAD = block;
  } else {
    last->next = block;
  }
  last = block;

  return block + 1;
}

void b_free(void *ptr) {
  mem_block *curr_block = (mem_block *)ptr - 1;
  curr_block->free = 1;
  memset(curr_block + 1, 0, curr_block->size);
}


void* b_realloc(void* src,usize size){

}

#endif