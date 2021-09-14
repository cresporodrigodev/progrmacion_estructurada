#include "scan_float.h"
#include <stdio.h>

float scan(char *message){
    char err[] = "Debe ingresar un valor entero.\n";
    float q;

    printf("%s", message);
    fflush(stdout);
    fflush(stdin);
    float input = scanf("%f", &q);
    if (input == 1){
        return q;
    }
    else{
        printf("%s", err);
        scan(message);
    }
}