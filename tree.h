
typedef struct Node{
  char letter;
  int occurence;
  struct Node* left;
  struct Node* right;
}Node;
typedef Node* Tree;

Tree createNode(char letter,int occurence);
void displayTree(Tree tree);
void add2Tree(Tree* tree, Tree node, int side);
int getWeight(Tree tree);
