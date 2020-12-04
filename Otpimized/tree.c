#include <stdlib.h>
#include <stdio.h>
#include <string.h>
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

NodeDic* Create_Node_Dic(char letter, char* code, int codeLgt){
    NodeDic* newNode = (NodeDic*)malloc(sizeof(NodeDic));
    char* newString = (char*)malloc(sizeof(char) * codeLgt);
    strcpy(newString, code);
    newNode->letter = letter;
    newNode->code = newString;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

void add_BST_Dic(NodeDic** tree, char letter, char* code, int codeLgt){
    if (*tree == NULL){
        *tree = Create_Node_Dic(letter, code, codeLgt);
    }
    if (letter < (*tree)->letter){
        add_BST_Dic(&((*tree)->left) , letter, code, codeLgt);
    }
    else if (letter > (*tree)->letter){
        add_BST_Dic(&((*tree)->right) , letter, code, codeLgt);
    }
}

int Tree_Depth_Dic(NodeDic* tree){
    if (tree == NULL){
        return 0;
    }
    else{
        int dl = Tree_Depth_Dic(tree->left);
        int dr = Tree_Depth_Dic(tree->right);

        if (dl > dr){
            return dl + 1;
        }
        else{
            return dr + 1;
        }
    }
}

int Balance_Factor_Dic(NodeDic* tree){
    if(tree == NULL){
        return 0;
    }
    else{
        return Tree_Depth_Dic(tree->right) - Tree_Depth_Dic(tree->left);
    }
}

void Right_Rotation_Dic(NodeDic** tree){
    if(*tree != NULL){
        NodeDic* temp = (*tree)->left;
        (*tree)->left = temp->right;
        temp->right = *tree;
        *tree = temp;
    }
}

void Left_Rotation_Dic(NodeDic** tree){
    if(*tree != NULL){
        NodeDic* temp = (*tree)->right;
        (*tree)->right = temp->left;
        temp->left = *tree;
        *tree = temp;
    }
}

void Balance_Dic(NodeDic** tree){
    if (*tree != NULL){
        Balance_Dic(&((*tree)->left));
        Balance_Dic(&((*tree)->right));

        int bf = Balance_Factor_Dic(*tree);
        if(bf <= -2){
            if(Balance_Factor_Dic((*tree)->left) > 0){
                Left_Rotation_Dic(&((*tree)->left));
            }
            Right_Rotation_Dic(tree);
        }
        else if(bf >= 2){
            if(Balance_Factor_Dic((*tree)->right) < 0){
                Right_Rotation_Dic(&((*tree)->right));
            }
            Left_Rotation_Dic(tree);
        }
    }
}

void add_node_AVL_Dic(NodeDic** tree, char letter, char* code, int codeLgt){
    add_BST_Dic(tree, letter, code, codeLgt);
    Balance_Dic(tree);
}

TreeDic* Huffman_Into_Avl_Wrapper(Tree tree){
    TreeDic* avl = (TreeDic*)malloc(sizeof(TreeDic));
    *avl = NULL;
    char* path = (char*)malloc(sizeof(char));
    path[0] = '\0';

    Huffman_Into_Avl(tree->left, avl, '0', path, 1);
    Huffman_Into_Avl(tree->right, avl, '1', path, 1);

    return avl;
}

void Huffman_Into_Avl(Tree treeHuff, TreeDic* treeAvl, char lastPath, char* path, int pathLgt){
    char* bufferChar = (char*)malloc(sizeof(char)*(++pathLgt));
    strcpy(bufferChar,path);
    bufferChar[pathLgt-2] = lastPath;
    bufferChar[pathLgt-1] = '\0';
    path = bufferChar;
    if(treeHuff->right == NULL && treeHuff->left == NULL){
        add_node_AVL_Dic(treeAvl, treeHuff->letter, path, pathLgt);
    }
    else{
        Huffman_Into_Avl(treeHuff->left, treeAvl, '0', path, pathLgt);
        Huffman_Into_Avl(treeHuff->right, treeAvl, '1', path, pathLgt);
    }
}

char* getCode(TreeDic dico, char letter){
  if(dico != NULL){
    if(dico->letter == letter)
    {
      return dico->code;
    }
    else if(dico->letter > letter){
      return getCode(dico->left,letter);
    }
    else{
      return getCode(dico->right,letter);
    }
  }
}
