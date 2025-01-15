#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>

#define ERROR -1

// Struct para representar uma lista de números naturais
typedef struct NumerosNaturais{
    int *numeros; // ponteiro para percorrer todos os elementos de um start
    int soma; // soma de todos os elementos
    int contador; // quantidade de números na lista
} NumerosNaturais;

// Struct para representar uma linha, que contém várias listas
typedef struct Linha{
    NumerosNaturais *listasNumerosNaturais;  // Vetor de listas
    int totalListas;  // Total de listas na linha
} Linha;

// Função para trocar duas listas
void trocar(NumerosNaturais *x, NumerosNaturais *y){
    NumerosNaturais aux = *x;
    *x = *y;
    *y = aux;
}

// Função Bubble Sort para ordenar números de uma lista
void bubbleSortNumeros(int numeros[], int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - 1 - i; j++){
            if(numeros[j] > numeros[j + 1]){
                // Troca os elementos se eles estiverem na ordem errada
                int temp = numeros[j];
                numeros[j] = numeros[j + 1];
                numeros[j + 1] = temp;
            }
        }
    }
}

// Função QuickSort para ordenar as listas com base na soma dos números
void quickSort(NumerosNaturais listaAuxiliar[], int menor, int maior){
    if(menor < maior){
        int i = menor - 1;
        int pivo = listaAuxiliar[maior].soma; // Pivô é a soma da última lista

        for(int j = menor; j < maior; j++){
            if(listaAuxiliar[j].soma <= pivo){
                i++;
                trocar(&listaAuxiliar[i], &listaAuxiliar[j]);
            }
        }

        trocar(&listaAuxiliar[i + 1], &listaAuxiliar[maior]);

        int p = i + 1;

        // Ordena as partes antes e depois do pivô
        quickSort(listaAuxiliar, menor, p - 1);
        quickSort(listaAuxiliar, p + 1, maior);
    }
}

int main(){
    // Aloca memória para a linha (que pode ter várias listas)
    Linha linha;
    linha.listasNumerosNaturais = malloc(1000 * sizeof(NumerosNaturais));
    linha.totalListas = 0;

    int countNumeros = 0;
    int linhaAtual = 0;

    // Abre o arquivo de entrada 'L1Q1.in' para leitura
    FILE *fp_in = fopen("L1Q1.in", "r");
    // Abre o arquivo de saída 'L1Q1.out' para escrever
    FILE *fp_out = fopen("L1Q1.out", "w");

    if(fp_in == NULL || fp_out == NULL){
        printf("Erro ao abrir arquivos\n");
        return ERROR;
    }

    char line[1000];
    int qtdeLinhas = 0;
    while(fgets(line, sizeof(line), fp_in)){
        qtdeLinhas++;
    }
    rewind(fp_in);

    // Separa a string em pedaços chamados 'slices' por linha
    while(fgets(line, sizeof(line), fp_in)){
        linhaAtual++;
        linha.totalListas = 0; // Resetar a contagem de listas para a nova linha

        // Inicializa a linha com uma lista
        linha.listasNumerosNaturais[linha.totalListas].numeros = malloc(1000 * sizeof(int));
        linha.listasNumerosNaturais[linha.totalListas].soma = 0;
        linha.listasNumerosNaturais[linha.totalListas].contador = 0;

        char *slice = strtok(line, " ");
        slice = strtok(NULL, " ");  // Ignorar "start"

        // Processa os números e distribui nas listas da linha
        while(slice != NULL){
            if(strcmp(slice, "start") == 0){
                // Inicializa uma nova lista dentro da linha
                linha.totalListas++;
                linha.listasNumerosNaturais[linha.totalListas].numeros = malloc(1000 * sizeof(int));
                linha.listasNumerosNaturais[linha.totalListas].soma = 0;
                linha.listasNumerosNaturais[linha.totalListas].contador = 0;
            } else{
                // Adiciona o número à lista atual da linha
                int num;
                sscanf(slice, "%d", &num);
                linha.listasNumerosNaturais[linha.totalListas].numeros[linha.listasNumerosNaturais[linha.totalListas].contador] = num;
                linha.listasNumerosNaturais[linha.totalListas].soma += num;
                linha.listasNumerosNaturais[linha.totalListas].contador++;
            }
            slice = strtok(NULL, " ");
        }

        // Ordenar os números de cada lista usando Bubble Sort
        for(int i=0; i<=linha.totalListas; i++){
            bubbleSortNumeros(linha.listasNumerosNaturais[i].numeros, linha.listasNumerosNaturais[i].contador);
        }

        // Ordenação das listas com base na soma dos elementos
        quickSort(linha.listasNumerosNaturais, 0, linha.totalListas);

        // Array para armazenar as últimas posições das somas
        int ultimaPosicao[1000] = {0};

        // Imprimir as listas ordenadas
        for(int i = 0; i <= linha.totalListas; i++){
            ultimaPosicao[linha.listasNumerosNaturais[i].soma] = i; // Armazenar o índice da última ocorrência da soma
        }

        int ultimaLista = INT_MIN; // Variável para armazenar a última soma impressa
        for(int i=0; i<=linha.totalListas; i++){
            // Imprimir apenas se a soma da lista for a última ocorrência dessa soma
            if(i == ultimaPosicao[linha.listasNumerosNaturais[i].soma]){
                fprintf(fp_out, "start");
                for(int j=0; j<linha.listasNumerosNaturais[i].contador; j++){
                    fprintf(fp_out, " %d", linha.listasNumerosNaturais[i].numeros[j]);
                }
                // AJEITAR !!
                if(!linha.listasNumerosNaturais[linha.totalListas - 1].contador - 1){
                    fprintf(fp_out, " ");
                }
                
            }
        }

        if(linhaAtual != qtdeLinhas){
            fprintf(fp_out, "\n");
        }
    }

    // Libera a memória alocada
    for(int i = 0; i <= linha.totalListas; i++){
        free(linha.listasNumerosNaturais[i].numeros);
    }
    free(linha.listasNumerosNaturais);

    fclose(fp_in);
    fclose(fp_out);
        
    return EXIT_SUCCESS;
}

