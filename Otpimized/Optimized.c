#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers/function.h"

int main(){
  char path[] = "input.txt";
  int length = 1;
  Node** array = letterOccurrences(path,&length);
  display(array,length-1);
  array_merge_sort(array,0,length-1);
  display(array,length-1);
  Tree huffman = createHuffman(array,length-1);
  displayHuffman(huffman);
  return 0;
}
