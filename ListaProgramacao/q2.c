/*2. Dado o tamanho do lado de um quadrado, calcular a área e o perímetro do mesmo.*/

#include <stdio.h>
int main(){
    float lado, area, perimetro;
    printf("Informe o tamanho do lado de um quadrado: ");
    scanf("%f", &lado);
    
    area= lado * lado;
    perimetro= lado * 4;
    printf("Area: %.2f \nPerimetro: %.2f", area, perimetro);
}