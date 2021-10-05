// Ingresar 30 valores. Contar cuantos están entre 1 y 10,
// cuantos entre 10 y 20, cuantos entre 20 y 30 y cuantos son mas
// de 30. Luego mostrar el porcentaje de cada grupo en el total.

#include <stdio.h>
#define MAX 30

int scanInt(char *message);
float getPercentage(int tot, int quantity);

int main()
{
    int oneToTen, tenToTwenty, twentyToThirty, plusThirty, x, numberPrint;
    float percentage;
    char messageA[] = "Ingrese un valor positivo\n";
    char message1to10[] = "01 y 10";
    char message10to20[] = "10 y 20";
    char message20to30[] = "20 y 30";
    char messagePlus30[] = "30 y ..";
    char *messagePrint;

    percentage = oneToTen = tenToTwenty = twentyToThirty = x = plusThirty = 0;

    for (int i = 0; i < MAX; i++)
    {
        x = scanInt(messageA);

        if (x < 30){
            if (x > 1 && x < 10) oneToTen += 1;
            else if (x > 10 && x < 20) tenToTwenty += 1;
            else if (x > 20 && x < 30) twentyToThirty += 1;
        }
        else plusThirty += 1;
    }

    for (int i = 0; i < 4; i++){
        switch (i){
        case 0:
            messagePrint = &message1to10;
            numberPrint = oneToTen;
            percentage = getPercentage(MAX, numberPrint);
            break;
        case 1:
            messagePrint = &message10to20;
            numberPrint = tenToTwenty;
            percentage = getPercentage(MAX, numberPrint);
            break;
        case 2:
            messagePrint = &message20to30;
            numberPrint = twentyToThirty;
            percentage = getPercentage(MAX, numberPrint);
            break;
        case 3:
            messagePrint = &messagePlus30;
            numberPrint = plusThirty;
            percentage = getPercentage(MAX, numberPrint);
            break;
        default: printf("Error\n");
            break;
        }        
        printf("La cantidad de numeros entre %s es: %d\n", messagePrint, numberPrint);
        printf("Y su porcentaje es: %.2f.\n", percentage);
        printf("\n");
    }
    return 0;
}

float getPercentage(int tot, int quantity)
{
    float percentage = 0;
    percentage = ((float)quantity / tot) * 100;
    return percentage;
}

int scanInt(char *message){
    char errA[] = "Debe ingresar un numero entero\n";
    int q = 0;
    int input = 0;

    do{
        printf("%s", message);
        fflush(stdout);
        fflush(stdin);
        input = scanf("%d", &q);
        
        if (input != 1){
            printf("%s", errA);
            fflush(stdout);
        }
        
    } while (input != 1);

    return q;
}