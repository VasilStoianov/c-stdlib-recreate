#pragma once

#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct CompValue {
  union {
    int intValue;
    char *strinValue;
    char charValue;
  } data;
} CompValue;

typedef enum CompareType { INTEGER, STRING, CHAR, STRUCT } CompareType;

typedef struct Node {
  void *value;
  struct Node *left;
  struct Node *right;
  __uint8_t isRoot;
} Node;

typedef struct Tree {
  Node *root;
} Tree;

int compareValues(size_t left, size_t right) { return left >= right; }

void put_(Tree *tree, Node *toPut, Node **toCheck, int (*f)(char*, char*));
void put(Tree *tree, Node *toPut, int (*f)(char*, char*)) {
  put_(tree, toPut, &(tree->root), (*f));
}

void put_(Tree *tree, Node *toPut, Node **toCheck, int (*f)(char*, char*)) {
  if (tree->root == NULL) {
    tree->root = malloc(sizeof(Node));
    tree->root->value = malloc(strlen((char *)toPut->value));
    strcpy(tree->root->value, toPut->value);
    tree->root->isRoot = 1;
    return;
  }
  if ((*toCheck) == NULL) {
    (*toCheck) = malloc(sizeof(Node));
    (*toCheck)->value = malloc(sizeof((char *)toPut->value));
    strcpy((*toCheck)->value, toPut->value);
    (*toCheck)->left = NULL;
    (*toCheck)->right = NULL;
  } else {
    if ((*f)((*toCheck)->value,toPut->value)) {
      put_(tree, toPut, &(*toCheck)->left, f);
    } else {

      put_(tree, toPut, &(*toCheck)->right, f);
    }
  }
}

void findValue(Tree *tree, CompareType type, int offset, CompValue val) {
  Queue queue = {0};
  Queue * queuePtr = &queue;
  QNode current = {.value = tree->root, .next = NULL, .previous = NULL};
  push(&queue.head, current, &queuePtr);
  int level = 0;
  while (queue.size > 0) {
    QNode *temp = pop(&queue);
    if (temp != NULL) {
      level++;
      Node *curr = (Node *)temp->value;
      switch (type) {
      case STRUCT: {
        if ((*(typeof(val.data.intValue) *)((char *)curr->value + offset)) ==
            val.data.intValue) {
          printf("Value found on level %d \n", level);
          return;
        }else {
          QNode left = {.value = curr->left};
          QNode right = {.value = curr-> right};
          push(&queue.head,left,&queuePtr);
          push(&queue.head,right,&queuePtr);
        };

        break;
      }
      case STRING: {
        printf("%s , %s %d \n",( char*)curr->value,val.data.strinValue,strcmp(( char*)curr->value,val.data.strinValue));
        if (strcmp(( char*)curr->value,val.data.strinValue) == 0) {
          printf("Value found on level %d, value: %s  \n", level,(char*)curr->value);
          return;
        }else {
          QNode left = {.value = curr->left};
          QNode right = {.value = curr-> right};
           push(&queue.head,left,&queuePtr);
          push(&queue.head,right,&queuePtr);
        };

        break;
      }
      case INTEGER: {
        if (*( int*)((char *)curr->value + offset)==
            val.data.intValue) {
          printf("Value found on level %s, value:  \n", level,(int)temp->value);
          return;
        }else {
          QNode left = {.value = curr->left};
          QNode right = {.value = curr-> right};
           push(&queue.head,left,&queuePtr);
          push(&queue.head,right,&queuePtr);
        };


        break;
      }

      case CHAR: {

        break;
      }
      default:
        break;
      }
    }
  }
}
