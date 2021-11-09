// Ingresar 15 datos en un vecto y
// ordenarlos de manera descendiente.

#include <stdio.h>

void printArray(float array[], int arrayLen);
float scanFloat(char *message);
void fillArray(float (*array), int arrayLen);
void floatSort(float (*array), int arrayLen);

int main(){
    float array[15] = {0};
    int arrayLen = sizeof(array) / sizeof(array[0]);

    fillArray(array, arrayLen);
    printf("El Vector ingresado es:\n");
    printArray(array, arrayLen);
    printf("El Vector ordenado es:\n");
    floatSort(array, arrayLen);
    printArray(array, arrayLen);
    
    return 0;
}

void printArray(float array[], int arrayLen){
    for (int i = 0; i < arrayLen; i++){
        printf("%4.2f\t", array[i]);
    }
    printf("\n");    
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

			if (array[j] < array[j + 1]){ 

				aux = array[j];

				array[j] = array[j + 1];
 
				array[j + 1]=aux;
			}
		}
	}
}