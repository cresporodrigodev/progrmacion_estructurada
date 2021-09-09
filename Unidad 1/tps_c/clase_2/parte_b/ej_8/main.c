#include <stdio.h>

int scan(char *message);

int main(){
    int h, t, s;
    char messageA[] = "Ingrese el valor de la hora.\n";
    char messageB[] = "Ingrese la canitdad de horas trabajas\n";
    h = scan(messageA);
    t = scan(messageB);
    s = h * t;
    printf("El sueldo del operario es: $%d\n", s);

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
