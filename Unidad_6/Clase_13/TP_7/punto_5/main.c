#include <stdio.h>

#define TRUE 1
#define FALSE 0

void fillSecuencialArray(int (*array), int arrayLen, int from);
void fillUserData(int (*array)[][], int totalOfEmployes, int emploId[], int proyectId[]);
void intSort(int (*array), int arrayLen);
int binarySearch(int array[], int arrayLen, int d);

int main(){
    char employName[10] = {"Camila", "Belen", "Rodrigo", "Pepe", "Juan", "Ramiro", "Lucila", "Luciana", "Enzo", "Carlos"};
    int employId[10] = {0};
    int hourValue[11] = {0, 500, 400, 450, 234, 578, 489, 980, 384, 467, 487};
    int proyectId[15] = {0};
    int inputData[10][3] = {0};

    int employIdLen = sizeof(employId) / sizeof(employId[0]);
    int hourValueLen = sizeof(hourValue) / sizeof(hourValue[0]);
    int proyectIdLen = sizeof(proyectId) / sizeof(proyectId[0]);
    
    fillSecuencialArray(employId, employIdLen, 500);
    fillSecuencialArray(proyectId, proyectIdLen, 400);
    fillUserData(inputData, 10, employId, proyectId);

    return 0;
}

void fillSecuencialArray(int (*array), int arrayLen, int from){
    for (int i = from; i < arrayLen; i++){
        array[i] = i;
    }
    
}

void fillUserData(int (*inputData)[][], int totalOfEmployes, int employId[], int proyectId[]){
    char employeRequest[] = "Ingrese el Id del empleado";
    char proyectRequest[] = "Ingrese el Id del proyecto";
    char workRequest[] = "Ingrese la cantidad de horas trabajadas";
    int i = 0;
    int isCorrectValue = FALSE;

    int employIdLen = sizeof(employId) / sizeof(employId[0]);
    int proyectIdLen = sizeof(proyectId) / sizeof(proyectId[0]);

    printf("Ingrese los datos para cada empleado.\n");
    
    for (int i = 0; i < count; i++){
                isCorrectValue = FALSE;
        do{
            int employIdInput = scanInt(employeRequest);
            if (binarySearch(employId, employIdLen, employIdInput) != -1){
                isCorrectValue = TRUE;
            }else{
                printf("El id de empleado %d no existe.\n", employId);
            }

        } while (isCorrectValue == FALSE);

        isCorrectValue = FALSE;
        do{
            int proyectIdInput = scanInt(proyectRequest);
            if (binarySearch(proyectId, proyectIdLen, proyectIdInput) != -1){
                isCorrectValue = TRUE;
            }else{
                printf("El id de proyecto %d no existe.\n", proyectId);
            }

        } while (isCorrectValue == FALSE);

        int hoursWorkedInput = scanInt(workRequest);

    }
    
}

void intSort(int (*array), int arrayLen){
	int aux = 0;

	for(int i = 0; i < arrayLen -1 ; i++){
		for(int j = 0; j < arrayLen - i - 1; j++){ 		

			if (array[j] > array[j + 1]){ 

				aux = array[j];

				array[j] = array[j + 1];
 
				array[j + 1]=aux;
			}
		}
	}
}

int binarySearch(int array[], int arrayLen, int d){
    int max, min, center, err;

    min = center = 0;
    max = arrayLen - 1;
    err = TRUE;
    
    while(min <= max){
        center = ( (max - min) / 2 ) + min;
        
        if (array[center] == d){
            err = FALSE;
            break;
        }
        
        if (d < array[center]) max = center - 1;
        else min = center + 1;
    }
    
    if (err == TRUE) return -1;

    return center;
}

float scanFloat(char *message){
    char errType[] = "Debe ingresar un valor numerico.\n";
    float q;
    int input;
    do
    {
        printf("%s.\n", message);
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

float scanInt(char *message){
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

void printArray(float array[], int arrayLen){
    for (int i = 0; i < arrayLen; i++){
        printf("%4.2f\t", array[i]);
    }
    printf("\n");    
}