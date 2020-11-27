#ifndef TREE_H
#define TREE_H

typedef struct Node{
  char letter;
  int occurence;
  struct Node* left;
  struct Node* right;
}Node;
typedef Node* Tree;

Tree createNode(char letter);
Node** insert(Node** array,int length,char letter,int pos);

#endif
