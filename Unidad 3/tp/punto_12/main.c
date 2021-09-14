// Sobre los datos del ejercicio anterior imprimir los sueldos
// de los empleados con más de 5 años de antigüedad


#include <stdio.h>
#include "../scan_int.h"

int main(){
    int salary, category, antiquity, bonus;
    const int plus = 50; 
    char messageA[] = "Ingrese el salario del trabajador\n";
    char messageB[] = "Ingrese la categoria del trabajador\n";
    char messageC[] = "Ingrese la antiguedad del trabajador\n";
    char messageD[] = "El sueldo del empleado es: $";

    salary = scan(messageA);
    category = scan(messageB);
    antiquity = scan(messageC);

    if (category == 1){
        bonus = plus * antiquity;
        salary += bonus;
    }

    if (antiquity > 5) printf("%s%d", messageD, salary);

    return 0;
}