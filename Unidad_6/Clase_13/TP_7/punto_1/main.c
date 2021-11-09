// Ingrese 20 valores en un vector e imprimalo ordenado
// utilizando el algoritmo bubblesort u
// ordenamiento por burbujeo.

#include <stdio.h>

void floatSort(float (*array), int arrayLen);
float scanFloat(char *message, int i);

int main(){
    float array[10] = {0};
    float input = 0;
    int arrayLen = sizeof(array) / sizeof(array[0]);
    char messageRequest[] = "Ingrese la posicion numero";

    for (int i = 0; i < arrayLen; i++){
        input = scanFloat(messageRequest, i + 1);
        array[i] = input;
    }

    printf("Array desordenado\n");
    for (int i = 0; i < arrayLen; i++){
        printf("%4.2f\t", array[i]);
        fflush(stdout);
    }
    printf("\n");
    
    floatSort(array, arrayLen);

    printf("Array ordenado\n");
    for (int i = 0; i < arrayLen; i++){
        printf("%4.2f\t", array[i]);
        fflush(stdout);
    }

    return 0;
    
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

float scanFloat(char *message, int i){
    char errType[] = "Debe ingresar un valor numerico.\n";
    float q;
    int input;
    do
    {
        printf("%s %d.\n", message, i);
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