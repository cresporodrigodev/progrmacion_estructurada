// Desarrollar un programa que presente un menú con las siguientes opciones:
// -	1 Cargar datos (carga dos valores para ser operados)
// -	2 Sumar valores
// -	3 Restar mayor – menor.
// -	4 Calcular el factorial del mayor.
// -	0 Salir

#include <stdio.h>
#define TRUE 1
#define FALSE 0
#define OPTION_ADD_DATA 1
#define OPTION_SUM 2
#define OPTION_SUBSTRACT 3
#define OPTION_FACTORIAL 4
#define OPTION_EXIT 5

int scanIds(char *message);
float scanFloat(char *message);
void sum(float x, float y);
void subtract(float x, float y);
void printfactorial(float x, float y);
float getHigher(float x, float y, int *err);
int getFactorial(int f);


int main(){
    int option, addData;
    float x, y;
    char err[] = "Por favor, primero cargue los datos.\n";
    char requestX[] = "Ingrese el primer valor\n";
    char requestY[] = "Ingrese el segundo valor\n";
    char optionRequest[] = "- 1: Cargar datos.\n- 2: Sumar valores\n- 3: Restar mayor menos menor\n- 4: Calcular factorial del mayor\n- 5: Salir.\n";

    printf("Bienvenido.\n Las opciones disponibles son:\n");

    addData = FALSE;
    option = -1;

    do{
        if (addData == TRUE && option != OPTION_EXIT){
            printf("Los valores ingresados son:\n- %.2f\n- %.2f\n", x, y);
            fflush(stdout);
        }        

        option = scanIds(optionRequest);

        if (addData == FALSE && option != OPTION_ADD_DATA){
            printf("%s", err);
            fflush(stdout);
            continue;
        }
        else{
            switch (option){
            case OPTION_ADD_DATA:
                x = scanFloat(requestX);
                y = scanFloat(requestY);
                addData = TRUE;
                break;
            case OPTION_SUM:
                sum(x, y);
                break;
            case OPTION_SUBSTRACT:
                subtract(x, y);
                break;
            case OPTION_FACTORIAL:
                printfactorial(x, y);
                break;
            case OPTION_EXIT: break;
            default:
                printf("Ocurrio un error.\n");
                break;
            }
        }
    }while (option != OPTION_EXIT);

    return 0;
}

void sum(float x, float y){
    printf("El resultado de la suma es: %.2f\n", x + y);
}

void subtract(float x, float y){
    float less, higher;
    int err;

    higher = getHigher(x, y, &err);

    if(err == FALSE){
        if(higher == x) less = y;
        else less = x;
        printf("El resultado de la resta es: %.2f\n", higher - less);
    }
}

float getHigher(float x, float y, int *err){
    float higher;
    *err = FALSE;
    if (x == y){
        printf("Los valores son iguales. No se puede realizar la operacion.\n");
        *err = TRUE;
    }
    else{
        if (x < y) higher = y;
        else higher = x;
    }
    return higher;
}

void printfactorial(float x, float y){
    int higher, err;

    higher = (int)getHigher(x, y, &err);

    if (err == FALSE){
        printf("El factorial de %d es: %d.\n", higher, getFactorial(higher));
    }
}

int getFactorial(int f){

    if (f == 0) return 1;
    else return f * getFactorial(f - 1);
    
}

int scanIds(char *message){
    char errType[] = "Debe ingresar un valor numerico.\n";
    char err[] = "Debe ingresar un valor entre 0 y 5.\n";
    int q, input;
    do{
        printf("%s", message);
        fflush(stdout);
        fflush(stdin);
        input = scanf("%d", &q);
        if (input != 1){
            printf("%s", errType);
            fflush(stdout);
        }
        else if (q < 0 || q > 5){
            printf("%s", err);
            fflush(stdout);
        }
        
    }while (q < 0 || q > 5);
    
    return q;
}

float scanFloat(char *message){
    char errType[] = "Debe ingresar un valor numerico.\n";
    float q;
    int input;
    do{
        printf("%s", message);
        fflush(stdout);
        fflush(stdin);
        input = scanf("%f", &q);
        if (input != 1){
            printf("%s", errType);
            fflush(stdout);
        }
        
    }while (input != 1);
    
    return q;
}