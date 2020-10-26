#include <stdio.h>
#include <stdlib.h>
#include "list.c"


void text2binaryFile(){
  FILE *input;
  FILE *output;
  input = fopen("input.txt","r");
  output = fopen("output.txt","w");
  char buffer = fgetc(input);
  while (buffer != EOF){
    //convert the char to binary and save it in the output file
    char binary[5];
    for(int i = 7;i >= 0;i--){
      binary[7-i] = (buffer >> i) & 1 ? '1' : '0';
    }
    fprintf(output,"%s ",binary);
    buffer = fgetc(input);
  }
  fclose(input);
  fclose(output);
  FILE *output2 = fopen("output.txt","r");
  fclose(output2);
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


}

int main(){
  text2binaryFile();
  //char path[] = "input.txt";
  //nCharInFile(path);
  return 0;
}
