#ifndef FUNCTION_H
#define FUNCTION_H
#include "tree.h"
int nCharInFile(char* path);
void display(Node** array,int length);
void array_merge(Node** array, int first, int medium, int last);
void array_merge_sort(Node** array, int first, int last);
Node** letterOccurrences(char* path);

#endif
