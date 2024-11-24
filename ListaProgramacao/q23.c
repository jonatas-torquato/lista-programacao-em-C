/* 23. Escreva um programa que leia um número e imprima se este número é ou não par. */

#include <stdio.h>
int main(){
    int numero, x;
    printf("Informe o numero: ");
    scanf("%d", &numero);
    
    x = numero % 2;
    
    if(x==0){
        printf("\n%d eh Par.", numero);
    } else{
        printf("\n%d eh Impar.", numero);
    }
    
    return 0;
}