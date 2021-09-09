#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main()
{
    int emp, ch, vh, sdo;
    system("cls");
    printf("ingrese el nro de empleado:\n");
    scanf("%d", &emp);
    printf("ingrese la cantidad de horas:\n");
    scanf("%d", &ch);
    printf("ingrese el valor de la hora del empleado:\n");
    scanf("%d", &vh);
    sdo = ch * vh;
    printf("el empleado %d, cobra %d pesos \n", emp, sdo);
    system("pause");
}