#include <stdio.h>
#include <stdlib.h>


int function(){
  FILE* input = fopen("intput.txt","r");
  FILE* output = fopen("output.txt","w");
  char buffer[] = "test";
  fprintf(output,"%s\n",buffer);
  fclose(input);
  fclose(output);
  return 0;
}
int main(){
  function();
  return 0;
}
