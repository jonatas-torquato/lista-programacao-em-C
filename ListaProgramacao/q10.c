/* 10. Converter um inteiro informado menor que 32 para sua representação em binário */

#include <stdio.h>
int main(){
    int numero;
    int quociente1, quociente2, quociente3, quociente4, quociente5;
    int resto1, resto2, resto3, resto4, resto5;
    printf("Informe o numero inteiro menor que 32: ");
    scanf("%d", &numero);
    
    quociente1= numero/2;
    resto1= numero%2;
    quociente2= quociente1/2;
    resto2= quociente1%2;
    quociente3= quociente2/2;
    resto3= quociente2%2;
    quociente4= quociente3/2;
    resto4= quociente3%2;
    quociente5= quociente4/2;
    resto5= quociente4%2;

    printf("%d %d %d %d %d %d", quociente5, resto5, resto4, resto3, resto2, resto1);
    
    return 0;
}