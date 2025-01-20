/*
    ----- Dados do Aluno -----
    Nome: Pedro Vitor Aquino Ferreira
    email: pedro.aquino.ct@gmail.com
    Matrícula: 20222160022
    Semestre: 2024/2

    ----- Dados do Aluno -----
    Nome: Jônatas Alfa Torquato de Souza
    email: jonatas.alfatorquato@gmail.com
    Matrícula: 20221160002
    Semestre: 2024/2
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX_LINHA 1024
#define MAX_VALORES 100

// Função para ler os dados do arquivo de entrada
void lerEntrada(const char *nomeArquivo, int leIndices[][MAX_VALORES], int *qtdIndices, float liValores[][MAX_VALORES], int *qtdValores, int *qtdComandos) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo de entrada");
        exit(EXIT_FAILURE);
    }

    char linha[MAX_LINHA];
    *qtdComandos = 0;

    while (fgets(linha, sizeof(linha), arquivo)) {
        int leCount = 0;
        int liCount = 0;
        int lendoLI = 0;

        char *token = strtok(linha, " ");
        while (token != NULL) {
            if (strcmp(token, "LE") == 0) {
                lendoLI = 0;
            } else if (strcmp(token, "LI") == 0) {
                lendoLI = 1;
            } else if (lendoLI) {
                liValores[*qtdComandos][liCount++] = atof(token);
            } else {
                leIndices[*qtdComandos][leCount++] = atoi(token);
            }
            token = strtok(NULL, " ");
        }

        qtdIndices[*qtdComandos] = leCount;
        qtdValores[*qtdComandos] = liCount;
        (*qtdComandos)++;
    }

    fclose(arquivo);
}

// Função para escrever os resultados no arquivo de saída
void escreverSaida(const char *nomeArquivo, char resultados[][MAX_LINHA], int qtdComandos) {
    FILE *arquivo = fopen(nomeArquivo, "w");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo de saída");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < qtdComandos; i++) {
        fprintf(arquivo, "%s\n", resultados[i]);
    }

    fclose(arquivo);
}

// Função para ordenar um array de números reais
void ordenarValores(float valores[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = i + 1; j < tamanho; j++) {
            if (valores[i] > valores[j]) {
                float temp = valores[i];
                valores[i] = valores[j];
                valores[j] = temp;
            }
        }
    }
}

void criarListaCircular(int chaveLE, float valores[], int tamanho, int usados[], char *resultado) {
    if (tamanho == 0) return;

    // Ordena os valores
    ordenarValores(valores, tamanho);

    // Adiciona valores que estão dentro do intervalo da chaveLE e não foram usados
    char buffer[32];
    int primeiro = 1;

    for (int i = 0; i < tamanho; i++) {
        // Verifica se o valor está dentro do intervalo e ainda não foi utilizado
        if (!usados[i] && valores[i] >= chaveLE - 0.99 && valores[i] <= chaveLE + 0.99) {
            usados[i] = 1;
            snprintf(buffer, sizeof(buffer), "%.2f", valores[i]);

            // Remover zeros a mais
            char *p = buffer + strlen(buffer) - 1;
            while (*p == '0' && *(p - 1) != '.') {
                *p-- = '\0';
            }

            if (!primeiro) {
                strcat(resultado, "->");
            }
            strcat(resultado, buffer);
            primeiro = 0;
        }
    }
}

void processarComandos(int leIndices[][MAX_VALORES], int qtdIndices[], float liValores[][MAX_VALORES], int qtdValores[], int qtdComandos, char resultados[][MAX_LINHA]) {
    for (int i = 0; i < qtdComandos; i++) {
        resultados[i][0] = '\0';
        strcat(resultados[i], "[");

        // Ordena os nós de LE
        for (int j = 0; j < qtdIndices[i] - 1; j++) {
            for (int k = j + 1; k < qtdIndices[i]; k++) {
                if (leIndices[i][j] > leIndices[i][k]) {
                    int temp = leIndices[i][j];
                    leIndices[i][j] = leIndices[i][k];
                    leIndices[i][k] = temp;
                }
            }
        }

        // Array para marcar valores de LI usados
        int usados[MAX_VALORES] = {0};

        for (int j = 0; j < qtdIndices[i]; j++) {
            char listaCircular[MAX_LINHA] = "";

            int chaveAtual = leIndices[i][j];
            criarListaCircular(chaveAtual, liValores[i], qtdValores[i], usados, listaCircular);

            char bloco[64];
            snprintf(bloco, sizeof(bloco), "%d(%s)", chaveAtual, listaCircular);
            strcat(resultados[i], bloco);

            if (j < qtdIndices[i] - 1) {
                strcat(resultados[i], "->");
            }
        }
        strcat(resultados[i], "]");
    }
}


int main(){
    const char *arquivoEntrada = "L1Q3.in";
    const char *arquivoSaida = "L1Q3.out";

    int leIndices[MAX_VALORES][MAX_VALORES];
    int qtdIndices[MAX_VALORES];
    float liValores[MAX_VALORES][MAX_VALORES];
    int qtdValores[MAX_VALORES];
    int qtdComandos;

    char resultados[MAX_VALORES][MAX_LINHA];

    lerEntrada(arquivoEntrada, leIndices, qtdIndices, liValores, qtdValores, &qtdComandos);
    processarComandos(leIndices, qtdIndices, liValores, qtdValores, qtdComandos, resultados);
    escreverSaida(arquivoSaida, resultados, qtdComandos);

    return 0;
}