#include <stdlib.h>
#include <stdio.h>
#include "tree.h"


Tree createNode(char letter, int occurence){
  Tree node = (Node*)malloc(sizeof(Node));
  node->letter = letter;
  node->occurence = occurence;
  node->left = NULL;
  node->right = NULL;
  return node;
}

void displayTree(Tree tree){//display in postfix order
  if(tree != NULL){
    displayTree(tree->left);
    displayTree(tree->right);
    printf("%c %d\n",tree->letter,tree->occurence);
  }
}

int getWeight(Tree tree){
  if (tree != NULL){
    return tree->occurence + getWeight(tree->left) + getWeight(tree->right);
  }
}
