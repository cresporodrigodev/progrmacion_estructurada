// Ingresar N valores, calcular e imprimir el promedio de:
// - positivos
// - negativos
// - cantidad de ceros

#include <stdio.h>
#include "../scan_int.h"
#define TRUE 1
#define FALSE 0

int isPositive (float x);
int isNegative (float x);
int scanInt(char *message);
float scanFloat(char *message, int i);

int main () {
    float number, totalPositives, totalNegatives;
    int countPositives, countNegatives, countZeros, max;
    char maxRequest[] = "Ingrese la cantidad total de valores que desea\n";
    char numberRequest[] = "Ingrese el valor";    
    
    countPositives = countNegatives = countZeros = number = 0;
    totalPositives = totalNegatives = 0;

    max = scanInt(maxRequest);

    for (int i = 0; i < max; i++){
        number = scanFloat(numberRequest, i + 1);
        
        if (isPositive(number)){
            countPositives++;
            totalPositives += number;
        }
        else if (isNegative(number)){
            countNegatives++;
            totalNegatives += number;
        }
        else countZeros++;
    }

    printf("- La cantidad de ceros es: %d\n", countZeros);
    printf("- El promedio de positivos es: %.2f\n", totalPositives / countPositives);
    printf("- El promedio de negativos es: %.2f\n", totalNegatives / countNegatives);

    return 0;
}

int isPositive (float x){
    int status = FALSE;
    if (x > 0) status = TRUE;
    return status;
}

int isNegative (float x){
    int status = FALSE;
    if (x < 0) status = TRUE;
    return status;
}

int scanInt(char *message){
    char err[] = "Debe ingresar un valor positivo.\n";
    int q, input;
    do{
        printf("%s", message);
        fflush(stdout);
        fflush(stdin);
        input = scanf("%d", &q);
        if (q < 0){
            printf("%s", err);
        }
        
    }while (q < 0);
}

float scanFloat(char *message, int i){
    char errA[] = "Debe ingresar un valor numerico\n";
    float q = 0;
    int input;

    do{
        printf("%s %d\n", message, i);
        fflush(stdout);
        fflush(stdin);
        input = scanf("%f", &q);
        
        if (input != 1){
            printf("%s", errA);
            fflush(stdout);
        }
        
    } while (input != 1);

    return q;
}