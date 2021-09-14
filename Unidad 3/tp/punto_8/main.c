// Ingresar la edad y la altura de dos personas,
// indicar e imprimir la estatura del de mayor 
// edad

#include <stdio.h>
#include "../scan_float.h"

int main(){
    int age [2];
    double height [2];
    char messageA[] = "Ingrese la edad de la primera persona\n";
    char messageB[] = "Ingrese la altura de la primera persona\n";
    char messageC[] = "Ingrese la edad de la segunda persona\n";
    char messageD[] = "Ingrese la altura de la segunda persona\n";
    char messageE[] = "La altura de la";

    age [0] = scan(messageA);
    height [0] = scan(messageB);
    age [1] = scan(messageC);
    height [1] = scan(messageD);

    if (age[0] != age [1]){
        if (age[0] > age [1]) printf("%s primera persona es: %.2f", messageE, height[0]);
        else printf("%s segunda persona es: %.2f", messageE, height[1]);
    }
    else printf("Ambas personas tienen la misma edad.\n");

    return 0;
}