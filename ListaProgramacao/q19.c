/* 19. Escreva um programa que calcule a raiz de uma equação do primeiro grau. */
#include <stdio.h>
int main(){
    float raiz, a, b;
    
    printf("--- Calcule a raiz de uma equação de primeiro grau ---\n");
    printf("Sabendo que y = ax + b\n\n");
    printf("Informe o valor de a: ");
    scanf("%f", &a);
    printf("Informe o valor de b: ");
    scanf("%f", &b);
    
    raiz = (-b) / a;
    
    printf("\nA raiz da função é: %.2f", raiz);
    
    return 0;
}