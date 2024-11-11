/* 11. Faça um algoritmo para calcular a nota semestral de um aluno. A nota semestral é obtida pela média aritmética entre a nota de 2 bimestres. Cada nota de bimestre é composta por 
2 notas de provas. 
*/

#include <stdio.h>
int main(){
	float prova1, prova2, prova3, prova4, media;
	
	printf("--- Digite as notas das provas do 1º bimestre ---\n");
	printf("Prova 1: ");
	scanf("%f", &prova1);
	printf("Prova 2: ");
	scanf("%f", &prova2);
	printf("\n--- Digite as notas das provas do 2º bimestre ---\n");
	printf("Prova 3: ");
	scanf("%f", &prova3);
	printf("Prova 4: ");
	scanf("%f", &prova4);
	
	media = (prova1+prova2) + (prova3+prova4) / 2;
	printf("Nota semestral: %.2f", media);
	
	return 0;
}