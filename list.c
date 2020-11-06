#include <stdlib.h>
#include <stdio.h>
#include "list.h"


Element* createElement(char c){
  Element* new_el = (Element*)malloc(sizeof(Element));
  new_el->letter = c;
  new_el->occurence = 1;
  new_el->next = NULL;
  return new_el;
}

void addElement(Element** list, Element* element){
  Element* temp = (*list);
  (*list) = element;
  element->next = temp;
}

void displayList(Element* list){
  if (list != NULL){
    printf("%c %d\n",list->letter,list->occurence);
    displayList(list->next);
  }
}
