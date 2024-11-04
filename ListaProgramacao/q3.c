/*3. Dado o tamanho do raio de uma circunferência, calcular a área e o perímetro da mesma.*/

#include <stdio.h>
int main(){
    float raio, area, perimetro;
    printf("Informe o tamanho do raio de uma circunferencia: ");
    scanf("%f", &raio);
    
    area= (raio*raio) * 3.14;
    perimetro= 2 * raio * 3.14;
    printf("Area: %.2f\n", area);
    printf("Perimetro: %.2f\n", perimetro);
    return 0;
}