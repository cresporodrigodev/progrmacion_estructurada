// Cree un vector de 10 posiciones, pida al usuario que
// ingrese los 10 valores y luego muéstrelo de manera inversa

#include <stdio.h>

float scanFloat(char *message, int i);

int main(){
    const int localArraySize = 10;
    float localArray[localArraySize];
    char floatRequest[] = "Ingrese el valor numero";

    for (int i = 0; i < localArraySize; i++){
        
        float userInput = scanFloat(floatRequest, i + 1);

        localArray[i] = userInput; 
    }

    for (int i = localArraySize; i > 0; i--){
        int iAux = i - 1;
        printf("- Posicion de array %d\t- Posicion de ingreso %d\t- valor %.2f\n", iAux, i, localArray[iAux]);
        fflush(stdout);
    }
}

float scanFloat(char *message, int i){
    char errType[] = "Debe ingresar un valor numerico.\n";
    float q;
    int input;
    do
    {
        printf("%s %d\n", message, i);
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