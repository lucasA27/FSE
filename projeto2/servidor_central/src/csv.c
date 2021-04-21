#include <stdio.h>
#include <time.h>

void cabecalho(){
    FILE *arquivo = fopen("./data/graph.csv", "w");
    if(arquivo == NULL){
        printf("arquivo nao foi aberto\n");
    }else{
        fprintf(arquivo,"cliente,data,hora \n");
        fclose(arquivo);
    }
}

void escreveArquivo(char *cliente){

    time_t timer;
    char buffer[26];
    struct tm* tm_info;

    timer = time(NULL);
    tm_info = localtime(&timer);

    strftime(buffer, 26, "%Y-%m-%d, %H:%M:%S", tm_info);
    
    FILE *arquivo = fopen("./data/graph.csv", "a");
    if(arquivo == NULL){
        printf("arquivo nao foi aberto\n");
    }else{
        fprintf(arquivo,"%s,%s\n", cliente, buffer);
        fclose(arquivo);
    }
}