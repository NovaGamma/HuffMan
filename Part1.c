#include <stdio.h>
#include <stdlib.h>
#include "tree.c"


void text2binaryFile(){
  FILE *input;
  FILE *output;
  input = fopen("input.txt","r");
  output = fopen("binary.txt","w");
  char buffer = fgetc(input);
  while (buffer != EOF){
    //convert the char to binary and save it in the output file
    char* binary = (char*)malloc(sizeof(char)*9);
    for(int i = 7;i >= 0;i--){
      binary[7-i] = (buffer >> i) & 1 ? '1' : '0';
    }
    binary[8] = '\0';
    fprintf(output,"%s",binary);
    buffer = fgetc(input);
  }
  fclose(input);
  fclose(output);
}

int nCharInFile(char* path){
  FILE *file;
  file = fopen(path,"r");
  char buffer = getc(file);
  int number = 0;
  while (buffer != EOF){
    number++;
    buffer = getc(file);
  }
  printf("%d\n",number);
  return number;
}

Node* getMinOccurrences(Tree list){
    if(list != NULL){
      Node* temp = list;
      Node* min = list;
      while (temp != NULL){
        if (temp->occurence <= min->occurence){
          min = temp;
        }
        temp = temp->next;
      }
    return min;
    }
}
/*
void removeFromTreeList(Tree* list, Tree node){
  Tree temp = *list;
  Node* prev = temp;
  if (temp->occurence == node->occurence && temp->left == node->left && temp->right == node->right){
    (*list) = temp->next;
    free(temp);
  }
  while (temp != NULL){
    if(temp->occurence == node->occurence && temp->left == node->left && temp->right == node->right){
      prev->next = temp->next;
      free(temp);
      return node;
    }
    prev = temp;
    temp = temp->next;
  }
}*/

void removeFromTreeList(Tree* list, Tree node){
    if(*list != NULL && (*list)->next != NULL){
        if((*list)->next->occurence == node->occurence && (*list)->next->left == node->left && (*list)->next->right == node->right){
            Tree temp = (*list)->next;
            (*list)->next = (*list)->next->next;
            free(temp);
        }
        else{
            removeFromTreeList(&(*list)->next, node);
        }
    }
    else if(*list != NULL && (*list)->occurence == node->occurence && (*list)->left == node->left && (*list)->right == node->right){
        free(*list);
        *list = NULL;
    }
}

Tree createHuffman(Tree occurence){
  while (nElement(occurence) > 1){
    displayList(occurence);
    printf("\n");
    Tree min = getMinOccurrences(occurence);//sending the address of the tree because the min will be removed
    removeFromTreeList(&occurence,min);
    Tree min2 = getMinOccurrences(occurence);
    removeFromTreeList(&occurence,min2);
    displayList(occurence);
    printf("\n");
    printf("%d\n",min->occurence + min2->occurence);
    Tree huffman = createHuffmanNode(min,min2);
    printf("occ %d\n",huffman->occurence);
    add2TreeList(&occurence,huffman);
  }
  return occurence;//the only element left is the huffman tree
}

Node* letterOccurrences(char* path){
  //here list is a degenerate tree
  FILE *file = fopen(path,"r");
  char buffer = getc(file);
  Node* list = createNode(buffer);
  list->occurence--;
  Node* temp;
  int added;
  while (buffer != EOF){
    printf("%c",buffer);
    temp = list;
    added = 0;
    do{
      if (buffer == temp->letter){
        temp->occurence++;
        added = 1;
      }
      temp = temp->next;
    }while(temp != NULL && added != 1 && temp->next != NULL);
    if (added == 0){
      add2TreeList(&list,createNode(buffer));//0 to add it at the left of the tree to create a degenerate
    }
    buffer = fgetc(file);
    /*if (buffer == EOF){
      printf("\nBonjour Antoine\n");
    }*/
  }
  printf("\n");
  return list;
}




int main(){
  text2binaryFile();
  char path[] = "input.txt";
  nCharInFile(path);
  char path2[] = "output.txt";
  nCharInFile(path2);
  Node* tree = letterOccurrences(path);
  //displayList(tree);
  //printf("\n");
  Tree huffman = createHuffman(tree);
  displayHuffman(huffman);
  return 0;
}
