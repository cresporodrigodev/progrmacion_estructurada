// Ingresar facturas hasta nro de factura = 0, sumar sus importes
// y cúales y cuantas superan los $1000. Imprimir los resultados.
// - a. Sobre el ejercicio anterior indicar cuántas superan los
// $ 10000.-imprimir el resultado
// - b. Sobre el ejercicio anterior indicar cuántas estan entre
// $ 400 y $ 700 inclusive. imprimir el resultado.

#include <stdio.h>
#define LIMIT 1000
#define LIMIT_2 10000
#define TRUE 1
#define FALSE 0

int plus1000(int amount);
int plus10000(int amount);
int isIn400to700(int amount);
int scan(char *message);

int main(){
    int numberInvoice, amountInvoice, isPlus1000, isPlus10000;
    int countPlus1000, countPlus10000, totalAmount, count400to700;
    char numberInvoiceRequest[] = "Ingrese el numero de la factura.\n";
    char amountInvoiceRequest[] = "Ingrese el importe de la factura.\n";
    countPlus1000 = totalAmount = countPlus10000 = count400to700 = 0;

    do{
        numberInvoice = scan(numberInvoiceRequest);    
        if (numberInvoice == 0) continue;
        
        amountInvoice = scan(amountInvoiceRequest);
        totalAmount += amountInvoice;
        
        if(plus1000(amountInvoice)){
            countPlus1000 += 1;
            printf("- La factura %d supera los $%d\n", numberInvoice, LIMIT);
        
            if(plus10000(amountInvoice)) countPlus10000 += 1;
        }
        else if (isIn400to700(amountInvoice)) count400to700 += 1;
        
    } while(numberInvoice != 0);
    
    printf("- El importe total de facturas es: %d\n", totalAmount);
    printf("- %d facturas superan los $%d\n", countPlus1000, LIMIT);
    printf("- %d facturas superan los $%d\n", countPlus10000, LIMIT_2);
    printf("- %d facturas se encunetran entre $400 y $700\n", count400to700);

    return 0;
}

int plus1000(int amount){
    int plus1000 = FALSE;
    if (amount > 1000) plus1000 = TRUE;
    return plus1000;
}

int plus10000(int amount){
    int plus10000 = FALSE;
    if (amount > 10000) plus10000 = TRUE;
    return plus10000;
}

int isIn400to700(int amount){
    int status = FALSE;
    if (amount > 400 && amount < 700) status = TRUE;
    return status;
}

int scan(char *message){
    char err[] = "Debe ingresar un valor positivo.\n";
    int q, input;
    do{
        printf("%s", message);
        fflush(stdout);
        fflush(stdin);
        input = scanf("%d", &q);
        if (q < 0){
            printf("%s", err);
        }
        
    }while (q < 0);
}