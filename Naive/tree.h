
typedef struct Node{
  char letter;
  int occurence;
  struct Node* next;
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

Tree createNode(char letter);
void displayTree(Tree tree);
void add2TreeList(Tree* tree,Tree node);
int getWeight(Tree tree);
int getDepth(Tree tree);
Tree createHuffmanNode(Tree min, Tree min2);
