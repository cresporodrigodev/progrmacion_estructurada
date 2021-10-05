// Ingresar nombres y notas de alumnos teniendo en cuenta que la
// carga finaliza con nota = 11.
// Calcular e imprimir:
// - el promedio
// - los aprobados
// - cuántos estan entre 4 y 6.

#include <stdio.h>
#define ASCII_A 97
#define ASCII_Z 122

int scanChar(char *message);
float scanFloat(char *message);

int main(){
    float note, totalNote;
    float disapproved = 4;
    int name, n, countApproveds, count4to6;
    char messageNameReq[] = "Ingrese la letra del alumno\n";
    char messageNoteReq[] = "Ingrese la nota\n";

    note = totalNote = countApproveds = count4to6 = n = 0;

    do{
        printf("- Alumno numero %d\n", n + 1);
        
        note = scanFloat(messageNoteReq);
        if (note == 11) continue;
        
        n++;
        totalNote += note;
        name = scanChar(messageNameReq);

        if (note > disapproved){
            countApproveds++;
            printf("El alumno %c esta aprobado. ", name);
            fflush(stdout);
            printf("Su nota es: %.2f\n", note);
            fflush(stdout);
            printf("----------------------------------\n");
            fflush(stdout);

            if (note < 6) count4to6++;
        }
    } while (note != 11);
    
    printf("- El promedio general es: %.2f\n", totalNote / n);
    printf("- El total de aprobados es: %d\n", countApproveds);
    printf("- La cantidad entre 4 y 6 es: %d\n", count4to6);
    
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

        if (q < 0 || q > 11){
            printf("%s", errB);
            fflush(stdout);
        }
        
    } while ((q < 0) || (q > 11));

    return q;
}