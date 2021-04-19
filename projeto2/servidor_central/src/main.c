#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include "../inc/client.h"
#include "../inc/menu.h"
#include "../inc/servidor.h"
#include <stdbool.h>

char confirme;

void fecharSockets(int signal){
        fecharServidor();
        fecharCliente();
        exit(0);
}

void tratamenu(int signal){
        set_deveprintar(0);
        menu();
        set_deveprintar(1);
}

void* alarme_thread(void *s){  
        distribuido();
}

int main(){
        pthread_t thread_alarme;
        pthread_create(&thread_alarme,NULL, alarme_thread,NULL);

        printf("----------------------------------------BEM-VINDO-------------------------------------------\n");
        printf("Digite qualquer tecla e pressione enter para começar, pressione ctrl + z para ir para ao menu\n");

        scanf("%s", &confirme);

        signal(SIGTSTP, tratamenu);
        signal(SIGINT, fecharSockets);
        while(1){
                client("temp");
                usleep(1000000);
        }

        pthread_join(thread_alarme,NULL);
        return 0;
}