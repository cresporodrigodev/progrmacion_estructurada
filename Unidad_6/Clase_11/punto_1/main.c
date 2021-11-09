// Cree un vector de enteros de 5 posiciones,
// inicializándolo con los valores del 10,100,94,84,11.

#include <stdio.h>

int main(){
    
    int localArray[5] = {10, 100, 94, 84, 11};
    int localArraySize = (int)(sizeof(localArray)/sizeof(localArray[0])); 

    for (int i = 0; i < localArraySize; i++){
        printf("- Posicion %d\t Valor %d\n", i, localArray[i] );
        fflush(stdout);
    }
}