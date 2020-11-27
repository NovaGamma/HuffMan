#include <stdlib.h>
#include <stdio.h>
#include "tree.h"

Tree createNode(char letter){
  Tree node = (Node*)malloc(sizeof(Node));
  node->letter = letter;
  node->occurence = 1;
  node->left = NULL;
  node->right = NULL;
  return node;
}

Node** insert(Node** array,int length,char letter,int pos){
  Node** inserted = (Node**)malloc(sizeof(Node*)*(length+1));
  Node* NodeLetter = createNode(letter);
  int i;
  if (pos != 0){
    for(i = 0; i < pos;i++){
      inserted[i] = array[i];
    }
    inserted[pos] = NodeLetter;
  }
  else{
    inserted[0] = NodeLetter;
  }
  for (i = pos+1;i<length+1;i++){
    inserted[i] = array[i-1];
  }
  return inserted;
}
