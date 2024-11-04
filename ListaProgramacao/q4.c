/*4. Dado os três lados de um triângulo determinar o perímetro do mesmo. */

#include <stdio.h>
int main(){
    float lado, perimetro;
    printf("Informe o lado do triangulo: ");
    scanf("%f", &lado);
    
    perimetro= lado * 3.0;
    printf("\nPerimetro: %.2f", perimetro);
    return 0;
}