#include <stdio.h>

int scan(char *message);

int main(){
    int x, y, z, w;
    char messageA[] = "Ingrese el valor de A.\n";
    char messageB[] = "Ingrese el valor de B.\n";
    char messageC[] = "Ingrese el valor de C.\n";
    x = scan(messageA);
    y = scan(messageB);
    z = scan(messageC);
    w = x + y;
    w = w + z;
    printf("La suma de A + B + C es:%d\n", w);

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
