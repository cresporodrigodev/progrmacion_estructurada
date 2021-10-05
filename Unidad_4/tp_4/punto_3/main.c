// Ingresar valores hasta uno = 0, indicar e imprimir la cantidad
// de números ingresados y su promedio

#include <stdio.h>

float scanFloat(char *message);

int main(){
    int countNumber;
    float number, total;
    char request[] = "Ingrese un valor numerico.\n";
    number = countNumber = 0;

    do{
        number = scanFloat(request);
        if (number == 0) continue;

        countNumber++;
        total += number;
    } while(number != 0);

    printf("- La cantidad de valores ingresados es: %d", countNumber);
    printf("- El promedio de valores ingresados es: %.2f", (total / countNumber) * 100);
    return 0;
}

float scanFloat(char *message){
    char errB[] = "Debe ingresar un valor numerico\n";
    float q = 0;
    int input;

    do{
        printf("%s", message);
        fflush(stdout);
        fflush(stdin);
        input = scanf("%f", &q);
        
        if (input != 1){
            printf("%s", errB);
            fflush(stdout);
        }
        
    } while (input != 1);

    return q;
}