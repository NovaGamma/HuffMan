#include <stdlib.h>
#include <stdio.h>
#include "tree.h"


Tree createNode(char letter){
  Tree node = (Node*)malloc(sizeof(Node));
  node->letter = letter;
  node->occurence = 1;
  node->left = NULL;
  node->right = NULL;
  node->next = NULL;
  return node;
}

Tree createHuffmanNode(Tree min, Tree min2){
  Tree node = (Node*)malloc(sizeof(Node));
  node->occurence = min->occurence + min2->occurence;
  node->letter = '\0';
  node->left = min2;
  node->right = min;
  return node;
}

int nElement(Tree tree){
  if(tree != NULL){
    return 1 + nElement(tree->next);
  }
  return 0;
}

int getWeight(Tree tree){
  if (tree != NULL){
    return tree->occurence + getWeight(tree->left) + getWeight(tree->right);
  }
}

int getDepth(Tree tree){
  if (tree == NULL){
    return 0;
  }
  else{
    int dl = getDepth(tree->left);
    int dr = getDepth(tree->right);
    if (dl > dr){
      return dl + 1;
    }
    else{
      return dr + 1;
    }
  }
}


void add2TreeList(Tree* tree,Tree node){
  if ((*tree) != NULL){
    Tree temp = (*tree);
    (*tree) = node;
    node->next = temp;
  }
  else{
    (*tree) = node;
  }
}
