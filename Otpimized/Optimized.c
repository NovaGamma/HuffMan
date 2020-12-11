#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers/input.h"
#include "headers/function.h"



int main(){
    int select = 0;

    printf("*************************************************************************************************\n");
    printf("   Welcome in the text files compression / decompression tool made by\n");
    printf("Anne HIRIART, Elvin AUPIAIS-BERTHY, Thomas CASASNOVAS and Guillaume GOMEZ.\n\n");
    printf("*************************************************************************************************\n");

    do {
        printf("To compress a text file, make sure it is in the same folder as the program, that\nits name is \"input.txt\" and type 1.\n");
        printf("If you rather want to decompress a file, make sure it is in the same folder\n as the program, that its name is \"output.txt\" and type 2.\n\n");
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
