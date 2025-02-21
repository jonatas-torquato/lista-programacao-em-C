#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ERROR -1

typedef struct Node{
    int value;
    struct Node *left;
    struct Node *right;
    struct Node *parent;
} Node;

typedef struct Tree{
    Node *root;
} Tree;

Node * criarNode(int value){
    Node * new = malloc(sizeof(Node));
    new->value = value;
    new->left = NULL;
    new->right = NULL;
    new->parent = NULL;
    return new;
}

Tree *criarEmptyTree(){
    Tree *newTree = malloc(sizeof(Tree));
    newTree->root = NULL;
    return newTree;
}

Tree * criarTree(Node *root){
    Tree *newTree = malloc(sizeof(Tree));
    newTree->root = NULL;
    return newTree;
}

void inserir(Node * node, Tree *tree){
    // Se a Raiz estiver vazia
    if(tree->root == NULL){
        tree->root = node;
    } else{
        Node *temp = tree->root;
        Node * parent;
        while(temp != NULL){
            parent = temp;
            if(node->value < temp->value){
                temp = temp->left;
            } else if (node->value >= temp->value){
                temp = temp->right;
            }
        }
        if(node->value < parent->value){
            parent->left = node;
        } else{
            parent->right = node;
        }
        node->parent = parent;
    }
}

int altura(Node *node){
    int height = 0;
    while(node->parent != NULL){
        node = node->parent;
        height++;
    }
    return height;
}

Node *maximumTree(Node *node){
    Node *temp = node;
    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp;
}

Node *predecessor(Node *node){
    if(node->left != NULL){
        return maximumTree(node->left);
    }
    Node * temp = node->parent;
    while((temp != NULL) && (node == temp->left)){
        node = temp;
        temp = temp->parent;
    }
    return temp;
}

void freeNode(Node *node){
    if(node != NULL){
        freeNode(node->left);
        freeNode(node->right);
        free(node);
    }
}

Node *localizar(Tree *tree, int value){
    Node * leaf = tree->root;
    while((leaf != NULL) && (leaf->value != value)){
        if(value < leaf->value){
            leaf = leaf->left;
        } else{
            leaf = leaf->right;
        }
    }
    return leaf;
}

int main(){    
    FILE *fp_in = fopen("L2Q1.in", "r");
    FILE *fp_out = fopen("L2Q1.out", "w");

    if(fp_in == NULL || fp_out == NULL){
        printf("\nErro ao abrir arquivos.\n");
        return ERROR;
    }

    char line[1000];

    int countLinhas = 0;
    
    while(fgets(line, sizeof(line), fp_in)){
        Tree *arvore = criarEmptyTree();
        
        if(countLinhas > 0){
            fprintf(fp_out, "\n");
        }

        char *pointer = line;
        int num, firstNumber = 1;

        while (sscanf(pointer, "%d", &num) == 1) {
            Node *aux = criarNode(num);
            inserir(aux, arvore);

            if (!firstNumber){
                fprintf(fp_out, " ");
            }

            fprintf(fp_out, "%d", altura(aux));
            firstNumber = 0;

            // Avança o ponteiro para o próximo número na linha
            while (*pointer != ' ' && *pointer != '\0') {
                pointer++;
            }
            while (*pointer == ' ') {
                pointer++;
            }
        }

        Node *max = maximumTree(arvore->root);
        Node *pred = predecessor(max);

        fprintf(fp_out, " max %d alt %d", max->value, altura(max));
        
        if(pred == NULL){
            fprintf(fp_out, " pred NaN");
        } else{
            fprintf(fp_out, " pred %d", pred->value);
        }

        countLinhas++;
        freeNode(arvore->root);
        free(arvore);
    }
    fclose(fp_in);
    fclose(fp_out);
    return 0;
}