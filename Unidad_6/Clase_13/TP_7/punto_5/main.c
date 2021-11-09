#include <stdio.h>

void fillSecuencialArray(int (*array), int arrayLen);
void fillArray(int (*array), int arrayLen);
void intSort(int (*array), int arrayLen);
void binarySearch(int array[], int arrayLen, int d);

int main(){
    char employName[10] = {"Camila", "Belen", "Rodrigo", "Pepe", "Juan", "Ramiro", "Lucila", "Luciana", "Enzo", "Carlos"};
    int employId[10] = {0};
    int hourValue[10] = {500, 400, 450, 234, 578, 489, 980, 384, 467, 487};
    int proyectId[15] = {0};

    int employIdLen = sizeof(employId) / sizeof(employId[0]);
    int hourValueLen = sizeof(hourValue) / sizeof(hourValue[0]);
    int proyectIdLen = sizeof(proyectId) / sizeof(proyectId[0]);
    
    fillSecuencialArray(employId, employIdLen);
    fillSecuencialArray(proyectId, proyectIdLen);
    fillArray()

    return 0;
}

void fillSecuencialArray(int (*array), int arrayLen){
    for (int i = 0; i < arrayLen; i++){
        array[i] = i + 1;
    }
    
}

void fillArray(int (*array), int arrayLen){
    char messageRequest[] = "Ingrese el valor";

    printf("Ingrese %d numeros.\n", arrayLen);
    
    for (int i = 0; i < arrayLen; i++){
        printf("Numero %d. ", i + 1);
        int input = scanFloat(messageRequest); 
        array[i] = input;
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

void binarySearch(int array[], int arrayLen, int d){
    int max, min, center, err;

    min = center = 0;
    max = arrayLen - 1;
    err = TRUE;
    
    while(min <= max){
        center = ( (max - min) / 2 ) + min;
        
        if (array[center] == d){
            printf("El valor %.2f se encuentra en la posicion %d del array.\n", d, center);
            err = FALSE;
            break;
        }
        
        if (d < array[center]) max = center - 1;
        else min = center + 1;
    }
    if (err == TRUE) printf("No se encontro el valor %.2f dentro del array.\n", d);
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