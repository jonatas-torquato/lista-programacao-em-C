/* 22. Escreva um programa que leia um número e exiba o seu módulo. */

#include <stdio.h>
int main(){
    int numero, modulo;
    printf("Informe o numero: ");
    scanf("%d", &numero);
    
    if(numero>=0){
        modulo = numero - 0;
    } else{
        modulo = numero * (-1);
    }
    
    printf("\nO modulo de |%d| = %d", numero, modulo);
    
    return 0;
}