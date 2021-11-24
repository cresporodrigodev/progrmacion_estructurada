#include <stdio.h>
#define TOTALEMPLOYES 3
#define TOTALMENUS 4

int scanInt(char *message);

int main() {
    int menusPrice[4] = {100, 100, 120, 120}; 
    int employesAndMenus[4][5] = {0}; //La primera posición de i y de j se reserva para totalizar
    int employe, menu, amount, count, totalPerSale, maxMenu2, bestSellingMenu;
    employe = menu = amount = totalPerSale = 0;
    count = bestSellingMenu = 1;

    do{
        char menuRequest[] = "Ingrese el numero de menu";
        char employeRequest[] = "Ingrese el numero de Mozo";
        char amountRequest[] = "Ingrese la cantidad del menu";
        printf("-----Venta numero %d------\n", count);

        employe = scanInt(employeRequest);
        if (employe == 0) continue;
        if (employe > TOTALEMPLOYES){
            printf("El mozo numero %d no existe\n", employe);
            continue;
        }
        
        totalPerSale = 0;
        do{
            menu = scanInt(menuRequest);
            if (menu == 0) continue;
            if (menu > TOTALMENUS){
                printf("El menu numero %d no existe", menu);
                continue;
            }
            
            amount = scanInt(amountRequest);

            employesAndMenus[employe][menu] += amount;
            employesAndMenus[employe][0] += amount;
            employesAndMenus[0][menu] += amount;

            totalPerSale += menusPrice[menu - 1] * amount;

        } while (menu != 0);
        printf("El importe a cobrar es: $%d\n", totalPerSale);
        
        count++;
    } while (employe != 0);
    
    printf("--------------------------------\n");
    printf("punto a.\nTotal facturado por cada mozo.\n");
    for (int i = 1; i < 4; i++){
        int totalSales = 0;
        for (int j = 1; j < 5; j++){
            totalSales += employesAndMenus[i][j] * menusPrice[j - 1];
        }
        printf("El mozo %d facturo un total de $%d\n", i, totalSales);
    }

    printf("--------------------------------\n");
    printf("punto b.\nCantidad total vendida de cada menu\n");
    for (int j = 1; j < 5; j++){
        printf("La cantidad vendida del menu %d es: %d\n", j, employesAndMenus[0][j]);
    }

    printf("--------------------------------\n");
    printf("punto c.\nDetalle de los menu de cada tipo vendido por cada mozo.\n");
    for (int i = 1; i < 4; i++){
        for (int j = 1; j < 5; j++){
            printf("El mozo %d vendio %d cantidades de menu %d\n", i, employesAndMenus[i][j], j);
        }
        printf("\n");  
    }

    printf("--------------------------------\n");
    printf("punto d.¿Que mozo vendio mas menu 2?\n");
    maxMenu2 = 1;
    for (int i = 1; i < 4; i++){
        if (employesAndMenus[i][2] > employesAndMenus[maxMenu2][2]) maxMenu2 = i;
    }
    printf("El mozo %d fue quien mas vendio el menu 2, con un total de: %d\n", maxMenu2, employesAndMenus[maxMenu2][2]);
    
    printf("--------------------------------\n");
    printf("punto e.¿Cual fue el plato mas vendido?\n");
    for (int j = 1; j < 5; j++){
        if (employesAndMenus[0][j] > employesAndMenus[0][bestSellingMenu]) bestSellingMenu = j;
    }
    printf("El menu mas vendido fue el %d, con un total de %d\n", bestSellingMenu, employesAndMenus[0][bestSellingMenu]);

    return 0;
}

int scanInt(char *message){
    char errType[] = "Debe ingresar un valor numerico.\n";
    int input, q;
    do{
        printf("%s\n", message);
        fflush(stdout);
        fflush(stdin);
        input = scanf("%d", &q);
        if (input != 1){
            printf("%s", errType);
            fflush(stdout);
        }
        
    }while (input != 1);

    return q;
}