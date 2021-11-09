// Cree una matriz de enteros de 3 x 3.
// Inicialícela en base a la siguiente tabla:
// 100 74 99
// 11 36 68
// 23 9 81

#include <stdio.h>
#define arrayRowSize 3
#define arrayColSize 3
int main(){
    int localArray[arrayRowSize][arrayColSize] = {
        {100, 74, 99},
        {11, 36, 68},
        {23, 9, 81}
    };

    for (int i = 0; i < arrayRowSize; i++){
        for(int j = 0; j < arrayColSize; j++){
            printf("%d\t", localArray[i][j]);
        }
        printf("\n");
    }
   
}