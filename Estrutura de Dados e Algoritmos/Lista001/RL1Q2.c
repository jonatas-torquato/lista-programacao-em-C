#define EXIT -2
#define CHEIA -3
#define VAZIA -4
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct stack{
    char **nomes; // pilha de nomes
    int top; // topo
    int capacidade; //
} Stack;

Stack* init_pilha(Stack *pilha, int size){
    pilha->nomes = (char**)malloc(size * sizeof(char*));
    pilha->top = -1;
    pilha->capacidade = size;
    return pilha;
}

bool vazia(Stack *pilha){
    if(pilha->top == -1){
        return true;
    } else{
        return false;
    }
}

bool cheia(Stack *pilha){
    if((pilha->top) == (pilha->capacidade - 1)){
        return true;
    } else{
        return false;
    }
}

void push(Stack *pilha, char *string){
    if(!cheia(pilha)){
        pilha->top = pilha->top++;
        pilha->nomes[pilha->top] = (char*)malloc((strlen(string) + 1) * sizeof(char));
        strcpy(pilha->nomes[pilha->top], string);
    } else{
        return CHEIA;
    }
}

void pop(Stack *pilha){
    if(!vazia(pilha)){
        pilha->top = pilha->top - 1; // Decrementa o topo
        return pilha->nomes[pilha->top + 1];
    } else{
        return VAZIA;
    }
}

