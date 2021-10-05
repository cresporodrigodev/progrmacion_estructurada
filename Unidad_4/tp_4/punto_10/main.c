// Ingresar las edades y estaturas de los alumnos, calcular e imprimir
// la edad promedio, la edad mayor y la estatura menor,
// los datos finalizan con edad = 0

#include <stdio.h>
#define TRUE 1
#define FALSE 0

int scanIntPositive(char *message, int i);
float scanFloat(char *message, int i);

int main(){
    int notEntries, i, age, totalAge, maxAge;
    float height, minHeight;
    char heightRequest[] = "Ingrese estatura";
    char ageRequest[] = "Ingrese la edad";

    i = totalAge = maxAge = minHeight = 0;
    notEntries = FALSE;
    do {
        height = scanFloat(heightRequest, i + 1);
        age = scanIntPositive(ageRequest, i + 1);

        if (i == 0){
            if (age == 0){
                notEntries = TRUE;
                break;
            }
            else minHeight = height;
        }
        totalAge += age;

        if (age > maxAge) maxAge = age;
        if (height < minHeight) minHeight = height;
        
        i++;
    } while (age != 0);

    if (notEntries) printf("Sin entrada validas");
    else{
        printf("- La edad promedio es: %d", totalAge / i);
        printf("- La mayor edad es: %d", maxAge);
        printf("- La menor estatura es: %.2f", minHeight);

    }

    return 0;
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

int scanIntPositive(char *message, int i){
    char err[] = "Debe ingresar un valor positivo.\n";
    int q, input;
    do{
        printf("%s %d\n", message, i);
        fflush(stdout);
        fflush(stdin);
        input = scanf("%d", &q);
        if (q < 0){
            printf("%s", err);
            fflush(stdout);
        }
        
    }while (q < 0);
}