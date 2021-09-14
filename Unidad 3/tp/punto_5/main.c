// Ingresar los tres lados de un triángulo
// e indicar que tipo de triángulo es
// equilatero --> a = b = c
// isósceles --> a = b <> c
// escaleno --> a <> b <> c

#include <stdio.h>
#include "../scan_int.h"

int main(){
    int a, b, c;
    char messageA[] = "Ingrese el lado A.\n";
    char messageB[] = "Ingrese el lado B.\n";
    char messageC[] = "Ingrese el lado C.\n";
    char messageD[] = "El triangulo es:";

    a = scan(messageA);
    b = scan(messageB);
    c = scan(messageC);

    if (a == b && b == c && c == a) printf("%s Equilatero", messageD);
    else
    if (a != b && b != c && c != a) printf("%s Escaleno", messageD);
    else printf("%s Isoceles", messageD);

    return 0;
}