#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

void get_path(Node* t, char isRightChild, char *path, int path_length){

    if (t != NULL )
    {
        if (right != 2)   //it would mean we're at the root 
            *(path + path_length - 1) = isRightChild; //is this node at the left or right of the previous one? //-1 since we didn't take the root

        if (t->right == NULL && t->left == NULL) //if leaf
        {
            FILE* dico = fopen("dico.txt","a+"); //adding at the end of the file
            fprintf(dico,"%c%s", tree->letter,path);
            printf("%c%s", tree->letter,path);  //(just to check)
            *path = '\0';  //reinitializing path
            fclose(dico);
        }

        else {
            get_path(t->left, 0, path, path_length + 1);
            get_path(t->right, 1, path, path_length + 1);
        }
    }
    else
        return NULL;
}

void createDico(Node* t)
{
    char path[20];
    get_path(t,2,path,0);
}