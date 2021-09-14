// Ingresar el valor de la hora y el tiempo trabajado por un empleado,
// calcular su sueldo conociendo que recibe un premio de $ 100
// si trabajo más de 50 hs y si trabajo más de 150 hs le dan otros
// $ 100 adicionales. Imprimir el sueldo.

#include <stdio.h>
#include "../scan_int.h"

int main(){
    int timeValue, timeWorked, basicSalary, netSalary;
    const int firstHourPlus = 50; 
    const int secondHourPlus = 150;
    const int plusValue = 100;
    char messageA[] = "Ingrese las horas trabajadas\n";
    char messageB[] = "Ingrese el valor de la hora\n";
    char messageC[] = "El sueldo del empleado es: $";

    timeWorked = scan(messageA);
    timeValue = scan(messageB);
    basicSalary = timeValue * timeWorked;

    if (timeWorked > firstHourPlus){
        
        netSalary = basicSalary + plusValue;
        
        if (timeWorked > secondHourPlus){
            netSalary += plusValue;
        }
        
        printf("%s%d\n", messageC, netSalary);
    }
    else printf("%s%d\n", messageC, basicSalary);

    return 0;
}