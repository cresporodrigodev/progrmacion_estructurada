// Ingresar las horas trabajadas por un empleado y su categoría,
// calcular su sueldo sabiendo que los empleados de la categoría 1
// cobran $50, la 2 cobra $ 70 y la 3 cobra $ 80.

#include <stdio.h>
#include "../scan_int.h"

int main(){
    int timeValue, timeWorked, category;
    const int category1 = 50;
    const int category2 = 70;
    const int category3 = 80;
    
    char messageA[] = "Ingrese las horas trabajadas\n";
    char messageB[] = "Ingrese la categoria\n";
    char messageC[] = "El sueldo del empleado es: $";

    timeWorked = scan(messageA);
    category = scan(messageB);

    timeValue = 0;

    if (category < 1 || category > 3) printf("Categoria %d no contemplada", category);
    else{
        
        switch (category)
        {
        case 1:
            timeValue = category1;
            break;
        
        case 2:
            timeValue = category2;
            break;
        
        case 3:
            timeValue = category3;
            break;
        
        default:
            break;
        }
        if (timeValue == 0) printf("Ocurrio un error");
        else printf("%s%d", messageC, timeWorked*timeValue);
    }

    return 0;
}