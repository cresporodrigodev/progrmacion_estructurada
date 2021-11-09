#include <stdio.h>

int scanIntHandler(char *message, int range[2]);

int main(){
    int array[2] = {5, 10};
    char mes[] = "Ingrese un num entre 5 y 10"; 

    int x = scanIntHandler(mes, array);

    return 0;
}

int scanIntHandler(char *message, int range[2]){
    char errType[] = "Debe ingresar un valor numerico.\n";
    char errData[] = "El rango permitido es:";
    int q, input, max, min;
    q = input = 0;

    min = range[0];
    max = range[1];

    if (max == min){
        do{
            printf("%s %d.\n", message);
            fflush(stdout);
            fflush(stdin);
            input = scanf("%d", &q);
            if (input != 1){
                printf("%s", errType);
                fflush(stdout);
            }
        } while (input != 1);
    }
    else{
        int err = 0;
        do{
            printf("%s %d.\n", message, i);
            fflush(stdout);
            fflush(stdin);
            
            input = scanf("%d", &q);
            
            if (input != 1){
                err = 1;
                printf("%s", errType);
                fflush(stdout);
            }

            if (min < q || max > q){
                err = 1;
                printf("%s %d - %d.\n", errData, min, max);
                fflush(stdout);
            }
        } while (err != 0);
    }

    return q;
}

void scanInt(char *message, int *input, int *q){
    printf("%s\n", message);
    fflush(stdout);
    fflush(stdin);
    input = scanf("%d", &q);
}