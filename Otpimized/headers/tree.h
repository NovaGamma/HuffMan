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
int getDepth(Tree tree);
Tree createHuffmanNode(Tree min, Tree min2);
Node** insert(Node** array,int length,char letter,int pos);
void displayHuffman(Tree tree);

#endif
