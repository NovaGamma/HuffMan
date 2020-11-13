
#include <stdio.h>
#include <stdlib.h>

void convert_char_binary(char c, int* array){ 
    int n = (int)c;
   // printf("%d \n",n);
    for(int i=0;n>0;i++)    
        {    
        *(array+i)=n%2;    
        n=n/2;    
    }
}

int main(){
    char c = 'A';
    FILE *file;
    FILE *file2;
    file = fopen("input.txt","r");
    file2 = fopen("output.txt","w");
    int array[8];
    convert_char_binary(c,array);
    if(file != NULL) 
    {   
        while ((c = fgetc(file)) != EOF)
        {
            int array[8];
           // printf("\n  %c : ",c);
            convert_char_binary(c,array);
            for (int i = 0; i<7;i++){
                fprintf(file2,"%d",array[7-i]);
            }   
        }
    fclose(file);
    fclose(file2);
    }

    return 0;
}