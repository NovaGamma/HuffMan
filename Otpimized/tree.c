#include <stdlib.h>
#include <stdio.h>
#include "headers/tree.h"

Tree createNode(char letter){
  Tree node = (Node*)malloc(sizeof(Node));
  node->letter = letter;
  node->occurence = 1;
  node->left = NULL;
  node->right = NULL;
  return node;
}

Tree createHuffmanNode(Tree min, Tree min2){
  Tree node = (Node*)malloc(sizeof(Node));
  node->occurence = min->occurence + min2->occurence;
  node->letter = '\0';
  node->left = min;
  node->right = min2;
  return node;
}

void displayHuffman(Tree tree){
  if (tree != NULL){
    if(tree->letter != '\0')
      printf("%d %c | ",tree->occurence,tree->letter);
      displayHuffman(tree->left);
      displayHuffman(tree->right);
  }
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
