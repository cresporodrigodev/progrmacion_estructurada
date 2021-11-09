// Desarrolle un programa que, a partir de los datos prefijados
// de los días de cada mes, diga qué meses tienen 30 días.
// Se deberá mostrar el número de cada mes, pero empezando a 
// contar desde 1 (abril será el mes 4).

#include <stdio.h>

int main(){
    int monthsLen;
    int daysOfMonths[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    char months[12][11] = { {"Enero"}, {"Febrero"}, {"Marzo"}, {"Abril"},
    {"Mayo"} , {"Junio"}, {"Julio"}, {"Agosto"}, {"Septiembre"}, {"Octubre"}, {"Noviembre"}, {"Diciembre"} };
    char messageHome[] = "Bienvenido.\nEl siguiente programa muestra los meses que tienen 30 dias.\n";

    monthsLen = sizeof(daysOfMonths) / sizeof(daysOfMonths[0]);

    printf("%s", messageHome);

    for (int i = 0; i < monthsLen; i++){
        if (daysOfMonths[i] == 30){
            printf("El mes %s(%d) tiene %d dias\n",months[i], i + 1, daysOfMonths[i]);
        }
    }

    return 0;

}