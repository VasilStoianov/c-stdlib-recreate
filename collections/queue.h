#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 25

typedef struct QNode
{
 void * value;
 struct QNode * previous;
 struct QNode * next;
} QNode;


typedef struct Queue {
   int size;
   QNode *head;
   QNode *tail;
} Queue;


int enqueue(Queue* queue, void* value) {
    if (value == NULL) {
        printf("ERROR: Empty value to put\n");
        return 0;
    }

    QNode* newNode = malloc(sizeof(QNode));
    newNode->value = value;
    newNode->next = NULL;
    newNode->previous = queue->tail;

    if (queue->tail) {
        queue->tail->next = newNode;
    }
    queue->tail = newNode;

    if (queue->head == NULL) {
        queue->head = newNode;
    }

    queue->size++;
    return 1;
}

QNode* dequeue(Queue* queue){
   if(queue->head == NULL){
    return NULL;
   }
   QNode* res = queue->head;
   queue->head = queue->head->next;
   if(queue->head != NULL){

   queue->head->previous = NULL;
   }else {

   queue->tail = queue->head;
   }
   --queue->size;
return res;
}




void freeQueue(Queue * queue){
    QNode * current = queue->head;
    while(current != NULL){
        QNode * next = current->next;
        free(current->value);
        free(current);
        current = next;
    }
    free(queue);
}

Queue* create_queue() {
    Queue* queue = malloc(sizeof(Queue));
    queue->size = 0;
    queue->head = NULL;
    queue->tail = NULL;
    return queue;
}
