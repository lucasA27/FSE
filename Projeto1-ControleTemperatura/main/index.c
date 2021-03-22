#include "../gpio/uart.h"
#include "../bme280/bme280.h"
#include "../lcd/lcd.h"
#include "../pwm/resistor.h"
#include "../pwm/ventoinha.h"
#include "../pid/pid.h"
#include "../arquivo/escreverArq.h"
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int entUsuario=0;
float tempUsuario=0;
int opcao,decisao;
float tempInterno, tempExter, tempReferen;

void desliga(){
    DesligaResistor();
    DesligaVentoinha();
    ClrLcd();
    printf("\ndesligando...\n");
    exit(0);
}

void trataAlarm(){
    alarm(1);
}

void  menu(){
    inicio:
    printf("1 - ENTRAR COM TEMPERATURA DO POTENCIOMETRO \n2 - ESCOLHER TEMPERATURA \n3 - SAIR \n");
    scanf("%d", &opcao);
    switch (opcao) {
    case 1:
        printf("Temperaturara do potenciometro escolhida\n");
        tempReferen = TemperaturaPotenciometro();
        break;
    case 2:
        printf("Digite uma temperatura\n");
        scanf("%f", &tempUsuario);

        break;
    case 3:
        printf("voce pediu para sair, prencione qualquer tecla para continuar\n");
        break;
    default:
        printf("voce deve escolher uma opcao valida\n");
        printf("Precione qualquer tecla para voltar ao menu\n");
        goto inicio;
    }

}

void trata_menu(){
    menu();
}

int main(void){
    
    configLcd();
    pid_configura_constantes(5, 1, 5);
    bme280Init(1, 0x76);
    cabecalho();
    menu();

    int tempExter, p, h, iniciar;
    float resistor, ventoinha;
    
    while(1)
    {

    alarm(1);
    signal(SIGALRM, trataAlarm );
    signal(SIGINT, desliga);
    signal(SIGTSTP, trata_menu);

    tempInterno = TemperaturaInterna();
    //tempReferen = TemperaturaPotenciometro();


    if(opcao == 2){
        tempReferen = tempUsuario;
    }else{
        tempReferen = TemperaturaPotenciometro();
    }

    bme280ReadValues(&tempExter, &p, &h);
    pid_atualiza_referencia(tempReferen);

    double controlaPid = pid_controle(tempInterno);

    if (controlaPid > 0){
        
       LigaResistor(controlaPid);
       resistor = controlaPid;
       DesligaVentoinha();
        
    }else if(controlaPid < -40 ){

       LigaVentoinha(controlaPid*(-1));
       ventoinha = controlaPid*(-1);
       DesligaResistor();

    }else{
        DesligaResistor();
        DesligaVentoinha();
    }

    EscreveNaLCD(tempInterno, (float)tempExter/100, tempReferen);

    printf("                              Ventoinha: %.2f  Resistor: %.2f                               \n", ventoinha, resistor);
    printf(" Temperatura interna: %.2f graus Temperatura externa: %.2f graus Temperatura de Referencia: %.2f graus\n", tempInterno, (float)tempExter/100, tempReferen);
    printf("                      pressione crtl + z para voltar ao menu                    \n");
    printf("                                  pressione crtl + c para sair                                        \n");

    escreveArquivo( tempInterno, (float)tempExter/100, tempReferen, resistor, ventoinha);

    pause();

    }

    return 0;
}

