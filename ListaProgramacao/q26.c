/* 26. Escreva um programa que leia 3 valores e escreva a soma dos 2 maiores. */

#include <stdio.h>
int main(){
    int n1, n2, n3;
    int soma;
    printf("Informe o primeiro numero: ");
    scanf("%d", &n1);
    printf("Informe o segundo numero: ");
    scanf("%d", &n2);
    printf("Informe o terceiro numero: ");
    scanf("%d", &n3);
    
    printf("\n");
    
    if((n1 >= n3) && (n2 >= n3)){
        soma = n1 + n2;
        printf("O maiores numeros: \nn1 = %d\nn2 = %d", n1, n2);
    } else if((n1 >= n2) && (n3 >= n2)){
        soma = n1 + n3;
        printf("O maiores numeros: \nn1 = %d\nn3 = %d", n1, n3);
    } else if((n2 >= n1) && (n3 >= n1)){
        soma = n2 + n3;
        printf("O maiores numeros: \nn2 = %d\nn3 = %d", n2, n3);
    }
    
    printf("\n\nSoma: %d", soma);

    return 0;
}
