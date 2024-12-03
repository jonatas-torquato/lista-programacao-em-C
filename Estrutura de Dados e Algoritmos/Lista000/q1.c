#define ERROR -1
#define MAX 1000
#define TAM 1000
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct Points {
    int x;
    int y;
} Points;

double distancia2Pontos(int x1, int y1, int x2, int y2) {
    int tempX;
    int tempY;
    double temp;
    tempX = (x2 - x1) * (x2 - x1);
    tempY = (y2 - y1) * (y2 - y1);
    temp = sqrt(tempX + tempY);

    return temp;
}

int main() {
    Points listaPontos[MAX];
    Points listaOrdenada[MAX]; // Cópia para ordenação
    int qtdePontos = 0;

    FILE *fp_in = fopen("L0Q1.in", "r");
    FILE *fp_out = fopen("L0Q1.out", "w");

    if (fp_in == NULL || fp_out == NULL) {
        printf("Files cannot be opened\n");
        return ERROR;
    }

    char line[TAM];
    while (fgets(line, sizeof(line), fp_in)) {
        qtdePontos = 0; // Resetar a contagem para cada linha

        // Ler cada ponto
        char *slice = strtok(line, " ");
        slice = strtok(NULL, " ");  // Ignorar "points"

        while (slice != NULL) {
            int x, y;
            sscanf(slice, "(%d,%d)", &x, &y);
            if (qtdePontos < MAX) {
                listaPontos[qtdePontos].x = x;
                listaPontos[qtdePontos].y = y;
                listaOrdenada[qtdePontos] = listaPontos[qtdePontos]; // Cópia para ordenação
                qtdePontos++;
            }
            slice = strtok(NULL, " ");
        }

        // Calcular a distância total (de acordo com a ordem da entrada)
        float distanciaTotal = 0.0;
        for (int i = 0; i < qtdePontos - 1; i++) {
            distanciaTotal += distancia2Pontos(listaPontos[i].x, listaPontos[i].y, listaPontos[i + 1].x, listaPontos[i + 1].y);
        }

        // Ordenação dos pontos pela distância até a origem (0,0)
        for (int i = 0; i < qtdePontos - 1; i++) {
            for (int j = 0; j < qtdePontos - i - 1; j++) {
                float d1 = distancia2Pontos(0, 0, listaOrdenada[j].x, listaOrdenada[j].y);
                float d2 = distancia2Pontos(0, 0, listaOrdenada[j + 1].x, listaOrdenada[j + 1].y);
                if (d1 > d2) {
                    Points aux = listaOrdenada[j];
                    listaOrdenada[j] = listaOrdenada[j + 1];
                    listaOrdenada[j + 1] = aux;
                }
            }
        }

        // Calcular a distância dos pontos (ordem crescente)
        float shortcut = 0.0;

        shortcut += distancia2Pontos(listaPontos[0].x, listaPontos[0].y, listaPontos[qtdePontos - 1].x, listaPontos[qtdePontos - 1].y);

        // Escreve a saída no arquivo (L0Q1.OUT)
        fprintf(fp_out, "points");
        for (int i = 0; i < qtdePontos; i++) {
            fprintf(fp_out, " (%d,%d)", listaOrdenada[i].x, listaOrdenada[i].y);
        }
        fprintf(fp_out, " distance %.2f shortcut %.2f\n", distanciaTotal, shortcut);
    }

    fclose(fp_in);
    fclose(fp_out);
    return EXIT_SUCCESS;
}
