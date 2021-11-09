// Ingrese 10 valores en un vector de enteros.
// Sume todos los valores muestre el resultado.
// a. ¿Cuántas líneas de código necesito para desarrollar
// el programa sin utilizar ciclos 
// de repetición?
// b. Implemente la misma solución con ciclos de repetición,
// y responda ¿Cuántas líneas de código necesito en esta segunda versión?

#include <stdio.h>
#define ARRAYSIZE 10

int withFor(int array[]);
int withoutFor(int array[]);
int scanInt(char *message, int i);

int main(){
    int array[ARRAYSIZE], total;
    char messageRequest[] = "Ingrese el valor numero";

    for (int i = 0; i < ARRAYSIZE; i++){
        int input = scanInt(messageRequest, i + 1);
        array[i] = input;
    }

    total = withoutFor(array);

    printf("El total sin for es: %d\n", total);

    total = withFor(array);

    printf("El total con for es: %d\n", total);
}

int withoutFor(int array[]){
    int acumulator, i;
    acumulator = i = 0;

    acumulator += array[i];
    i++;
    acumulator += array[i];
    i++;
    acumulator += array[i];
    i++;
    acumulator += array[i];
    i++;
    acumulator += array[i];
    i++;
    acumulator += array[i];
    i++;
    acumulator += array[i];
    i++;
    acumulator += array[i];
    i++;
    acumulator += array[i];
    i++;
    acumulator += array[i];
    i++;

    return acumulator;
}

int withFor(int array[]){
    int acumulator = 0;

    for (int i = 0; i < ARRAYSIZE; i++){
        int x = array[i];
        acumulator += x;
    }

    return acumulator;
}

int scanInt(char *message, int i){
    char errType[] = "Debe ingresar un valor numerico.\n";
    int q;
    int input;
    do
    {
        printf("%s %d\n", message, i);
        fflush(stdout);
        fflush(stdin);
        input = scanf("%d", &q);
        if (input != 1)
        {
            printf("%s", errType);
            fflush(stdout);
        }

    } while (input != 1);

    return q;
}