#include "../collections/queue.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Test{
    int val;
    int val2;
} Test;


void printQueue(Queue * queue){
    QNode * current = queue->head;
    while(current->value != NULL){
        QNode * next = current->next;
        Test* t = (Test*)current->value;
        printf("%d \n",t->val);
        current = next;
    }
    printf("\n");
}


int main(void) {

     
   printQueue(queue);
    freeQueue(queue);
  return 1;
}