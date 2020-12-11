#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "headers/function.h"

void compression(){
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
    printf("Time needed = %f\n",(double)(end - begin) / CLOCKS_PER_SEC);
}

void decompression(){
    clock_t begin = clock();
    // we open the input file here to prevent going through the dictionary twice
    FILE* input = fopen("output.txt", "r");
    FILE* output = fopen("decompressed.txt", "w");
    Tree huffman = create_Huffman_from_dic(input);
    decompress(huffman, input, output);
    fclose(input);
    fclose(output);
    clock_t end = clock();
    printf("Decompression done !\n");
    printf("Time needed = %f\n",(double)(end - begin) / CLOCKS_PER_SEC);
}

int main(){
    decompression();
  return 0;
}
