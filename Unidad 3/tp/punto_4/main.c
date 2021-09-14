// Ingresar dos valores y realizar e
// imprimir la resta del mayor menos el menor

#include <stdio.h>
#include "../scan_int.h"

int higher(int x, int b);

int main(){
    int x, y, high;
    char messageA[] = "Ingrese el primer valor.\n";
    char messageB[] = "Ingrese el segundo valor.\n";
    char messageC[] = "El resultado del mayor menos el menor es:";

    x = scan(messageA);
    y = scan(messageB);

    high = higher(x, y);

    if (high == 0) printf("Los valores son iguales\n");
    else if(high == 1){
        printf("%s %d\n", messageC, x - y);
    }
    else printf("%s %d\n", messageC, y - x);

    return 0;
}

int higher(int x, int y){
    // 0 --> x = y
    // 1 --> x > y
    // 2 --> y > x
    if (x != y){
        if (x > y) return 1;
        else return 2;
    }
    else return 0;
}