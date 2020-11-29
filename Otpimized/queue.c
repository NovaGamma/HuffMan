#include <stdlib.h>
#include <stdio.h>
#include "headers/queue.h"

Element* create_element(Node* val){
    Element* e = (Element*)malloc(sizeof(Element));
    e->data = val;
    e->next = NULL;
    return e;
}

Queue* create_queue(){
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->values_of_queue = NULL;
    return q;
}

int is_empty(Queue* q){
    if(q->values_of_queue == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

void enqueue(Queue** q, Node* val){
    Element* new_el = create_element(val);
    new_el->next = (*q)->values_of_queue;
    (*q)->values_of_queue = new_el;
}

Node* unqueue(Queue** q,int delete){
    if(is_empty(*q)){
        return NULL;
    }
    else{
        Element* temp = (*q)->values_of_queue;
        if(temp->next == NULL){
            Node* temp2 = temp->data;
            if(delete){
            (*q)->values_of_queue = NULL;
            free(temp);
            }
            return temp2;
        }
        else{
            while(temp->next->next != NULL){
                temp = temp->next;
            }
            Element* temp2 = temp->next;
            Node* temp3 = temp2->data;
            if(delete){
            temp->next = NULL;
            free(temp2);
            }
            return temp3;
        }
    }
}
