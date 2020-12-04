#ifndef TREE_H
#define TREE_H

typedef struct Node{
  char letter;
  int occurence;
  struct Node* left;
  struct Node* right;
}Node;
typedef Node* Tree;

typedef struct NodeDic{
    char letter;
    char* code;
    struct NodeDic* left;
    struct NodeDic* right;
}NodeDic;
typedef NodeDic* TreeDic;

Tree createNode(char letter);
int getDepth(Tree tree);
Tree createHuffmanNode(Tree min, Tree min2);
Node** insert(Node** array,int length,char letter,int pos);
void displayHuffman(Tree tree);

NodeDic* Create_Node_Dic(char letter, char* code, int codeLgt);
void add_BST_Dic(NodeDic** tree, char letter, char* code, int codeLgt);
int Tree_Depth_Dic(NodeDic* tree);
int Balance_Factor_Dic(NodeDic* tree);
void Right_Rotation_Dic(NodeDic** tree);
void Left_Rotation_Dic(NodeDic** tree);
void Balance_Dic(NodeDic** tree);
void add_node_AVL_Dic(NodeDic** tree, char letter, char* code, int codeLgt);
TreeDic* Huffman_Into_Avl_Wrapper(Tree tree);
void Huffman_Into_Avl(Tree treeHuff, TreeDic* treeAvl, char lastPath, char* path, int pathLgt);
char* getCode(TreeDic dico, char letter);
#endif
