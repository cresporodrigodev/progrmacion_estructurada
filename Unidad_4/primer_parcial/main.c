// En un local de empanadas implementa un sistema de pedidos por
// donde se ingresan:
// - Gusto de empanada (1 Carne, 2 Pollo, 3 Jamón y queso) --> int
// - Cantidad de empanadas de ese gusto. --> int
// La carga se finaliza con gusto = 0.
// Sabemos que cada empana cuesta $100 y la docena $1000.
// Al finalizar la carga debe mostrar:
// - Cantidad de empanadas de cada gusto. --> int
// - Cantidad de empanadas totales. --> int
// - Cuantas docenas y cuantas empanadas sueltas son. --> int
// - Costo del pedido. --> float

#include <stdio.h>
#define TRUE 1
#define FALSE 0

int scanIntPositive(char *message);
int scanIdItem(char *message);
int isValidItem(int item);

const int item0 = 0;
const int item1 = 1;
const int item2 = 2;
const int item3 = 3;

int main(){
    int dozens, units, itemId, quantity, total, totalItem1, totalItem2, totalItem3, i, notValidInput;
    char idRequest[] = "Ingrese el gusto de empanda\n";
    char quantityRequest[] = "Ingrese la cantidad de empandas para el gusto indicado\n";

    dozens = units = total = totalItem1 = totalItem2 = totalItem3 = i = 0;
    notValidInput = FALSE;
    
    do{
       itemId = scanIdItem(idRequest);
       
       if (itemId == item0){
           if (i == 0) notValidInput = TRUE;
           continue;
        }
       quantity = scanIntPositive(quantityRequest);
       total += quantity;

       if (itemId == item1) totalItem1 += quantity;
       else if (itemId == item2) totalItem2 += quantity;
       else if (itemId == item3) totalItem3 += quantity;

        i++;

    } while (itemId != 0);

    for (int i = units = 0; i < total; i++, units++){
        
        if (units == 12){
            dozens++;
            units = 0;
        }
    }
    
    if (notValidInput == FALSE){
            printf("Su pedido es:\n");
        printf("- %d de carne.\n- %d de pollo.\n- %d de JyQ.\n", totalItem1, totalItem2, totalItem3);
        printf("- El total de empandas es: %d\n", total);
        printf("- Son %d docenas y %d unidades sueltas", dozens, units);
        printf("- El total del pedido es: %d", (dozens * 1000) + (units * 100));
    }
    else printf("No se ingresaron datos validos");

    return 0;
}

int scanIntPositive(char *message){
    char errType[] = "Debe ingresar un valor numerico.\n";
    char err[] = "Debe ingresar un valor positivo.\n";
    int q, input;
    do{
        printf("%s", message);
        fflush(stdout);
        fflush(stdin);
        input = scanf("%d", &q);
        if (input != 1){
            printf("%s", errType);
            fflush(stdout);
        }
        else if (q < 0){
            printf("%s", err);
            fflush(stdout);
        }
        
    }while (q < 0);
    
    return q;
}

int scanIdItem(char *message){
    char itemErr[] = "El articulo ingresado no se encunetra disponible. Ingrese nuevamente el articulo\n";
    int idItem, idErr;

    idErr = TRUE;

    do{
        idItem = scanIntPositive(message);
        if (isValidItem(idItem)) idErr = FALSE;
        else{
            printf("%s", itemErr);
            fflush(stdout);
        }

    } while (idErr == TRUE);

    return idItem;
}

int isValidItem(int item){
    int status = FALSE;
    if (item == item0 || item == item1 || item == item2 || item == item3) status = TRUE;
    return status;
}