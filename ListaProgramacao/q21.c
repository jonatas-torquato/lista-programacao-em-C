/* 21. Escreva um programa que leia um número e exiba se ele é positivo ou negativo. */

#include <stdio.h>
int main(){
    int numero;
    printf("Digite um numero: ");
    scanf("%d", &numero);
    
    if(numero<0){
        printf("\n%d eh Negativo.", numero);
    } else if(numero>0){
        printf("\n%d eh Positivo.", numero);
    } else if(numero==0){
        printf("\n%d nao eh Positivo e nem Negativo.", numero);
    }
    
    return 0;
