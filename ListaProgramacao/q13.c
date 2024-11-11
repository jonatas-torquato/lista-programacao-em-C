/* 13. Um circuito elétrico é composto de duas resistências R1 e R2 em paralelo, e ambas em 
sequência de uma resistência R3. Faça um algoritmo para calcular a resistência 
equivalente desse circuito.   */

#include <stdio.h>
int main(){
    float r1, r2, r3, rTotal, r;
    printf("\nDigite o valor da resistência 1: ");
    scanf("%f", &r1);
    printf("\nDigite o valor da resistência 2: ");
    scanf("%f", &r2);
    printf("\nDigite o valor da resistência 3: ");
    scanf("%f", &r3);
    
    r= (1/r1) + (1/r2) + (1/r3);
    rTotal= 1/r;
    
    printf("Resistência equivalente: %.2f", rTotal);

    return 0;
}