/* 8. Dado que a fórmula para conversão de Fahrenheit para Celsius é C = 5/9 (F – 32), 
leu um valor de temperatura em Fahrenheit e exibi-lo em Celsius */

#include <stdio.h>
int main(){
    float temperaturaCelsius, temperaturaFahrenheit, temperaturaCelsiusFahrenheit;
    printf("Informe a temperatura em Fahrenheit: ");
    scanf("%f", &temperaturaFahrenheit);
    
    temperaturaCelsius= (temperaturaFahrenheit - 32)/1.8;
    
    printf("Temperatura em Celsius: %f", temperaturaCelsius);
    
    return 0;
}