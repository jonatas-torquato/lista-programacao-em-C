/* 24. Escreva um programa que leia três números e mostre o maior entre eles. */

#include <stdio.h>
int main(){
    int n1, n2, n3;
    printf("Informe o primeiro numero: ");
    scanf("%d", &n1);
    printf("Informe o segundo numero: ");
    scanf("%d", &n2);
    printf("Informe o terceiro numero: ");
    scanf("%d", &n3);
    
    if((n1 >= n2) && (n1 >= n3)){
        printf("O maior numero: %d", n1);
    } else if((n2 >= n1) && (n2 >= n3)){
        printf("O maior numero: %d", n2);
    } else if((n3 >= n1) && (n3 >= n2)){
        printf("O maior numero: %d", n3);
    }
    
    return 0;
}