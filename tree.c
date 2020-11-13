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

int getDepth(Tree tree){
  if (tree != NULL){
    return 1 + getDepth(tree->left) + getDepth(tree->right);
  }
  return 0;
}

void add2TreeList(Tree* tree,Tree node){
  if ((*tree) != NULL){
    Tree temp = (*tree);
    (*tree) = node;
    node->left = temp;
  }
}

void removeFromTreeList(Tree* tree,char letter){
  if ((*tree) != NULL){
    if((*tree)->letter == letter){
      Tree temp = (*tree);
      (*tree) = (*tree)->left;//here since tree is a degenerate we know that there is nothing on the right child
      free(temp);
    }
    else{
      while((*tree)->left->letter != letter){
        (*tree) = (*tree)->left;
      }
      Tree temp = (*tree)->left;
      free(temp);
      if ((*tree)->left->left != NULL){
        (*tree)->left = (*tree)->left->left;
      }
      else{
        (*tree)->left = NULL;
      }
    }
  }
}
