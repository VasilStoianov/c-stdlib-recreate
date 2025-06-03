#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include "tree.h"

int comp(char * str1 , char* str2){
  return strcmp(str1,str2);
}

int main(void) {

Tree* t = malloc(sizeof(Tree));
Node * n = malloc(sizeof(Node));
n->value = "test";
put(t,n,comp);
findValue(t,STRING,0,(CompValue){.data.strinValue = "test"});


  return 1;
}