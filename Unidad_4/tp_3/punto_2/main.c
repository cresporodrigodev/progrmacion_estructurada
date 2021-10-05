// Ingresar 20 notas y nombres de alumnos,
// indicar e imprimir los aplazados ( menos de 4) y 
// el nombre a quien pertenece esa nota

#include <stdio.h>
#define MAX 20
#define ASCII_A 97
#define ASCII_Z 122

int scanChar(char *message);
float scanFloat(char *message);

int main(){
    float note = 0;
    float disapproved = 4;
    int name, n;
    char messageNameReq[] = "Ingrese la letra del alumno\n";
    char messageNoteReq[] = "Ingrese la nota\n";

    for (int i = 0; i < MAX; i++){
        n = i + 1;
        printf("- Alumno numero %d\n", n);
        note = scanFloat(messageNoteReq);
        name = scanChar(messageNameReq);

        if (note < disapproved){
            printf("El alumno %c esta aplazado\n", name);
            fflush(stdout);
            printf("Y su nota es: %.2f\n", note);
            fflush(stdout);
        }
    }
    return 0;
}

int scanChar(char *message){
    char errA[] = "Ocurrió un error\n";
    char errB[] = "Debe ingresar una letra\n";
    char q = 0;
    int input;

    do{
        printf("%s", message);
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

float scanFloat(char *message){
    char errA[] = "Ocurrió un error\n";
    char errB[] = "Debe ingresar un valor entre 0 y 10\n";
    float q = 0;
    int input;

    do{
        printf("%s", message);
        fflush(stdout);
        fflush(stdin);
        input = scanf("%f", &q);
        
        if (input != 1){
            printf("%s", errA);
            fflush(stdout);
        }

        if (q < 0 || q > 10){
            printf("%s", errB);
            fflush(stdout);
        }
        
    } while ((q < 0) || (q > 10));

    return q;
}