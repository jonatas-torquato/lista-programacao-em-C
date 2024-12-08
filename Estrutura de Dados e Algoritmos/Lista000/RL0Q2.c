// CÓDIGO AINDA EM DESENVOLVIMENTO //

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

typedef struct Strings {
    char string[TAM];
} Strings;

typedef struct Inteiro {
    int nInt;
} Inteiro;

typedef struct Floats {
    int nFloat;
} Floats;

typedef struct Line {
    Strings listaString[TAM];
    Inteiro nInt[TAM];
    Floats nFloat[TAM];
    Points points[TAM];
} Line;

int ehString(char *string){
    int i = 0;
    int cont = 0;

    while(((string[i] >= 'a') && (string[i] <= 'z')) || ((string[i] >= 'A') && (string[i] <= 'Z'))){
        cont++;
    }
    
    if(cont>0){
        return 1;
    } else{
        return 0;
    }
}

int ehInteiro(char *string){
    int i = 0;
    int cont = 0;

    while((string[i] >= 0) && (string[i] <= 9)){
        cont++;
    }
    
    if(cont>0){
        return 1;
    } else{
        return 0;
    }
}

int verificaString(char *string){
    int i = 0;
    int j = 0;
    char stringAux[MAX];

    while(((string[i] >= 'a') && (string[i] <= 'z')) || ((string[i] >= 'A') && (string[i] <= 'Z'))){
        stringAux[j] = string[i];
        j++;
    }
    stringAux[j] = '\0';
}

int main(){
    Line listaValores[MAX];

    int qtdeValores = 0;

    FILE *fp_in = fopen("L0Q1.in", "r");
    FILE *fp_out = fopen("L0Q1.out", "w");

    if (fp_in == NULL || fp_out == NULL) {
        printf("Files cannot be opened\n");
        return ERROR;
    }

    char line[TAM];

    while (fgets(line, sizeof(line), fp_in)) {
        qtdeValores = 0; // Resetar a contagem para cada linha

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



}