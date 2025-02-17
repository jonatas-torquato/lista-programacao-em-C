/*
    Implementação de uma Arvore de Busca Binária com as principais operações de acordo com
    o conceito apresentado por Thomas H. Cormen, em seu livro "Algortimos: Teoria e Prática".
*/

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

Node *criarNode();
Tree *criarEmptyTree();
Tree *criarTree();
void inserir();
void imprimirOrdenado();
int altura();
Node *localizar();
Node *minimumTree();
Node *maximumTree();
Node *sucessor();
Node *predecessor();
void delete();

int main(){
    
    Tree *arvore = criarEmptyTree();
    
    int valor;
    
    int opcao;
    
    do{
        printf("\n\t--------- MENU ---------\n\n");
        printf("\t0 - Sair");
        printf("\n\t1 - Inserir");
        printf("\n\t2 - Imprimir Arvore");
        printf("\n\t3 - Imprimir a Altura da Arvore");
        printf("\n\t4 - Localizar um Valor Especifico da Arvore");
        printf("\n\t5 - Excluir um Valor Especifico da Arvore");
        printf("\n\t6 - Imprimir o Minimo da Arvore");
        printf("\n\t7 - Imprimir o Maximo da Arvore");
        printf("\n\t8 - Imprimir o Sucessor de um No");
        printf("\n\t9 - Imprimir o Predecessor de um No");
        printf("\n\t10 - Imprimir a Raiz da Arvore");
        printf("\n");

        scanf("%d", &opcao);
        
        switch(opcao){
            case 1:{
                printf("\n\tDigite o Valor a ser inserido: ");
                scanf("%d", &valor);
                inserir(criarNode(valor), arvore);
                break;
            }
            case 2:{
                printf("\n\tImpressao da Arvore: \n");
                imprimirOrdenado(arvore->root);
                break;
            }
            case 3:{
                if(altura(arvore->root) == -1){
                    printf("\n\tArvore Vazia.");
                } else{
                    printf("\n\tAltura da Arvore: %d\n", altura(arvore->root));
                }
                break;
            }
            case 4:{
                printf("\n\tDigite o Valor que deseja localizar: ");
                scanf("%d", &valor);
                if(localizar(arvore, valor) != NULL){
                    printf("\n\tValor %d foi encontrado na Arvore.\n", localizar(arvore, valor)->value);
                } else{
                    printf("\n\tValor nao encontrado na Arvore.\n");
                }
                break;
            }
            case 5:{
                printf("\n\tDigite o Valor que deseja excluir: ");
                scanf("%d", &valor);
                if(localizar(arvore, valor) == NULL){
                    printf("\n\tValor nao encontrado na Arvore.\n");
                } else{
                    delete(arvore, localizar(arvore, valor));
                    printf("\n\tValor %d foi excluido da Arvore com Sucesso.\n", valor);
                }
                break;
            }
            case 6:{
                if(arvore != NULL){
                    printf("O Valor Minimum da Arvore: %d", minimumTree(arvore->root)->value);
                } else{
                    printf("\n\tArvore Vazia.\n");
                }
                break;
            }
            case 7:{
                if(arvore != NULL){
                    printf("O Valor Minimum da Arvore: %d", maximumTree(arvore->root)->value);
                } else{
                    printf("\n\tArvore Vazia.\n");
                }
                break;
            }
            case 8:{
                printf("\n\tDigite o Valor que deseja imprimir o Sucessor: ");
                scanf("%d", &valor);
                if(localizar(arvore, valor) != NULL){
                    if(sucessor(localizar(arvore, valor)) == NULL){
                        printf("\n\t%d nao possui Sucessor", valor);
                    } else{
                        printf("\n\tO Sucessor de %d = %d", valor, sucessor(localizar(arvore, valor))->value);
                    }
                } else{
                    printf("\n\tValor nao encontrado na Arvore.\n");
                }
                break;
            }
            case 9:{
                printf("\n\tDigite o Valor que deseja imprimir o Predecessor: ");
                scanf("%d", &valor);
                if(localizar(arvore, valor) != NULL){
                    if(predecessor(localizar(arvore, valor)) == NULL){
                        printf("\n\t%d nao possui Sucessor", valor);
                    } else{
                        printf("\n\tO Sucessor de %d = %d", valor, predecessor(localizar(arvore, valor))->value);
                    }
                } else{
                    printf("\n\tValor nao encontrado na Arvore.\n");
                }
                break;
            }
            case 10:{
                if(arvore->root == NULL){
                    printf("\n\tArvore Vazia.");
                } else{
                    printf("\n\tRaiz da Arvore: %d", arvore->root->value);
                }
                break;
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
    Node *temp = node;
    if(temp != NULL){
        imprimirOrdenado(temp->left);
        printf("\t%d ", temp->value);
        imprimirOrdenado(temp->right);
    }
}

int altura(Node *node){
    if(node == NULL){
        return -1;
    }
    int leftAltura = altura(node->left);
    int rightAltura = altura(node->right);

    if(leftAltura > rightAltura){
        return leftAltura + 1;
    } else{
        return rightAltura + 1;
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

Node *minimumTree(Node *node){
    Node *temp = node;
    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp;
}

Node *maximumTree(Node *node){
    Node *temp = node;
    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp;
}

Node *sucessor(Node *node){
    if(node->right != NULL){
        return minimumTree(node->right);
    }
    Node * temp = node->parent;
    while((temp != NULL) && (node == temp->right)){
        node = temp;
        temp = temp->parent;
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

void delete(Tree *tree, Node *remove){
    Node *y; // Node auxiliar
    Node *x; // Node auxiliar

    // Se a esquerda OU a direita do valor a ser Removido for NULL
    if((remove->left == NULL) || (remove->right == NULL)){
        // Node y recebe Remove
        y = remove;
    } else{
        // Node y recebe o sucessor de Remove
        y = sucessor(remove);
    }

    // Se a Esquerda de Node y for diferente NULL
    if(y->left != NULL){
        // Node x recebe a esquerda de Node y, senão, recebe a direita de Node y
        x = y->left;
    } else{
        x = y->right;
    }

    if(x != NULL){
        // O pai de x recebe o pai de y
        x->parent = y->parent;
        if(y->parent == NULL){
            /*  
                Se o pai de y for NULL, signigica o Remove é a raiz,
                logo o seu filho (x) à esquerda ou a direita vai se tornar a raiz.
            */    
            tree->root = x;
        } else{
            /*  Se o y não for a Raiz, verifica se a esquerda do seu pai é igual a y
            */
            if(y->parent->left == y){
                y->parent->left = x;
            } else{
                y->parent->right = x;
            }
        }
    }

    if(y != remove){
        remove->value = y->value;
    }

}

// Versão do Thomas Cormen usando Transplant e Delete //

/*

void transplant(Tree *tree, Node *removido, Node *substituto){
    if(removido->parent == NULL){
        // Caso Node seja a raiz
        tree->root = substituto;
    } else if(removido == removido->parent->left){
        // Caso seja o Filho da Esquerda
        removido->parent->left = substituto;
    } else if(removido == removido->parent->right){
        // Caso seja o Filho da Direita
        removido->parent->right = substituto;
    }

    if(substituto != NULL){
        substituto->parent = removido->parent;
    }
}

void delete(Tree *tree, int value){
    Node *remove = localizar(tree, value);
    Node *actual = tree->root;
    if(remove != NULL){
        if(remove->left == NULL){
        // Sem Filho na Esquerda
            transplant(tree, remove, remove->right);
        } else if(remove->right == NULL){
        // Sem Filho na Direita
            transplant(tree, remove, remove->left);
        } else{
            // Filhos da direita e esquerda
            actual = minimumTree(remove->right);
            if(actual->parent != remove){
                transplant(tree, actual, actual->right);
                actual->right = remove->right;
                actual->right->parent = actual;
            }
            transplant(tree, remove, actual);
            actual->left = remove->left;
            actual->left->parent = actual;
        }
        free(remove);
    }
}

*/
