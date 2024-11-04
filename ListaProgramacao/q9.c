/* 9. Faça um algoritmo que calcule e apresente o valor do volume de uma lata de óleo, dado
seu raio e sua altura */

#include <stdio.h>
int main(){
    float raio, altura, volume;
    printf("Informe o raio da lata de óleo: ");
    scanf("%f", &raio);
    printf("Informe a altura da lata de oleo: ");
    scanf("%f", &altura);
    
    volume = 3.14 * (altura * (raio*raio));
    
    printf("Volume da lata de oleo: %.2f", volume);
    
    return 0;
}