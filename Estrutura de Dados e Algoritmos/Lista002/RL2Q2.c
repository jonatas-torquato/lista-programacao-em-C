#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ERROR -1

typedef struct Node{
    int value;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct Tree{
    Node *root;
} Tree;

Node *criarNode(int value){
    Node *new = malloc(sizeof(Node));
    new->value = value;
    new->left = NULL;
    new->right = NULL;
    return new;
}

Tree *criarEmptyTree(){
    Tree *newTree = malloc(sizeof(Tree));
    newTree->root = NULL;
    return newTree;
}

void inserir(Tree *tree, int value){
    Node *newNode = criarNode(value);
    if (tree->root == NULL){
        tree->root = newNode;
        return;
    }
    Node *temp = tree->root;
    Node *parent = NULL;
    while (temp != NULL){
        parent = temp;
        if (value < temp->value){
            temp = temp->left;
        } else if (value > temp->value){ // Evita duplicatas
            temp = temp->right;
        } else{
            free(newNode); // Descartar nó duplicado
            return;
        }
    }
    if(value < parent->value){
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }
}

int somaSubarvore(Node *node){
    if (node == NULL) return 0;
    return node->value + somaSubarvore(node->left) + somaSubarvore(node->right);
}

void emOrdem(Node *node, FILE *fp_out, int *first){
    if(node == NULL){
        return;
    }
    
    emOrdem(node->left, fp_out, first);
    
    int somaEsquerda = somaSubarvore(node->left);
    int somaDireita = somaSubarvore(node->right);
    int diferenca = somaDireita - somaEsquerda;
    
    if(*first){
        *first = 0;
    } else{
        fprintf(fp_out, " ");
    }
    fprintf(fp_out, "%d (%d)", node->value, diferenca);
    
    emOrdem(node->right, fp_out, first);
}

void freeNode(Node *node){
    if (node != NULL) {
        freeNode(node->left);
        freeNode(node->right);
        free(node);
    }
}

int main(){
    FILE *fp_in = fopen("L2Q2.in", "r");
    FILE *fp_out = fopen("L2Q2.out", "w");
    
    if(fp_in == NULL || fp_out == NULL){
        printf("Erro ao abrir arquivos.\n");
        return ERROR;
    }
    
    char line[1000];
    int countLinhas = 0;
    
    while(fgets(line, sizeof(line), fp_in)){
        Tree *arvore = criarEmptyTree();
        char *pointer = line;
        int num, off;
        
        if(countLinhas > 0){
            fprintf(fp_out, "\n");
        }
        
        while(sscanf(pointer, "%d%n", &num, &off) == 1){
            inserir(arvore, num);
            pointer += off;
        }
        
        int firstNumber = 1;
        emOrdem(arvore->root, fp_out, &firstNumber);
        
        freeNode(arvore->root);
        free(arvore);
        countLinhas++;
    }
    
    fclose(fp_in);
    fclose(fp_out);
    return 0;
}