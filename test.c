#include <stdio.h>
#include <stdlib.h>
#include "tree.c"

Node* letterOccurrences(char* path){
  //here list is a degenerate tree
  FILE *file = fopen(path,"r");
  char buffer = getc(file);
  Node* list = createNode(buffer);
  int length = 1;
  list->occurence--;//decresing the occurence of the first letter because it will be increase after
  Node* temp;
  int added;
  while (buffer != EOF){
    temp = list;
    added = 0;
    do{
      if (buffer == temp->letter){
        temp->occurence++;
        added = 1;
      }
      temp = temp->next;
    }while(temp != NULL && added != 1 && temp->next != NULL);
    if (added == 0){
      add2TreeList(&list,createNode(buffer));//0 to add it at the left of the tree to create a degenerate
    }
    buffer = fgetc(file);
    /*if (buffer == EOF){
      printf("\nBonjour Antoine\n");
    }*/
  }
}

int main(){
  char path[] = "input.txt";
  Tree tree = letterOccurrences(path);
  return 0;
}
