#include <stdio.h>

int scan(char *message);

int main(){
    int x, y, z, w;
    char messageA[] = "Ingrese el valor del lado A.\n";
    char messageB[] = "Ingrese el valor del lado B.\n";
    char messageC[] = "Ingrese el valor del lado C.\n";
    x = scan(messageA);
    y = scan(messageB);
    z = scan(messageC);
    w = x + y + z;
    printf("El per+imetro del triangulo es:%d\n", w);

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