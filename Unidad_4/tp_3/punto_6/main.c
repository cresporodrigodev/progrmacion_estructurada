// Ingresar la patente y monto de la multa de 50 autos,
// indicar e imprimir cuántos montos superan los $ 40 y del total
// cobrado que porcentaje representa la suma de los que superan los $40

#include <stdio.h>
#define MAX 10
#define LIMIT 40

float scanFloat(char *message);
float percetage(float total, float q);

int main(){
    int countPlus40 = 0;
    float amount, totalPlus40, total;
    char patente;
    char messageReq[] = "Ingrese el valor de la multa\n";

    amount = totalPlus40 = total = 0;

    for (int i = 0; i < MAX; i++){
        printf("Ingrese la patente\n");
        fflush(stdout);
        fflush(stdin);
        scanf("%c", &patente);

        amount = scanFloat(messageReq);
        total += amount;

        if (amount > LIMIT){
            countPlus40 += 1;
            totalPlus40 += amount;
        }
    }

    printf("%d patentes superan los %d$ de multa\n", countPlus40, LIMIT);
    printf("El %.2f supera los $%d pesos", percetage(total, totalPlus40),LIMIT);
    
    return 0;
}

float percetage(float total, float q){
    return (q / total) * 100;
}

float scanFloat(char *message){
    char errA[] = "Debe ingresar un numero\n";
    float q = 0;
    int input = 0;

    do{
        printf("%s", message);
        fflush(stdout);
        fflush(stdin);
        input = scanf("%f", &q);
        
        if (input != 1){
            printf("%s", errA);
            fflush(stdout);
        }
        
    } while (input != 1);

    return q;
}