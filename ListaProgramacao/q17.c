/* 17.  Um programa para gerenciar os saques de um caixa eletrônico deve possuir algum 
mecanismo para decidir o número de notas de cada valor que deve ser disponibilizado 
para o cliente que realizou o saque. Um possível critério seria o da "distribuição ótima" 
no sentido de que as notas de menor valor fossem distribuídas em número mínimo 
possível. Por exemplo, se a quantia solicitada fosse R$ 87,00, o programa deveria indicar 
uma nota de R$ 50,00, três notas de R$ 10,00, uma nota de R$ 5,00 e duas notas de R$ 
1,00. Escreva um programa que receba o valor da quantia solicitada e retorne a
distribuição das notas de acordo com o critério da distribuição ótima (considere existir 
notas de R$1,00; R$2,00; R$5,00; R$10,00; R$20,00; R$50,00 e R$100,00)   */

#include <stdio.h>
int main(){
    int valor;
    int div100, div50, div20, div10, div5, div2, div1;
    
    printf("Digite o valor da quantia: ");
    scanf("%d", &valor);
    
    div100 = valor/100;
    div50 = (valor%100)/50;
    div20 = ((valor%100)%50)/20;
    div10 = (((valor%100)%50)%20)/10;
    div5 = ((((valor%100)%50)%20)%10)/5;
    div2 = (((((valor%100)%50)%20)%10)%5)/2;
    div1 = ((((((valor%100)%50)%20)%10)%5)%2)/1;
    
    printf("\nNotas de 100: %d", div100);
    printf("\nNotas de 50: %d", div50);
    printf("\nNotas de 20: %d", div20);
    printf("\nNotas de 10: %d", div10);
    printf("\nNotas de 5: %d", div5);
    printf("\nNotas de 2: %d", div2);
    printf("\nNotas de 1: %d", div1);


    return 0;
}