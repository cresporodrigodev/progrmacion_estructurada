// Ingresar N sueldos e indicar su suma y su promedio,
// imprimir resultados.

#include <stdio.h>

int scanN(char *message);
int scanSalary(int salaryCount);

int main(){
    int n, salary, total, prom;
    char nRequest[] = "Ingrese la cantidad de sueldos\n";
    n = scanN(nRequest);

    salary = total = prom = 0;
    
    for (int i = 0; i < n; i++){
       salary = scanSalary(i + 1);
       total += salary;
    }

    prom = total/n;

    printf("-La suma total de sueldos es: %d\n", total);
    printf("-El promedio del total es: %d\n", prom);
    
    return 0;
}

int scanN(char *message){
    char err[] = "Debe ingresar un valor entero.\n";
    int q;

    printf("%s", message);
    fflush(stdout);
    fflush(stdin);
    int input = scanf("%d", &q);
    if (input == 1){
        return q;
    }
    else{
        printf("%s", err);
        scanN(message);
    }
}

int scanSalary(int salaryCount){
    char err[] = "Debe ingresar un valor entero.\n";
    int q;

    printf("Ingrese el sueldo numero %d\n", salaryCount);
    fflush(stdout);
    fflush(stdin);
    int input = scanf("%d", &q);
    if (input == 1){
        return q;
    }
    else{
        printf("%s", err);
        scanN(salaryCount);
    }
}