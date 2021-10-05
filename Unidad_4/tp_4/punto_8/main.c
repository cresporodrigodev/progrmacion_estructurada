// Ingresar temperaturas hasta una temperatura igual a 1000
// indicar e imprmir la mayor y menor

#include <stdio.h>
#define LIMIT 1000

float scanFloat(char *message, int i);

int main(){
    float max, min, input;
    char inputRequest[] = "Ingrese la temperatura";
    
    max = min = input = 0;

    for (int i = 0; input != LIMIT; i++){
        input = scanFloat(inputRequest, i + 1);
        if (i == 0){
            max = input;
            min = input;
        }
        else if (input != LIMIT){
            if (input > max) max = input;
            if (input < min) min = input;
        }
    }

    if (max == min) printf("No se ingresaron temperaturas validas");
    else{   
        printf("La temperatur maxima es: %.2f\n", max);
        printf("La temperatur minima es: %.2f\n", min);
    }
    return 0;    
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
