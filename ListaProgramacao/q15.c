/* 15. Num dia de sol, você deseja medir a altura de um prédio, porém, a trena não é 
suficientemente longa. Assumindo que seja possível medir sua sombra e a do prédio no 
chão, e que você lembre da sua altura, faça um programa para ler os dados necessários e 
calcular a altura do prédio. */

#include <stdio.h>
int main(){
    float altura, sombra, alturaPredio, sombraPredio;
    printf("Informe a sua altura e a medida da sua sombra: ");
    scanf("%f %f", &altura, &sombra);
    printf("Informe a medida da sombra do predio: ");
    scanf("%f", &sombraPredio);
    
    alturaPredio= (altura*sombraPredio) / sombra;
    
    printf("Altura do predio: %.2f", alturaPredio);

    return 0;
}