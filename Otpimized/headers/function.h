#ifndef FUNCTION_H
#define FUNCTION_H
#include "queue.h"

//int nCharInFile(char* path);
void display(Node** array,int length);
void array_merge(Node** array, int first, int medium, int last);
void array_merge_sort(Node** array, int first, int last);
Node** letterOccurrences(char* path,int* length);
Tree createHuffman(Tree* array, int len);
void compressText(char* path,TreeDic dico);
void printDic(TreeDic dic, FILE* output);
Tree create_Huffman_from_dic(FILE* input);
void create_Huffman_from_dic_util(FILE* input, Tree tree);
void decompress(Tree huffman, FILE* input, FILE* output);

#endif
