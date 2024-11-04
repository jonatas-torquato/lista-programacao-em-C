/*1. Dado o tamanho da base e da altura de um retângulo, calcular a sua área e o seu
perímetro.*/

#include <stdio.h>
int main(){
    float base, altura, area, perimetro;
    printf("Informe a base de um triangulo: ");
    scanf("%f", &base);
    printf("Informe a altura de um triangulo: ");
    scanf("%f", &altura);
    
    area= base * altura;
    perimetro= 2*(base+altura);
    printf("Area: %.2f \nPerimetro: %.2f", area, perimetro);
}