// Ingresar los sueldos y nombres de 30 empleados, indicar e imprimir
// el sueldo mayor y a quién pertenece

#include <stdio.h>
#define MAX 30
#define ASCII_A 97
#define ASCII_Z 122

float scanFloat(char *message, int i);
int scanChar(char *message, int i);

int main(){
    float salary, maxSalary, minSalary;
    int name, maxName, minName;
    char salaryReq[] = "Ingrese el sueldo del empleado";
    char nameReq[] = "Ingrese el nombre del empleado";

    maxName = minName = maxSalary = minSalary = 0;

    for (int i = 0; i < MAX; i++){
        name = scanChar(nameReq, i + 1);
        salary = scanFloat(salaryReq, i + 1);

        if (i == 0){
            maxSalary = minSalary = salary;
            maxName = minName = name;
        }
        else{
            if (salary > maxSalary){
                maxSalary = salary;
                maxName = name;
            } 
            if (salary < minSalary){
                minSalary = salary;
                minName = name;
            }
        }
    }
    printf("El salario maximo es: %.2f\n", maxSalary);
    printf("Y le corresponde a: %c\n", maxName);
    printf("El salario minimo es: %.2f\n", minSalary);
    printf("Y le corresponde a: %c\n", minName);
    
}

float scanFloat(char *message, int i){
    char errA[] = "Debe ingresar un valor numerico\n";
    float q = 0;
    int input;

    do{
        printf("%s %d\n", message, i);
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

int scanChar(char *message, int i){
    char errA[] = "Ocurrió un error\n";
    char errB[] = "Debe ingresar una letra\n";
    char q = 0;
    int input;

    do{
        printf("%s %d\n", message, i);
        fflush(stdout);
        fflush(stdin);
        input = scanf("%c", &q);
        
        if (input != 1){
            printf("%s", errA);
            fflush(stdout);
        }

        if (q < ASCII_A || q > ASCII_Z){
            printf("%s", errB);
            fflush(stdout);
        }

    } while (q < ASCII_A || q > ASCII_Z);

    return q;
}