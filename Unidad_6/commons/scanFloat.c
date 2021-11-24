float scanFloat(char *message)
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