#include <stdio.h>
#include <stdlib.h>
#include "list.c"
#include "tree.c"


void text2binaryFile(){
  FILE *input;
  FILE *output;
  input = fopen("input.txt","r");
  output = fopen("output.txt","w");
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
  FILE *output2 = fopen("output.txt","r");
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

Element* letterOccurrences(char* path){
  FILE *file = fopen(path,"r");
  char buffer = getc(file);
  Element* list = createElement(buffer);
  list->occurence--;
  Element* temp;
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
      addElement(&list,createElement(buffer));
    }
    buffer = fgetc(file);
    /*if (buffer == EOF){
      printf("\nBonjour Antoine\n");
    }*/
  }
  return list;
}




int main(){
  text2binaryFile();
  char path[] = "input.txt";
  nCharInFile(path);
  char path2[] = "output.txt";
  nCharInFile(path2);
  Element* list = letterOccurrences(path);
  displayList(list);
  return 0;
}
