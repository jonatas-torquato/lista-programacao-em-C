/* 25. Escreva um programa que leia o número equivalente ao mês e imprima a quantidade de 
dias deste mês. */

#include <stdio.h>
int main(){
    int mes;
    printf("Digite o numero equivalente ao mes de 1 a 12: ");
    scanf("%d", &mes);
    
    switch(mes){
        case 1:{
            printf("31 dias.");
            break;
        }
        case 2:{
            printf("28 dias.");
            break;
        }
        case 3:{
            printf("31 dias.");
            break;
        }
        case 4:{
            printf("30 dias.");
            break;
        }
        case 5:{
            printf("31 dias.");
            break;
        }
        case 6:{
            printf("30 dias.");
            break;
        }
        case 7:{
            printf("31 dias.");
            break;
        }
        case 8:{
            printf("31 dias.");
            break;
        }
        case 9:{
            printf("30 dias.");
            break;
        }
        case 10:{
            printf("31 dias.");
            break;
        }
        case 11:{
            printf("30 dias.");
            break;
        }
        case 12:{
            printf("31 dias.");
            break;
        }
        default:{
            printf("Numero invalido.");
            break;
        }
    }

    return 0;
}
