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

Node* getMinOccurrences(Node* list){
    if(list != NULL){
      Node* temp = list;
      Node* min = list;
      while (temp != NULL){
        if (temp->occurence < min->occurence){
          min = temp;
        }
        temp = temp->left;
      }
      return min;
    }
}

Tree createHuffman(Tree occurence){
  while (getDepth(occurence) > 0){

    Tree min = getMinOccurrences(occurence);
    if(min->occurence)
  }
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
      temp = temp->left;
    }while(temp != NULL && added != 1 && temp->left != NULL);
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
  displayTree(tree);
  return 0;
}
