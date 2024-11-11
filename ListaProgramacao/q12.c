/* 12. Faça um algoritmo que transforme uma velocidade fornecida em m/s pelo usuário para 
Km/h. Para tal, multiplique o valor em m/s por 3,6.  */
#include <stdio.h>
int main(){
    float ms, kmh;
    printf("Informe a velocidade em m/s: ");
    scanf("%f", &ms);
    
    kmh= ms * 3.6;
    
    printf("Velocidade: %.2f Km/h", kmh);

    return 0;
}