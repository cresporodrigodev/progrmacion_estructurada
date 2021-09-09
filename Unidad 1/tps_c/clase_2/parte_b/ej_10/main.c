#include <stdio.h>
#define BASE 500
#define PLUS_FIJO 50
#define COMISION 0.10

int scan(char *message);

int main(){
    int s, p, q, p_total, plus_porcent, plus_const, plus_total;
    char messageA[] = "Ingrese el valor del vehiculo.\n";
    char messageB[] = "Ingrese la cantidad vendida.\n";
    p = scan(messageA);
    q = scan(messageB);
    p_total = p * q;
    plus_porcent = p_total * COMISION;
    plus_const = q * PLUS_FIJO;
    plus_total = plus_porcent + plus_const;
    s = BASE + p_total + plus_total;
    printf("El sueldo mensual del operario es: $%d\n", s);

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