#include <stdio.h>
#include <stdlib.h>

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
            } else{
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

void imprimirOrdenado(Node *node){
    if(node != NULL){
        imprimirOrdenado(node->left);
        printf("\t%d ", node->value);
        imprimirOrdenado(node->right);
    }
}

Node * localizar(Tree *tree, int value){
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

Node *minimumTree(Node *node){
    Node *temp = node;
    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp;
}

Node *sucessor(Node *node){
    if(node->right != NULL){
        return sucessor(node->right);
    }
    Node * temp = node;
    while((temp != NULL) && (temp->right != node)){
        node = temp;
        temp = temp->parent;
    }
    return temp;
}
// Revisar as funções Transplant e Delete
Node *transplant(Tree *tree, Node *remove, Node * substituto){
    if(remove->parent == NULL){
        tree->root = substituto;
    } else if(remove == remove->parent->left){
        remove->parent->left = substituto;
    } else if(remove == remove->parent->right){
        remove->parent->right = substituto;
    }

    if(substituto != NULL){
        substituto->parent = remove->parent;
    }
}

Node *delete(Tree *tree, int value){
    Node *temp = localizar(tree, value);
    Node *new = tree;
    if(localizar(tree, value) != NULL){
        if(temp->left == NULL){
            transplant(tree, temp, temp->right);
        } else if(temp->right == NULL){
            transplant(tree, temp, temp->left);
        } else{
            new = minimumTree(temp->right);
            if(new->parent != temp){
                transplant(tree, new, new->right);
                new->right = temp->right;
                new->right->parent = new;
            }
            transplant(tree, temp, new);
            new->left = temp->left;
            new->left->parent = new;
        }
        return temp;
    }
}

int main(){
    
    Tree *arvore = criarEmptyTree();
    
    int valor;
    
    int opcao;
    
    do{
        printf("\n\t--------- MENU ---------\n\n");
        printf("\t0 - Sair");
        printf("\n\t1 - Inserir");
        printf("\n\t2 - Imprimir Arvore");
        printf("\n\t3 - Imprimir o Minimo da Arvore");
        printf("\n\t4 - Imprimir o Sucessor de um No");
        printf("\n\t5 - Localizar um Valor Especifico da Arvore");
        printf("\n\t6 - Excluir um Valor Especifico da Arvore\n");

        scanf("%d", &opcao);
        
        switch(opcao){
            case 1:{
                printf("\n\tDigite o Valor a ser inserido: ");
                scanf("%d", &valor);
                Inserir(criarNode(valor), arvore);
                break;
            }
            case 2:{
                printf("\n\tImpressao da Arvore: \n");
                imprimirOrdenado(arvore);
                break;
            }
            case 3:{
                if(minimumTree(arvore) != NULL){
                    printf("\n\tMinimum (Menor Valor da Arvore): %d", minimumTree(arvore));
                } else{
                    printf("\n\tArvore Vazia.\n");
                }
            }
            case 4:{
                printf("\n\tDigite o Valor que deseja imprimir o Sucessor: ");
                scanf("%d", &valor);
                if(localizar(arvore, valor) != NULL){
                    if(sucessor(localizar(arvore, valor) == NULL)){
                        printf("\n\t%d nao possui Sucessor", valor);
                    } else{
                        printf("\n\tO Sucessor de %d = %d", valor, sucessor(localizar(arvore, valor)));
                    }
                } else{
                    printf("\n\tValor nao encontrado na Arvore.\n");
                }
            }
            case 5:{
                printf("\n\tDigite o Valor que deseja localizar: ");
                scanf("%d", &valor);
                if(localizar(arvore, valor) != NULL){
                    printf("\n\tValor %d encontrado na Arvore.\n", localizar(arvore, valor));
                } else{
                    printf("\n\tValor nao encontrado na Arvore.\n");
                }
            }
            case 6:{
                printf("\n\tDigite o Valor que deseja excluir: ");
                scanf("%d", &valor);
                if(localizar(arvore, valor) == NULL){
                    printf("\n\tValor nao encontrado na Arvore.\n");
                } else{
                    delete(arvore, valor);
                    printf("\n\tValor %d foi excluido da Arvore com Sucesso.\n", valor);
                }
            }
            default:{
                if(opcao != 0){
                    printf("\nOpcao Invalida.\n");
                }
            }
        }
    } while(opcao != 0);

    return 1;
}