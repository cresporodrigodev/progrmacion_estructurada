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