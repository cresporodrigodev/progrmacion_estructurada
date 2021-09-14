// Ingresar cuatro valores,
// sumar el 1ro y el 2do, el 3ro y el 4to,
// indicar e imprimir cuál de estas sumas es mayor

#include <stdio.h>
#include "../scan_int.h"

int main(){
    int a, b, c, d, ab, cd;
    char messageA[] = "Ingrese el primer valor.\n";
    char messageB[] = "Ingrese el segundo valor.\n";
    char messageC[] = "Ingrese el tercer valor.\n";
    char messageD[] = "Ingrese el cuarto valor.\n";
    char messageE[] = "La mayor suma es:";

    a = scan(messageA);
    b = scan(messageB);
    c = scan(messageC);
    d = scan(messageD);

    ab = a + b;
    cd = c + d;

    if (ab != cd){
        if (ab > cd) printf("%s ab = %d", messageE, ab);
        else printf("%s cd = %d", messageE, cd);
    }
    else printf("a + b es igual que c + d\n");

    return 0;
}