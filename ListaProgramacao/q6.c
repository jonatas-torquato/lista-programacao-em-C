/* 6. Ler dois números inteiros e exibir o quociente e o resto da divisão inteira entre eles. */

#include <stdio.h>
int main(){
    int numero1, numero2;
    int quociente, resto;
    printf("Informe dois numeros inteiros: ");
    scanf("%d %d", &numero1, &numero2);
    
    quociente= numero1 / numero2;
    resto= numero1 % numero2;
    
    printf("Quociente: %d\n", quociente);
    printf("Resto da Divisao: %d\n", resto);
    
    return 0;
}