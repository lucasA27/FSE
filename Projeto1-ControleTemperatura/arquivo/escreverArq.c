#include <stdio.h>
#include <time.h>

void cabecalho(){
    FILE *arquivo = fopen("graph.csv", "w");
    if(arquivo == NULL){
        printf("arquivo nao foi aberto");
    }else{
        fprintf(arquivo,"TI,TE,TR,resitor,ventoinha,data,hora \n");
        fclose(arquivo);
    }
}

void escreveArquivo(float tempInterno, float tempExter, float tempReferen, float resistor, float ventoinha){

    time_t timer;
    char buffer[26];
    struct tm* tm_info;

    timer = time(NULL);
    tm_info = localtime(&timer);

    strftime(buffer, 26, "%Y-%m-%d, %H:%M:%S", tm_info);
    
    FILE *arquivo = fopen("graph.csv", "a");
    if(arquivo == NULL){
        printf("arquivo nao foi aberto");
    }else{
        fprintf(arquivo," %.2f,%.2f,%.2f,%.2f,%.2f,%s\n", tempInterno, tempExter, tempReferen, resistor, ventoinha, buffer );
        fclose(arquivo);
    }
}