// Ingresar tres valores, sumarlos, calcular el promedio
// e indicar e imprimir cuál de estos 
// valores es mayor al promedio

#include <stdio.h>
#include "../scan_int.h"

int main(){
    int a, b, c, tot;
    double prom, max;
    char messageA[] = "Ingrese el primer valor.\n";
    char messageB[] = "Ingrese el segundo valor.\n";
    char messageC[] = "Ingrese el tercer valor.\n";

    a = scan(messageA);
    b = scan(messageB);
    c = scan(messageC);

    max = 3;
    tot = a + b + c;
    prom = tot/max;

    printf("El promedio es: %.2f\n", prom);
    printf("Los valores mayores al promedio son:\n");
    if (a > prom) printf("- %d\n", a);
    if (b > prom) printf("- %d\n", b);
    if (c > prom) printf("- %d\n", c);

    return 0;
}