#include <stdio.h>

int scan(char *message);

int main(){
    int a, b, s, p, r;
    char messageA[] = "Ingrese el valor de A.\n";
    char messageB[] = "Ingrese el valor de B.\n";
    a = scan(messageA);
    b = scan(messageB);
    s = a + b;
    p = a * b;
    r = a - b;
    printf("La suma de A+B es:%d\n", s);
    printf("El producto de A y B es:%d\n", p);
    printf("La resta de A-B es:%d\n", r);

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
