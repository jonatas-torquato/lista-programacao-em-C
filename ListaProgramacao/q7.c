/* 7. Solicitar a idade de uma pessoa em dias e informar na tela a idade em anos, meses e dias. */

#include <stdio.h>
int main(){
    int idade, anos, meses, dias;
    printf("Informe a sua idade em dias: ");
    scanf("%d", &idade);
    
    anos= idade/360;
    meses= (idade%360)/30;
    dias= (idade%360)%30;
    
    printf("Ano(s): %d\n", anos);
    printf("Mes(es): %d\n", meses);
    printf("Dias: %d", dias);
    
    return 0;
}