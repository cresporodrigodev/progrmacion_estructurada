// Ingresar 8 valores por teclado, y a partir de esto sacar el
// promedio general, sacar el promedio de lo valores pares y el
// promedio de los valores impares. Luego mostrar por pantalla
// cuantos números superaron el valor 15.

#include <stdio.h>
#define MAX 8
#define TRUE 1
#define FALSE 0

float scanFloat(char *message);
float avarage(int count, float total);
int isPair(float x);

int main(){
    int countPair, countNotPair, countPlus15;
    float x, pairAverage, notPairAverage, total, totalAvarage, totalPair, totalNotPair;
    char messageReq[] = "Ingrese un valor\n";

    x = pairAverage = notPairAverage = totalAvarage = total = totalPair = totalNotPair = 0;
    countPair = countNotPair = countPlus15 = 0;

    for (int i = 0; i < MAX; i++){
        x = scanFloat(messageReq);
        total += x;

        if (isPair(x)){
            countPair += 1;
            totalPair += x;
        }
        else{
            countNotPair += 1;
            totalNotPair += x;          
        }
        if (x > 15) countPlus15 += 1;
    }

    printf("- El promedio general es: %.2f\n", avarage(MAX, total));
    printf("- El promedio de pares es: %.2f\n", avarage(countPair, totalPair));
    printf("- El promedio de impares es: %.2f\n", avarage(countNotPair, totalNotPair));
    printf("- Se ingresaron %d numeros mayores a 15\n", countPlus15);

    return 0;
}

float avarage (int count, float total){
    return total/count;
}

int isPair(float x){
    int status = FALSE;

    if (((int)x % 2)== 0) status = TRUE;

    return status;
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