// Ingresar dos valores y realizar e imprimir el producto
// si el 1ro es mayor al 2do, si son 
// iguales solo indicarlo

#include <stdio.h>
#include "../scan_int.h"

int main(){
    int x, y;
    char messageA[] = "Ingrese el primer valor.\n";
    char messageB[] = "Ingrese el segundo valor.\n";

    x = scan(messageA);
    y = scan(messageB);

    if(x > y){
        printf("El producto del primero por el segundo es:%d", x*y);
    }
    else if(x == y){
        printf("Ambos valores son iguales");
    }

    return 0;
}