#include <stdio.h>
#include <math.h>

int scan(char *message);
double hipotenusa(int a, int b);
int superficie(int a, int b);

int main(){
    int a, b, s, p;
    double h;
    char messageA[] = "Ingrese el valor del cateto A\n";
    char messageB[] = "Ingrese el valor del cateto B.\n";
    a = scan(messageA);
    b = scan(messageB);
    s = superficie(a, b);
    h = hipotenusa(a, b);
    p = a + b + h;
    printf("La superficie del triangulo es:%d\n", s);
    printf("La hipotenusa del triangulo es:%.2f\n", h);    
    printf("El permetro del triangulo es:%d\n", p);

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

double hipotenusa(int a, int b){
// - hipotenusa = h = raiz(a'2 + b'2)
    double h, a2, b2;
    
    a2 = pow(a, 2);
    b2 = pow(b, 2);
    h = sqrt(a2 + b2);
    return h;
}

int superficie(int a, int b){
// - superficie (a.b)/2
    int s = ((a*b)/2);
    return s;
}