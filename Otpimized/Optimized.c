#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "headers/function.h"

int main(){
  clock_t begin = clock();
  char path[] = "input.txt";
  int length = 1;
  Node** array = letterOccurrences(path,&length);
  array_merge_sort(array,0,length-1);
  Tree huffman = createHuffman(array,length-1);
  TreeDic* dico =  Huffman_Into_Avl_Wrapper(huffman);
  compressText(path,*dico);
  clock_t end = clock();
  printf("Compression done !\n");
  printf("Time needed = %f",(double)(end - begin) / CLOCKS_PER_SEC);
  return 0;
}
