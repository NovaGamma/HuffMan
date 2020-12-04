#include <stdio.h>
#include <stdlib.h>
#include "headers/function.h"

/*
int nCharInFile(char* path){
  FILE *file;
  file = fopen(path,"r");
  char buffer = getc(file);
  int number = 0;
  while (buffer != EOF){
    number++;
    buffer = getc(file);
  }
  printf("%d\n",number);
  return number;
}*/

void display(Node** array,int length){
  for(int i = 0;i<length;i++){
    printf("%c %d / ",array[i]->letter,array[i]->occurence);
  }
  printf("\n");
}

void array_merge(Node** array, int first, int medium, int last){
    int size1 = medium - first + 1;
    int size2 = last - medium;
    Node* array1[size1];
    Node* array2[size2];
    int i;
    for(i = 0 ; i < size1 ; i++){
        array1[i] = array[i + first];
    }
    for(i = 0 ; i < size2 ; i++){
        array2[i] = array[i + size1 + first];
    }
    i = 0;
    int j = 0;
    int k = first;
    while(k < last + 1){
        if(i < size1 && (j >= size2 || array1[i]->occurence <= array2[j]->occurence)){
            array[k] = array1[i];
            i++;
        }
        else{
            array[k] = array2[j];
            j++;
        }
        k++;
    }
}

void array_merge_sort(Node** array, int first, int last){
    if(first < last){
        int medium = first + (last-first)/2;
        array_merge_sort(array, first, medium);
        array_merge_sort(array, medium+1, last);
        array_merge(array, first, medium, last);
    }
}

Node** letterOccurrences(char* path,int* length){
  //here list is a degenerate tree
  FILE *file = fopen(path,"r");
  char letter = getc(file);
  Node* node = createNode(letter);
  Node** array = (Node**)malloc(sizeof(Node*));
  array[0] = node;
  array[0]->occurence--;
  while (letter != EOF){
    int right = (*length)-1;
    int left = 0;
    int pos;
    char temp;
    int added = 0;
    int before = -1;
    while (added == 0){
        pos = (left + right)/2;
        temp = array[pos]->letter;
        if (temp == letter){
          array[pos]->occurence++;
          added = 1;
          pos = -1;
        }
        else if (temp > letter){//we go to the left
            if (pos == 0){
              added = -1;
            }
            else if(array[pos-1]->letter < letter){
              added = -1;
            }
            else if (pos == before){
              added = -1;
              pos--;
            }
            else{
                before = pos;
                right = pos - 1;
              }
          }
        else if(temp < letter){ // we go to the right
            if (pos == (*length)-1){
              pos++;
              added = -1;
            }
            else if(array[pos+1]->letter > letter){
              added = -1;
              pos++;
            }
            else{
                left = pos + 1;
              }
          }
    }
    if (pos != -1){
        array = insert(array,*length,letter,pos);
        (*length)++;
    }
    letter = fgetc(file);
    /*if (buffer == EOF){
      printf("\nBonjour Antoine\n");
    }*/
  }
  printf("\n");
  return array;
}

// we create two sorted queues q1 and q2, q1 is the first Node of the q1 queue and q1* the second one.
// we want to give to the function createHuffman the two mins of the values q1, q1*, q2, q2*, the only possibilities are giving, in order : q1q2, q1q1',q2q2',q2q1
Tree createHuffman(Tree* array, int len){
  Queue* q1 = create_queue();  //contains all the nodes from the array
  Queue* q2 = create_queue();  //storage for when we create a new node
  Node* NodeUsed[2];
  Node* huffman;
  for(int i = 0; i<len ; i++) //filling q1
  {
    enqueue(&q1, array[i]);
  }

  while(!is_empty(q1) || !is_empty(q2))
  {
      if(!is_empty(q1) && (is_empty(q2) || unqueue(&q1,0)->occurence < unqueue(&q2,0)->occurence))
      {
        NodeUsed[0] = unqueue(&q1,1);
        //case q1q1*
        if ((!is_empty(q1)) && (is_empty(q2) || unqueue(&q1,0)->occurence < unqueue(&q2,0)->occurence)){   //is_empty(q1) would mean we've just removed the last value of q1
          NodeUsed[1] = unqueue(&q1,1);
        }
        //case q1q2
        else{
          NodeUsed[1] = unqueue (&q2,1);
        }
      }
      //else if (is_empty(q1) || unqueue(&q2,0)->occurence < unqueue(&q1,0)->occurence)
      else
      {
        NodeUsed[0] = unqueue(&q2,1);
        //case q2q2*
        if ((!is_empty(q2)) && (is_empty(q1) || unqueue(&q2,0)->occurence < unqueue(&q1,0)->occurence)){   //is_empty(q2) would mean we've just removed the last value of q2
            NodeUsed[1] = unqueue(&q2,1);
        }
        //case q2q1
        else{
          NodeUsed[1] = unqueue(&q1,1);
        }
      }
    huffman = createHuffmanNode(NodeUsed[0],NodeUsed[1]); //creates the parent of these two nodes, with letter '\0' and occ node 1 + node 2
    if(!is_empty(q1) || !is_empty(q2)){
      enqueue(&q2,huffman);
    }
  }
  return huffman;
}

void compressText(char* path,TreeDic dico){
  FILE *input = fopen(path,"r");
  FILE *output = fopen("output.txt","w");
  char letter = getc(input);
  while(letter != EOF){
    char* code = getCode(dico,letter);
    fprintf(output,"%s",code);
    letter = getc(input);
  }
  fclose(input);
}
