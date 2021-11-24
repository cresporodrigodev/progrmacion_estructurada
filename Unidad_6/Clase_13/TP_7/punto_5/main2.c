#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define W 6
// void fillUserData(int (*hoursPerProyect)[W], int hLenI, int hLenJ, char employes[][], int eLenI);
float scanInt(char *message);
void sortArray(int (*originalArray), int (*sortedArray), int len);

int main(){
    char employes[5][20] = {{"Camila"}, {"Belen"}, {"Rodrigo"}, {"Pepe"}, {"Juan"}};
    int hourValue[5] = {500, 400, 450, 234, 578};
    int hoursPerProyect[6][8] = {0};
    int salarys[5] = {0};
    int sortedSalarys[5] = {0, 1, 2, 3, 4};

    char employeRequest[] = "Ingrese el Id del empleado";
    char proyectRequest[] = "Ingrese el Id del proyecto";
    char workRequest[] = "Ingrese la cantidad de horas trabajadas";

    int employe = 0;
    do {
        employe = scanInt(employeRequest);
        if (employe == 0) continue;

        int proyect = scanInt(proyectRequest);
        int hoursWorked = scanInt(workRequest);

        hoursPerProyect[employe][proyect] = hoursWorked;
        hoursPerProyect[employe][0] += hoursWorked;
        hoursPerProyect[0][proyect] += hoursWorked;

    } while (employe != 0);
    
    printf("--------------------------------\n");
    printf("punto 1.\nTotal de horas por analista.\n");
    for (int i = 0; i < 6; i++){
        if (i == 0) continue;
        printf("analista %d, total de horas trabajadas: %d\n", i, hoursPerProyect[i][0]);
    }

    printf("--------------------------------\n");
    printf("punto 2.\nTotal de horas por analista y por proyecto.\n");
    for (int i = 0; i < 6; i++){
        if (i == 0) continue;
        
        printf("\n");
        printf("--------------------------------\n");
        printf("empleado %d\n", i);
        for (int j = 0; j < 8; j++){
            if (j == 0) continue;
            printf("\tproyecto %d, horas %d\n", j , hoursPerProyect[i][j]);
        }
    }
    
    printf("--------------------------------\n");
    printf("punto 3.\nTotal de horas por proyecto.\n");
    for (int j = 0; j < 8; j++){
        if (j == 0) continue;
        printf("proyecto %d, total de horas trabajadas: %d\n", j, hoursPerProyect[0][j]);
    }

    printf("--------------------------------\n");
    printf("punto 4.\nAnalista que menos trbaajo en el proyecto 1.\n");
    int min = 1;
    for (int i = 0; i < 6; i++){
        if (i == 0) continue;
        if (hoursPerProyect[i][1] == 0) continue;
        if (hoursPerProyect[i][1] < hoursPerProyect[min][1]) min = i;
    }
    printf("%s, id %d, trabajo menos en el proyecto 1 con un total de %d\n", employes[min - 1], min, hoursPerProyect[min][1]);

    printf("--------------------------------\n");
    printf("punto 5.\nSueldo de cada analista.\n");
    int maxSalary = 1;
    for (int i = 1; i < 6; i++){
        int salary = hoursPerProyect[i][0] * hourValue[i - 1];
        if (salary > hoursPerProyect[maxSalary][0] * hourValue[maxSalary - 1]) maxSalary = i; 
        salarys[i - 1] = salary;
        printf("analista %s, sueldo total %d\n", employes[i - 1], salary);
    }

    printf("--------------------------------\n");
    printf("punto 6.\nNombre del analista que mas cobro.\n");
    printf("El analista que mas cobro es %s, con un sueldo de %d",employes[maxSalary - 1], hoursPerProyect[maxSalary][0] * hourValue[maxSalary - 1]);
    
    printf("--------------------------------\n");
    printf("Punto 7. Cantidad de analistas que trabajaron menos de 5 hs en algun proyecto\n");
    for (int i = 1; i < 6; i++){
        for (int j = 1; j < 8; j++){
            if (hoursPerProyect[i][j] < 5){
                printf("El analista %s trabajo %d horas en el proyecto %d\n", employes[i - 1], hoursPerProyect[i][j], j);
            }
        }
    }

    printf("--------------------------------\n");
    printf("Punto 8. Ordenado descendente por sueldo\n");
    sortArray(salarys, sortedSalarys, 6);
    for (int i = 1; i < 6; i++){
        int target = sortedSalarys[i];
        printf("nombre %s, valor de la hora %d, sueldo %d", employes[target], hourValue[target], salarys[target]);
    }

    return 0;
}

void sortArray(int (*originalArray), int (*sortedArray), int len){
    for (int i = 1; i < len; i++){
        for (int j = 1; j < len - 1; j++){
            
            int actual = sortedArray[j];
            int next = sortedArray[j + 1];
            if (originalArray[actual] < originalArray[next]) {
                int aux = sortedArray[j];
                sortedArray[j] = sortedArray[j + 1];
                sortedArray[j + 1] = aux;
            }
        }
    }
}

float scanInt(char *message){
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
// void fillUserData(int (*hoursPerProyect)[W], int hLenI, int hLenJ, char employes[][], int eLenI){

//     int isCorrectValue = FALSE;
//     int input = 0;

//     printf("A continuación debe ingrese los datos para cada empleado.\n");
    
//     for (int i = 0; i < hLenI - 1; i++){  
//         int employIdInput = 0;
//         int proyectIdInput = 0;

//         isCorrectValue = FALSE;

//         do{
//             printf("Ingrese el numero del empleado");

//             employIdInput = scanInt(employeRequest);
            
//             if (0 <= employIdInput <= hLenI){
//                 isCorrectValue = TRUE;
//             }
//             else printf("El id de empleado %d no existe.\n", employIdInput);

//         } while (isCorrectValue == FALSE);

//         do{
//             printf("Ingrese el numero de proyecto");

//             proyectIdInput = scanInt(proyectRequest);
            
//             if (0 <= proyectIdInput <= hLenI){
//                 isCorrectValue = TRUE;
//             }
//             else printf("El id de empleado %d no existe.\n", proyectIdInput);

//         } while (isCorrectValue == FALSE);

//         int hoursWorkedInput = scanInt(workRequest);

//         hoursPerProyect[employIdInput][proyectIdInput] = hoursWorkedInput;

//     }
    
// }