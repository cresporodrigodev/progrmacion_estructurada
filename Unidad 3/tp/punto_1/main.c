#include <stdio.h>

int scan(char *message);

int main() {
    int x;
    char messageA[] = "Ingrese el valor entero.\n";
    char messageB[] = "El valor ingresado es:";
    char messageC[] = "y es un numero";
    char mPositive[] = "positivo";
    char mNegative[] = "negativo";
    char mZero[] = "cero";

    printf("Bienvenido\n");
    x = scan(messageA);

    if (x > 0){
        printf("%s %d %s %s.", messageB, x, messageC,mPositive);
    }
    else if (x < 0){
        printf("%s %d %s %s.", messageB, x, messageC,mNegative);
    }
    else{
        printf("%s %d %s %s.", messageB, x, messageC,mZero);
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
