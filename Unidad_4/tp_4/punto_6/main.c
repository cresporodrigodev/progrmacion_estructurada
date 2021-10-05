// Ingresar los datos de facturación de una empresa.
// Se conoce:
// - Número de factura
// - Número de artículo
// - Cantidad vendida
// - Precio unitario
// Los datos finalizan con numero de factura = 0, cada factura sólo
// tiene un número de artículo, y existen sólo tres artículos.

#include <stdio.h>
#define TRUE 1
#define FALSE 0

int scanInvoice(char *message);
int scanIntPositive(char *message);
int isNotValidItem(int item);
float scanFloat(char *message);

const int item1 = 415;
const int item2 = 764;
const int item3 = 998;

int main(){
    int itemId, quantity;
    float amount;
    char invoiceReq[] = "Ingrese el numero de factura\n";
    char itemReq[] = "Ingrese el Id del articulo\n";
    char itemErr[] = "El articulo ingresado no se encunetra disponible. Ingrese nuevamente el articulo\n";
    char quantityReq[] = "Ingrese la cantidad facturada\n";
    char amountReq[] = "Ingrese el precio unitario\n";
    
    while((scanInvoice(invoiceReq) != 0)){
        printf("Ingrese los datos de la factura.\n");
        fflush(stdout);
        printf("Los articulos disponibles son:\n");
        fflush(stdout);
        printf("- %d\n- %d\n- %d\n", item1, item2, item3);
        fflush(stdout);

        do{
            itemId = scanIntPositive(itemReq);
            if (isNotValidItem(itemId)) printf("%s", itemErr);
        } while (isNotValidItem(itemId));

        scanIntPositive(quantityReq);
        scanFloat(amountReq);

        // printf("Total facturado: $%d\n",quantity * amount);
        // fflush(stdout);
        // printf("---------------------------------------\n");
        // fflush(stdout);
    } 

    return 0;
}

int scanInvoice(char *message){
    char err[] = "Debe ingresar un valor positivo.\n";
    int q, input;
    do{
        printf("%s", message);
        fflush(stdout);
        fflush(stdin);
        input = scanf("%d", &q);
        if (q < 0){
            printf("%s", err);
            fflush(stdout);

        }
        
    }while (q < 0);
}

int scanIntPositive(char *message){
    char err[] = "Debe ingresar un valor positivo.\n";
    int q, input;
    do{
        printf("%s", message);
        fflush(stdout);
        fflush(stdin);
        input = scanf("%d", &q);
        if (q <= 0){
            printf("%s", err);
            fflush(stdout);
        }
        
    }while (q <= 0);
}

int isNotValidItem(int item){
    int status = TRUE;
    if (item == item1 || item == item2 || item == item3) status = FALSE;
    return status;
}

float scanFloat(char *message){
    char errA[] = "Debe ingresar un valor numerico\n";
    float q = 0;
    int input;

    do{
        printf("%s\n", message);
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