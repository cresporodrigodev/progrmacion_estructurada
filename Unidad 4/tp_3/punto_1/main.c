// Ingresar 25 números, calcular su promedio e imprimirlo

#include <stdio.h>
#include "../scan_int.h"
#define MAX 25


int main (){
    char messageA[] = "Ingrese un valor entero\n";
    int x, total, promedio;

    x = total = 0;

    for (int i = 0; i < MAX; i++){
        x = scan(messageA);
        total = total + x;
    }

    promedio = total / MAX;

    printf("El promedio de los %d numeros es: %d", MAX, promedio);

    return 0;
}

