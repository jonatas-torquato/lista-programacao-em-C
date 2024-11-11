/* 16. Escreva um programa para gerar o invertido de um número com três algarismos 
(exemplo: o invertido de 498 é 894). */

#include <stdio.h>
int main(){
    int numero, centena, dezena, decimal, numeroInvertido;
    printf("Digite o numero de 3 algarismos: ");
    scanf("%d", &numero);
    
    centena= numero/100;
    dezena= (numero%100)/10;
    decimal= ((numero%100)%10)%10;
    
    numeroInvertido= (decimal*100) + (dezena*10) + centena;
    
    printf("Numero Invertido: %d", numeroInvertido);

    return 0;
}