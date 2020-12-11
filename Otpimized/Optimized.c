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
    if (array == NULL) {
        return;
    }
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
    if (file == NULL) {
      printf("ERREUR\nFICHIER \"output.txt\" NON TROUVE\n");
      return;
    }
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
    int select = 0;

    printf("*************************************************************************************************\n");
    printf("   Welcome in the text files compression / decompression tool made by\n");
    printf("Anne HIRIART, Elvin AUPIAIS-BERTHY, Thomas CASASNOVAS and Guillaume GOMEZ.\n\n");
    printf("*************************************************************************************************\n");

    do {
        printf("To compress a text file, make sure it is in the same folder as the program, that\nits name is \"input.txt\" and type 1.\n");
        printf("If you rather want to decompress a file, make sure make sure it is in the same folder\n as the program, that its name is \"output.txt\" and type 2.\n\n");
        printf("Your choice : ");
        scanf(" %d%*c", &select);
        printf("\n\n");
        switch (select) {
            case 1:
                compression();
                break;
            case 2:
                decompression();
                break;
            default:
                select = 0;
        }
    } while(select == 0);
  return 0;
}
