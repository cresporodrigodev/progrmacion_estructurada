#include <stdio.h>
#include <math.h>

int scan(char *message);
double diagonal(int a, int b);

int main(){
    int a, b, s, p;
    double d;
    char messageA[] = "Ingrese el valor del Lado A\n";
    char messageB[] = "Ingrese el valor del Lado B.\n";
    a = scan(messageA);
    b = scan(messageB);
    p = 2 * (a + b);
    s = a * b;
    d = diagonal(a, b);
    printf("La superficie del rectuangulo es:%d\n", s);
    printf("La diagonal del rectuangulo es:%.2f\n", d);    
    printf("El perimetro del rectuangulo es:%d\n", p);

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

double diagonal(int a, int b){
// - d = raiz(a'2 + b'2)
    double d, a2, b2;
    
    a2 = pow(a, 2);
    b2 = pow(b, 2);
    d = sqrt(a2 + b2);
    return d;
}
