// Desarrolle un programa que pida al usuario los datos de
// dos matrices de 2x2, y calcule y muestre su producto.
// Investigue como obtener el producto de dos matrices.

#include <stdio.h>
#define ARRAY_LEN 2

void printArray2x2(float (*array)[ARRAY_LEN]);
float scanFloat(char *message, char arrayId, int i, int j);
void buildArray2x2(char arrayId, float (*array)[ARRAY_LEN]);
void array2x2Product(float (*arrayA)[ARRAY_LEN], float (*arrayB)[ARRAY_LEN], float (*arrayProduct)[ARRAY_LEN]);
float scanFloat(char *message, char arrayId, int i, int j);

int main(){
    float arrayA[ARRAY_LEN][ARRAY_LEN] = {0};
    float arrayB[ARRAY_LEN][ARRAY_LEN] = {0};
    float arrayResult[ARRAY_LEN][ARRAY_LEN] = {0};

    buildArray2x2('A', arrayA);
    buildArray2x2('B', arrayB);

    printf("La matriz A es:\n");
    printArray2x2(arrayA);
    printf("La matriz B es:\n");
    printArray2x2(arrayB);

    // Ojo!! La múltiplicación de matrices no es conmutativa
    array2x2Product(arrayA, arrayB, arrayResult);
    printf("El producto de A x B es:\n");
    printArray2x2(arrayResult);

    array2x2Product(arrayB, arrayA, arrayResult);
    printf("El producto de B x A es:\n");
    printArray2x2(arrayResult);

    return 0;
}

void printArray2x2(float (*array)[ARRAY_LEN]){
    for (int i = 0; i < ARRAY_LEN; i++){
        for (int j = 0; j < ARRAY_LEN; j++){
            printf("%.1f \t", array[i][j]);
        }
        printf("\n");
    }
}

void buildArray2x2(char arrayId, float (*array)[ARRAY_LEN]){
    char messageRequest[] = "Ingrese el valor de la matriz";

    for (int i = 0; i < ARRAY_LEN; i++) {
        for(int j = 0; j < ARRAY_LEN; j++) {
            float input = scanFloat(messageRequest, arrayId, i, j);
            array[i][j] = input;
        }
    }
}

void array2x2Product(float (*arrayA)[ARRAY_LEN],float (*arrayB)[ARRAY_LEN],float (*arrayProduct)[ARRAY_LEN]){
    // A * B = | C11    C12 |
    //         | C21    C22 |
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            arrayProduct[i][j] = 0;
        }
    }

    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            for (int k = 0; k < 2; k++){
                arrayProduct[i][j] += arrayA[i][k] * arrayB[k][j];
            }
        }
    }

}

float scanFloat(char *message, char arrayId, int i, int j){
    char errType[] = "Debe ingresar un valor numerico.\n";
    float q;
    int input;
    do
    {
        printf("%s %c fila %d, columna %d\n", message, arrayId, i, j);
        fflush(stdout);
        fflush(stdin);
        input = scanf("%f", &q);
        if (input != 1)
        {
            printf("%s", errType);
            fflush(stdout);
        }

    } while (input != 1);

    return q;
}