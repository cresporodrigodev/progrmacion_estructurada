#include "scan_int.h"
#include <stdio.h>

int scan(char *message){
    char err[] = "Debe ingresar un valor entero.\n";
    int q;

    printf("%s", message);
    fflush(stdout);
    fflush(stdin);
    int input = scanf("%d", &q);
    if (input == 1){
        return q;
    }
    else{
        printf("%s", err);
        scan(message);
    }
}