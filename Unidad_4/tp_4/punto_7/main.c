// Ingresar N temperaturas , indicar e imprimir la máxima y mínima

#include <stdio.h>

int scanIntPositive(char *message);
float scanFloat(char *message, int i);

int main(){
    int n;
    float max, min, input, last;
    char nRequest[] = "Ingrese la cantidad de temperaturas\n";
    char inputRequest[] = "Ingrese la temperatura";
    
    max = min = input = last = 0;

    n = scanIntPositive(nRequest);

    for (int i = 0; i < n; i++){
        input = scanFloat(inputRequest, i + 1);

        if (input > max) max = input;
        if (input < min) min = input;
    }

    printf("La temperatur maxima es: %.2f\n", max);
    printf("La temperatur minima es: %.2f\n", min);
    
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

int scanIntPositive(char *message){
    char err[] = "Debe ingresar un valor positivo.\n";
    int q, input;
    do{
        printf("%s", message);
        fflush(stdout);
        fflush(stdin);
        input = scanf("%d", &q);
        if (q <= 0){
            printf("%s", err);
            fflush(stdout);
        }
        
    }while (q <= 0);
}
