
typedef struct Node{
  char letter;
  int occurence;
  struct Node* next;
  struct Node* left;
  struct Node* right;
}Node;
typedef Node* Tree;

Tree createNode(char letter);
void displayTree(Tree tree);
void add2TreeList(Tree* tree,Tree node);
int getWeight(Tree tree);
int getDepth(Tree tree);
