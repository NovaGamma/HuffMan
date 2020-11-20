#include <stdlib.h>
#include <stdio.h>
#include "tree.c"


void display(char* array,int length){
  for(int i = 0;i<length;i++){
    printf("%c ",array[i]);
  }
  printf("\n");
}

char* insert(char* array,int length,char letter,int pos){
  char* inserted = (char*)malloc(sizeof(char)*(length+1));
  char NodeLetter = letter;
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

int main(){
FILE *file = fopen("input.txt","r");
char letter = getc(file);
char node = letter;
char* array = (char*)malloc(sizeof(char));
array[0] = node;
int length = 1;
while (letter != EOF){
  printf("%c %d\n",letter,letter);
  int pos;
  int left = 0;
  int right = length - 1;
  char temp;
  int added = 0;
  while (added == 0){
    pos = (left + right)/2;
    temp = array[pos];
    if(array[pos] == letter){
      added = 1;
      printf("add occurence\n");
    }
    else if (temp < letter){
      left = pos + 1;
    }
    else if (temp > letter){
      right = pos - 1;
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
}
