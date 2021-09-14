// Ingresar tres valores correspondientes al día,
// mes y año de una fecha, indicar si es válida, 
// considerar los años bisiestos
#include <stdio.h>
#include "../scan_int.h"
#define TRUE 1
#define FALSE 0

int isValidDay(int day);
int isValidMonth(int month);
int isValidYear(int year);
int isBisiesto(int year);
int isValidDate(int day, int month, int year);

int main(){
    int day, month, year;
    int validDay, validMonth, validYear;
    char messageA[] = "Ingrese el dia\n";
    char messageB[] = "Ingrese el mes\n";
    char messageC[] = "Ingrese el ano\n";

    validDay = validMonth = validYear = FALSE;
    
    while (validDay != TRUE){
        day = scan(messageA);
        validDay = isValidDay(day);
    }
    while (validMonth != TRUE){
        month = scan(messageB);;
        validMonth = isValidMonth(month);
    }
    while (validYear != TRUE){
        year = scan(messageC);
        validYear = isValidYear(year);
    }

    if (isValidDate(day, month, year) == TRUE){
        printf("La fecha %d/%d/%d es valida", day, month, year);
    }
    else printf("La fecha %d/%d/%d es invalida", day, month, year);

}

int isValidDay(int day){
    int status = FALSE;
    if (day >= 1 && day <= 31) status = TRUE;
    else printf("Valor para dia incorrecto\n");

    return status;
}

int isValidMonth(int month){
    int status = FALSE;
    if (month >= 1 && month <= 12) status = TRUE;
    else printf("Valor para mes incorrecto\n");

    return status;
}

int isValidYear(int year){
    int status = FALSE;
    if (year >= -9999 && year <= 9999) status = TRUE;
    else printf("Valor para mes incorrecto\n");

    return status;
}

int isBisiesto(int year){
    int status = FALSE;
    if ((year % 4) == 0){
        if ((year % 100) != 0 || (year % 400) == 0) status = TRUE;
    }
    return status;
}

int isValidDate(int day, int month, int year){
    int validDate, month30Days, month31Days;
    int monthsWith30days[] = {4, 6, 9, 11};
    int monthsWith31days[] = {1, 3, 5, 7, 8, 10, 12};
    
    validDate = month30Days = month31Days = FALSE;

    for (int i = 0; i < sizeof(monthsWith30days); i++){
        if (monthsWith30days[i] == month) month30Days = TRUE; 
    }

    if (month30Days != TRUE){
        for (int i = 0; i < sizeof(monthsWith31days); i++){
            if (monthsWith31days[i] == month) month31Days = TRUE; 
        }
    }

    if (month == 2){
        if (isBisiesto(year) == TRUE){
            if (day <= 29) validDate = TRUE; 
        }
        else{
            if (day <= 28) validDate = TRUE;
        }
    }
    else if (month30Days == TRUE){
        if (day <= 30) validDate = TRUE;
    }
    else if (month31Days == TRUE){
        if (day <= 31) validDate = TRUE;
    }
    
    return validDate;
}