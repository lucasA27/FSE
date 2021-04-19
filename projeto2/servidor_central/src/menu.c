#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "../inc/client.h"


int input;

void menu(){

        printf("-------------------------------------------------------------------------------\n");
        printf("digite 1 ou 2 para ligar o ar-condicionado 1 ou 2 respectivamente.         \n");
        printf("digite 3 ou 4 para desligar o ar-condicionado 1 ou 2 respectivamente.       \n");
        printf("digite 5, 6, 7 ou 8 para ligar as lampadas 1, 2, 3 ou 4 respectivamente.      \n");
        printf("digite 9, 10, 11 ou 12 para desligar as lampadas 1, 2, 3 ou 4 respectivamente. \n");
        printf("digite 0 para sair do programa\n");
        printf("--------------------------------------------------------------------------------\n");
        scanf("%d", &input);
    switch (input){
    case 0:
        printf("fechando o programa...\n");
        exit(0);
        break;
    case 1:
        client("1");
        printf("ligar o ar-condicionado 1 solicitado\n");
        break;

    case 2:
        client("2");
        printf("ligar o ar-condicionado 2 solicitado\n");
        break;

    case 3:
        client("3");
        printf("desligar o ar-condicionado 1 solicitado\n");
        break;

    case 4:
        client("4");
        printf("desligar o ar-condicionado 2 solicitado\n");
        break;
    
    case 5:
        client("5");
        printf("ligar a lampada 1 solicitado\n");
        break;
    
    case 6:
        client("6");
        printf("ligar a lampada 2 solicitado\n");
        
        break;
    
    case 7:
        client("7");
        printf("ligar a lampada 3 solicitado\n");
        
        break;
    
    case 8:
        client("8");
        printf("ligar a lampada 4 solicitado\n");
        
        break;
    
    case 9:
        client("9");
        printf("desligar a lampada 1 solicitado\n");
        
        break;
    
    case 10:
        client("a");
        printf("desligar a lampada 2 solicitado\n");
        
        break;
    
    case 11:
        client("b");
        printf("desligar a lampada 3 solicitado\n");
        
        break;
    
    case 12:
        client("c");
        printf("desligar a lampada 4 solicitado\n");
        
        break;

    default:
        printf("comando inválido\n");
        break;
    }
        
}