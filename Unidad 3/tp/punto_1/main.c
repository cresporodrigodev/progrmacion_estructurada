// Ingresar dos valores, indicar e imprimir si son iguales

#include <stdio.h>

int scan(char *message);

int main(){
    int x, y;
    char messageA[] = "Ingrese el primer valor.\n";
    char messageB[] = "Ingrese el segundo valor.\n";

    x = scan(messageA);
    y = scan(messageB);
    if (x == y){
        printf("%d y %d son iguales", x, y);
    }
    else{
        printf("%d y %d no son iguales", x, y);
    }
    return 0;
}


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