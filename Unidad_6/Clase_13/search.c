#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {

	//creo un array desordenado
	int miArray[]={10,4,14,90,17,1,9,11,23,61};
	int dato = 90;
	
	ordenar(miArray); //invoco la funcion ordenar
	
	int i=0;
	
	
	for(i=0;i<10;i++){
		printf("El valor de la pos %d es %d\n",i,miArray[i]);
	}
	
	printf("Ingrese dato a buscar (0 para terminar): ");
	// scanf("%d",&dato);
	while(dato!=0){
		
		printf("\nCon busqueda binaria\n");
		int resultado=	busquedaBinaria(miArray,dato);
		analizarResultado(resultado);
		
		printf("\nCon busqueda secuecial\n");
		int resultado2=busquedaSecuencial(miArray,dato);
		analizarResultado(resultado2);
		
		
		printf("Ingrese dato a buscar (0 para terminar): ");
		scanf("%d",&dato);
	}

	
}


void ordenar(int array[]){

	int n = 10;
	int i,y,aux=0; 
	for(i=0;i<n-1;i++){ //recorro el array hasta dos posiciones antes del final
		for(y=0;y<n-i-1;y++){ //por cada posicion, vuelvo a recorrerlo todo
		
		//comparo con la posici�n siguiente, si es mayor...
			if (array[y]>array[y+1]){ 
				 //utilizo una variable auxiliar para guardar temporalmente el valor actual
				aux=array[y];
				//guardo en la posicion actual, el valor de la siguiente
				array[y]=array[y+1];
				//guardo en la posicion siguente el valor que teniamos en aux 
				array[y+1]=aux;
			}
		}
	}
}

int busquedaBinaria(int  array[], int dato) {
  int n=10;
  int iteraciones=0;
  int centro,inf=0,sup=n-1;
   
   
   while(inf<=sup){
   	iteraciones++;
      centro=((sup-inf)/2)+inf;
      if(array[centro]==dato)
        {
        	printf("Total de %d iteraciones\n",iteraciones);
            return centro;
        }
      else
        if(dato < array[centro]) 
			sup=centro-1;
          else
           inf=centro+1;
   }
   
    printf("Total de %d iteraciones\n",iteraciones);
   return -1;
}

int busquedaSecuencial(int array[], int dato){
	int i;
	for(i=0;i<10;i++){
		
		if (array[i]==dato){
			printf("Total de %d iteraciones\n",i);
			return i;
		}
	}
	 printf("Total de %d iteraciones\n",i);
	return -1;
}

void analizarResultado(resultado){
	
		if (resultado>=0){
			printf("El dato se encuentra en la posicion %d\n",resultado);
		}
		else
		{
			printf("No se encontro el dato a buscar\n");
		}	
}


