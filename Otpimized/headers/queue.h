#ifndef QUEUE_H
#define QUEUE_H

#include "tree.h"

typedef struct Element{
  Node* data;
  struct Element* next;
}Element;

typedef struct Queue{
    Element* values_of_queue;
}Queue;

Element* create_element(Node* val);
Queue* create_queue();
int is_empty(Queue* q);
void enqueue(Queue** q, Node* val);
Node* unqueue(Queue** q, int delete);

#endif
