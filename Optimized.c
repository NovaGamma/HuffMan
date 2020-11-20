#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

Tree getMinOccurrences(Tree list){
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

void removeFromTreeList(Tree* list, Tree node){
  Tree temp = *list;
  Node* prev = temp;
  if (temp->occurence == node->occurence && temp->left == node->left && temp->right == node->right && temp->letter == node->letter){
    (*list) = temp->next;
  }
  while (temp != NULL){
    if(temp->occurence == node->occurence && temp->left == node->left && temp->right == node->right && temp->letter == node->letter){
      prev->next = temp->next;
    }
    prev = temp;
    temp = temp->next;
  }
}

void createHuffman(Tree* occurence){
  while (nElement(*occurence) > 1){
    Tree min = getMinOccurrences(*occurence);//sending the address of the tree because the min will be removed
    removeFromTreeList(occurence,min);
    Tree min2 = getMinOccurrences(*occurence);
    removeFromTreeList(occurence,min2);
    Tree huffman = createHuffmanNode(min,min2);
    add2TreeList(occurence,huffman);
  }
}

void display(Node** array,int length){
  for(int i = 0;i<length;i++){
    printf("%c %d / ",array[i]->letter,array[i]->occurence);
  }
  printf("\n");
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

Node** letterOccurrences(char* path){
  //here list is a degenerate tree
  FILE *file = fopen(path,"r");
  char letter = getc(file);
  Node* node = createNode(letter);
  Node** array = (Node**)malloc(sizeof(Node*));
  array[0] = node;
  array[0]->occurence--;
  int length = 1;
  while (letter != EOF){
    printf("%c %d\n",letter,letter);
    int right = length-1;
    int left = 0;
    int pos;
    char temp;
    int added = 0;
    int before = -1;
    while (added == 0){
        pos = (left + right)/2;
        temp = array[pos]->letter;
        if (temp == letter){
          printf("add occurence odd\n");
          array[pos]->occurence++;
          added = 1;
          pos = -1;
        }
        else if (temp > letter){//we go to the left
            if (pos == 0){
              added = -1;
            }
            else if(array[pos-1]->letter < letter){
              added = -1;
            }
            else if (pos == before){
              added = -1;
              pos--;
            }
            else{
                before = pos;
                right = pos - 1;
              }
          }
        else if(temp < letter){ // we go to the right
            if (pos == length-1){
              pos++;
              added = -1;
            }
            else if(array[pos+1]->letter > letter){
              added = -1;
              pos++;
            }
            else{
                left = pos + 1;
              }
          }
    }
    if (pos != -1){
        printf("Add node for letter : %c at pos : %d\n",letter,pos);
        array = insert(array,length,letter,pos);
        length++;
    }
    display(array,length);
    letter = fgetc(file);
    /*if (buffer == EOF){
      printf("\nBonjour Antoine\n");
    }*/
  }
  printf("\n");
  return array;
}

void text2compressedFile(){
    FILE *input;
    FILE *output;
    FILE * dic;
    input = fopen("input.txt","r");
    output = fopen("output.txt","w");
    dic = fopen("dico.txt", "r");
    char bufferIn = fgetc(input);
    char bufferDic = fgetc(dic);
    while (bufferIn != EOF){
        if (bufferIn == '\n' || bufferIn == ' '){
            while (bufferDic != ':'){        //To verify if it's actually the term we're looking at and not a random space or return
                while (bufferDic != bufferIn){
                    bufferDic = fgetc(dic);
                }
                fseek(dic, 1, SEEK_CUR);
                bufferDic = fgetc(dic);
            }
            fseek(dic, 1, SEEK_CUR);
        }
        else {
            while (bufferDic != bufferIn){
                bufferDic = fgetc(dic);
            }
            fseek(dic, 3, SEEK_CUR);
        }
        bufferDic = fgetc(dic);
        while (bufferDic != '\n'){
            fprintf(output, "%c", bufferDic);
            bufferDic = fgetc(dic);
        }
        fseek(dic, 0, SEEK_SET);
        bufferDic = fgetc(dic);
        bufferIn = fgetc(input);
    }
    fclose(input);
    fclose(output);
    fclose(dic);
}

void get_path(Tree tree, char* isRightChild, char* path, int path_length){

    if (tree != NULL )
    {
        if (isRightChild != "\0"){   //it would mean we're not at the root
          char* temp = (char*)malloc(sizeof(char)*(path_length + 1));
          strcpy(temp,path);
          strcat(temp,isRightChild);
          path = temp;
        }
        if (tree->right == NULL && tree->left == NULL) //if leaf
        {
            FILE* dico = fopen("dico.txt","a+"); //adding at the end of the file
            fprintf(dico,"%c : %s\n", tree->letter,path);
            //printf("%c%s\n", tree->letter,path);  //(just to check)
            fclose(dico);
            free(path);
        }

        else {
            get_path(tree->left, "0", path, path_length + 1);
            get_path(tree->right, "1", path, path_length + 1);
        }
    }
    else
        return NULL;
}

void createDico(Node* t)
{
  char* path = "\0";
  FILE* dico = fopen("dico.txt","w");
  fclose(dico);//opening and closing the file in write mode to remove previous writing
  get_path(t,"\0",path,0);
}

int main(){
  text2binaryFile();
  char path[] = "input.txt";
  nCharInFile(path);
  char path2[] = "output.txt";
  Node** tree = letterOccurrences(path);
  //displayList(tree);
  //printf("\n");
  /*createHuffman(&tree);
  //displayHuffman(tree);
  createDico(tree);
  text2compressedFile();
  nCharInFile("binary.txt");
  nCharInFile(path2);*/
  return 0;
}
