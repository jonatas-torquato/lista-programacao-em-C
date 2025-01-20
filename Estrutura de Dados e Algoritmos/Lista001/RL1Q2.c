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

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 1000
#define MAX 1000
#define EXIT -2
#define CHEIA -3
#define VAZIA -4
#define ERROR -5
#define SUCESSO 1

typedef struct stack {
    char **nomes;
    int top;
    int capacidade;
} Stack;

Stack *init_pilha(int size) {
    Stack *pilha = (Stack *)malloc(sizeof(Stack));
    pilha->nomes = (char **)malloc(size * sizeof(char *));
    pilha->top = -1;
    pilha->capacidade = size;
    return pilha;
}

bool vazia(Stack *pilha) {
    return pilha->top == -1;
}

bool cheia(Stack *pilha) {
    return pilha->top == pilha->capacidade - 1;
}

int push(Stack *pilha, const char *string, FILE *arq_saida) {
    if (!cheia(pilha)) {
        pilha->top++;
        pilha->nomes[pilha->top] = (char *)malloc((strlen(string) + 1) * sizeof(char));
        strcpy(pilha->nomes[pilha->top], string); 
        fprintf(arq_saida, "push-%s ", string);   
        return SUCESSO;
    }
    return CHEIA;
}

char *pop(Stack *pilha) {
    if (!vazia(pilha)) {
        char *removido = pilha->nomes[pilha->top];
        pilha->top--;
        return removido;
    }
    return NULL;
}

char *peek(Stack *pilha) {
    if (vazia(pilha)) {
        return NULL;
    }
    return pilha->nomes[pilha->top];
}

void limparPilha(Stack *pilha) {
    while (!vazia(pilha)) {
        free(pop(pilha));
    }
    pilha->top = -1;
}

void inserirNaOrdem(Stack *pilha, const char *string, FILE *arq_saida) {
    char temp[TAM][MAX];
    int tempTop = -1;
    int popCount = 0;

    while (!vazia(pilha) && strcmp(peek(pilha), string) > 0) {
        strcpy(temp[++tempTop], peek(pilha));
        pop(pilha);
        popCount++;
    }

    if (popCount > 0) {
        fprintf(arq_saida, "%dx-pop ", popCount);
    }

    push(pilha, string, arq_saida);

    while (tempTop >= 0) {
        push(pilha, temp[tempTop--], arq_saida);
    }
}

void inserirNaPilha(Stack *pilha, char **strings, int size, FILE *arq_saida) {
    for (int i = 0; i < size; i++) {
        inserirNaOrdem(pilha, strings[i], arq_saida);
    }
    fprintf(arq_saida, "\n");
}

int main() {
    FILE *fp_in = fopen("L1Q2.in", "r");
    FILE *fp_out = fopen("L1Q2.out", "w");

    if (fp_in == NULL || fp_out == NULL) {
        printf("Erro ao abrir arquivos\n");
        return ERROR;
    }

    char line[1000];
    Stack *pilha = init_pilha(TAM);

    while (fgets(line, sizeof(line), fp_in) != NULL) {
        line[strcspn(line, "\n")] = '\0';

        char **words = NULL;
        int count = 0;
        char *word = strtok(line, " ");

        while (word != NULL) {
            words = realloc(words, (count + 1) * sizeof(char *));
            words[count] = (char *)malloc((strlen(word) + 1) * sizeof(char));
            strcpy(words[count], word);
            count++;
            word = strtok(NULL, " ");
        }

        inserirNaPilha(pilha, words, count, fp_out);

        for (int i = 0; i < count; i++) {
            free(words[i]);
        }
        free(words);

        limparPilha(pilha);
    }

    fclose(fp_in);
    fclose(fp_out);

    while (!vazia(pilha)) {
        free(pop(pilha));
    }
    free(pilha->nomes);
    free(pilha);

    return SUCESSO;
}
