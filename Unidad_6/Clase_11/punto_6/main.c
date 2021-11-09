// Desarrolle un programa que almacene en un vector el
// número de días que tiene cada mes (supondremos
// que es un año no bisiesto), pida al usuario que
// le indique un mes (1=enero, 12=diciembre) y
// muestre en pantalla el número de días que tiene ese mes.

#include <stdio.h>

int scanDays(char *message);

int main(){
    const int exit = 0;
    int input = 0;
    int daysOfMonths[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    char months[12][11] = { {"Enero"}, {"Febrero"}, {"Marzo"}, {"Abril"},
    {"Mayo"} , {"Junio"}, {"Julio"}, {"Agosto"}, {"Septiembre"}, {"Octubre"}, {"Noviembre"}, {"Diciembre"} };
    char messageHome[] = "Bienvenido.\nEl siguiente programa muestra la cantidad de dias de cada mes.\nIngrese 0 para salir.\n";
    char messageRequest[] = "Ingrese el mes que desea consultar\n";

    printf("%s", messageHome);

    do{
        input = scanDays(messageRequest);
        
        if (input != exit){
            int i = input - 1;
            printf("El mes %s(%d) tiene %d dias\n",months[i], input, daysOfMonths[i]);
        }
    } while (input != exit);

    return 0;

}

int scanDays(char *message){
    char errType[] = "Debe ingresar un valor numerico.\n";
    char errValue[] = "Debe ingresar un numero entre 0 y 12\n";
    int q;
    int input;
    
    do{
        printf("%s\n", message);
        fflush(stdout);
        fflush(stdin);
        input = scanf("%d", &q);
        if (input != 1) {
            printf("%s", errType);
            fflush(stdout);
        }
        if (q > 12 || q < 0){
            printf("%s", errValue);
            fflush(stdout);
        }

    } while (input != 1 || (q > 12 || q < 0));

    return q;
}