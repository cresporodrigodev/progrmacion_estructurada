#include <stdio.h>

#define ARRAY_LEN 100
#define TRUE 1
#define FALSE 0

int addInvoice(int i, int (*invoiceArr), int (*vendorArr), float (*amountArr));
void printArrayFloat(float (*array));
void printArrayInt(int (*array));
float scanFloat(char *message);
int scanInt(char *message);

int main(){
    int cont = FALSE;
    int invoice [ARRAY_LEN] = {0};
    int vendor [ARRAY_LEN] = {0};
    int i = 0;
    float amount[ARRAY_LEN] = {0};
    char home[] = "Bienvenido.\nIngrese nro factura = 0 para salir\n";

    printf("%s", home);
    fflush(stdout);

    do{
        cont = addInvoice(i, invoice, vendor, amount);  
        i++;
    }while (cont != FALSE);

    printf("invoices\n");
    printArrayInt(invoice);
    printf("vendors\n");
    printArrayInt(vendor);
    printf("amount\n");
    printArrayFloat(amount);

    return 0;

}

void printArrayFloat(float (*array)){
    for (int i = 0; i < ARRAY_LEN; i++){
        if (array[i] != 0){
            printf("%.1f \t", array[i]);
        }
    }
    printf("\n");
}

void printArrayInt(int (*array)){
    for (int i = 0; i < ARRAY_LEN; i++){
        if (array[i] != 0){
            printf("%d \t", array[i]);
        }
    }
    printf("\n");
}

int addInvoice(int i, int (*invoiceArr), int (*vendorArr), float (*amountArr)){
    int invoice = 0, vendor = 0;
    float amount = 0;
    char invoiceRequest[] = "Ingrese el numero de factura.\n";
    char vendorRequest[] = "Ingrese el numero de vendor.\n";
    char amountRequest[] = "Ingrese el importe.\n";

    invoice = scanInt(invoiceRequest);
    if (invoice != FALSE){
        vendor  = scanInt(vendorRequest);
        amount  = scanFloat(amountRequest); 
    
        invoiceArr[i] = invoice;
        vendorArr[i] = vendor;
        amountArr[i] = amount;
    }
    
    return invoice;
}

float scanFloat(char *message){
    char errType[] = "Debe ingresar un valor numerico.\n";
    float q;
    int input;
    do
    {
        printf("%s", message);
        fflush(stdout);
        fflush(stdin);
        input = scanf("%f", &q);
        if (input != 1)
        {
            printf("%s", errType);
            fflush(stdout);
        }

    } while (input != 1);

    return q;
}

int scanInt(char *message){
    char errType[] = "Debe ingresar un valor numerico.\n";
    int q;
    int input;
    do
    {
        printf("%s", message);
        fflush(stdout);
        fflush(stdin);
        input = scanf("%d", &q);
        if (input != 1)
        {
            printf("%s", errType);
            fflush(stdout);
        }

    } while (input != 1);

    return q;
}