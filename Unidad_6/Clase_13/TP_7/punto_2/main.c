// Cree un programa para ingresar 10 números en un vector y luego que
// permita introducir un número para realizar una búsqueda. Permita que
// el operador del programa elija que tipo de algoritmo quiere utilizar
// por medio de un menú (debe ser búsqueda binaria o secuencial).

#include <stdio.h>
#include <math.h>
#define TRUE 1
#define FALSE 0
#define EXIT 0
#define SEC 1
#define BINARY 2

void selectSearchType(float array[], int arrayLen);
void binarySearch(float array[], int arrayLen, float d);
void secuencialSearch(float array[], int arrayLen, float d);
void fillArray(float (*array), int arrayLen);
void floatSort(float (*array), int arrayLen);
float scanInt(char *message);
void printArray(float array[], int arrayLen);
float scanFloat(char *message);

int main(){
    double x = pow(x, y);
    float array[10] = {0};
    int arrayLen = sizeof(array) / sizeof(array[0]);

    fillArray(array, arrayLen);
    printf("El array ingresado es:\n");
    printArray(array, arrayLen);
    printf("\n");
    floatSort(array, arrayLen);
    printf("El array ordenado es:\n");
    printArray(array, arrayLen);
    printf("\n");
    selectSearchType(array, arrayLen);

}

void selectSearchType(float array[], int arrayLen){
    char dataRequest[] = "Ingrese el valor buscado";
    char messageRequest[] = "Ingrese 0 para salir, 1 para busqueda secuencial y 2 para busqueda binaria\n";
    char searchRequest[] = "Seleccione el tipo de busqueda\n";
    int x = 0;
    float d = 0;

    printf("%s", messageRequest);

    do{
        int err = TRUE;
        x = scanInt(searchRequest);

        if (x == EXIT || x == BINARY || x == SEC) err = FALSE;
        else printf("La opción %d no existe.\n", x);

        if (err == FALSE){
            switch (x){
            case BINARY:
                d = scanFloat(dataRequest);
                binarySearch(array, arrayLen, d);
                break;
            case SEC:
                d = scanFloat(dataRequest);
                secuencialSearch(array, arrayLen, d);
                break;
            default:
                break;
            }
        }
    
    } while (x != EXIT);

}

void binarySearch(float array[], int arrayLen, float d){
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

void secuencialSearch(float array[], int arrayLen, float d){
    int err = TRUE;
    for (int i = 0; i < arrayLen; i++){
        if (array[i] == d){
            printf("El valor %.2f se encuentra en la posicion %d del array.\n", d, i);
            err = FALSE;
            break;
        }
    }
    if (err == TRUE) printf("No se encontro el valor %.2f dentro del array.\n", d);
}

void fillArray(float (*array), int arrayLen){
    char messageRequest[] = "Ingrese el valor";

    printf("Ingrese %d numeros.\n", arrayLen);
    
    for (int i = 0; i < arrayLen; i++){
        printf("Numero %d. ", i + 1);
        int input = scanFloat(messageRequest); 
        array[i] = input;
    }
}

void floatSort(float (*array), int arrayLen){
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