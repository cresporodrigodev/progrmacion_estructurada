// Ingresar 10 valores, indicar e imprimir cuántos son positivos,
// cuántos negativos y cuántos ceros

#include <stdio.h>
#include "../scan_int.h"
#define MAX 10

int sign (int x);

int main () {
    int positives, negatives, zeros, x, result;
    char messageA[] = "Ingrese un valor entero\n";    
    
    x = positives = negatives = zeros = result = 0;

    for (int i = 0; i < MAX; i++)
    {
        x = scan(messageA);
        result = sign(x);

        switch (result)
        {
        case 1: zeros = zeros + 1;
            break;
        case 2: positives = positives + 1;
            break;
        case 3: negatives = negatives + 1;
            break;
        default: printf("Error\n");
            break;
        }
    }

    printf("Los totales son:\n");
    printf("- Ceros: %d\n", zeros);
    printf("- Positivos: %d\n", positives);
    printf("- Negativos: %d\n", negatives);

    return 0;
}

int sign (int x) {
    const int zero = 1;
    const int positive = 2;
    const int negative = 3;
    if (x != 0){
       if (x > 0) return positive;
       else return negative;
    }
    else return zero; 
}