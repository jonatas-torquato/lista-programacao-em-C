/* 5. Ler um número inteiro e exibir o seu sucessor. */

#include <stdio.h>
int main(){
    int num;
    printf("Informe um numero: ");
    scanf("%d", &num);

    printf("Sucessor: %d", ++num);
    
    return 0;
}