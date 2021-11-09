
int floatBinarySearch(float array[], int x) {
  int arrayLen = sizeof(array) / sizeof(array[0]); 
  int center = 0, min = 0, max = arrayLen - 1 ; 
   
  while(min <= max){
    
    center = ((max - min) / 2) + min;
    
    if (array[center] == x) return center;

    if (x < array[center]) max = center - 1;
    else min=center+1;
  }
  return -1;
}

int intBinarySearch(int array[], int x) {
  int arrayLen = sizeof(array) / sizeof(array[0]); 
  int center = 0, min = 0, max = arrayLen - 1 ; 
   
  while(min <= max){
    
    center = ((max - min) / 2) + min;
    
    if (array[center] == x) return center;

    if (x < array[center]) max = center - 1;
    else min=center+1;
  }
  return -1;
}