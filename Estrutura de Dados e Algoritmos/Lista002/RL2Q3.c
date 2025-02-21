#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura do nó da árvore
typedef struct Node {
    int value;
    int height;
    struct Node *left;
    struct Node *right;
} Node;

// Função auxiliar para criar um novo nó
Node* criarNode(int value) {
    Node *novo = (Node*)malloc(sizeof(Node));
    novo->value = value;
    novo->height = 0;  // Altura inicial como 0
    novo->left = novo->right = NULL;
    return novo;
}

// Função para inserir um nó na árvore
void inserirNode(Node **root, int value) {
    if (*root == NULL) {
        *root = criarNode(value);  // Cria um novo nó se a árvore está vazia
        return;
    }

    Node *temp = *root;

    // Percorre recursivamente até encontrar a posição correta
    if (value < temp->value) {
        inserirNode(&(temp->left), value);  // Insere na subárvore esquerda
    } else if (value > temp->value) {
        inserirNode(&(temp->right), value);  // Insere na subárvore direita
    }

    // Se o valor já existe, não fazemos nada (BST normalmente não permite duplicados)

    // Atualiza a altura do nó
    int alturaEsquerda = (temp->left) ? temp->left->height : -1;
    int alturaDireita = (temp->right) ? temp->right->height : -1;
    temp->height = 1 + (alturaEsquerda > alturaDireita ? alturaEsquerda : alturaDireita);
}


// Função para encontrar o menor nó em uma árvore (usada para encontrar o sucessor)
Node* minimum(Node *root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Função para remover um nó da árvore
Node* removeNode(Node *root, int value) {
    if (root == NULL) {
        return NULL;  // Valor não encontrado, nada a fazer
    }

    // Percorre a árvore para encontrar o nó a ser removido
    if (value < root->value) {
        root->left = removeNode(root->left, value);
    } else if (value > root->value) {
        root->right = removeNode(root->right, value);
    } else {
        // Caso 1: Nó folha
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }

        // Caso 2: Nó com apenas um filho
        if (root->left == NULL) {
            Node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node *temp = root->left;
            free(root);
            return temp;
        }

        // Caso 3: Nó com dois filhos
        Node *temp = minimum(root->right);  // Sucessor em ordem
        root->value = temp->value;  // Substitui o valor do nó pelo sucessor
        root->right = removeNode(root->right, temp->value);  // Remove o sucessor
    }

    // Atualiza a altura do nó
    int alturaEsquerda = (root->left) ? root->left->height : -1;
    int alturaDireita = (root->right) ? root->right->height : -1;
    root->height = 1 + (alturaEsquerda > alturaDireita ? alturaEsquerda : alturaDireita);

    return root;
} 

int main(){
    FILE *arquivoEntrada = fopen("L2Q3.in", "r");
    FILE *arquivoSaida = fopen("L2Q3.out", "w");
    char linha[1000];
    char espaco[] = " ";
    int contadorLinhas = 0;
  
    if(arquivoEntrada == NULL || arquivoSaida == NULL){
      printf("Arquivos nao podem ser abertos.");
      return EXIT_FAILURE;
    }
  
    while(fgets(linha, sizeof(linha), arquivoEntrada) != NULL){
      Node *raiz = NULL;
      char texto[1000];
      int elemento = 0;
  
      linha[strcspn(linha, "\n")] = '\0'; // Remove o \n da linha lida
      linha[strcspn(linha, "\r")] = '\0'; // Remove o \r da linha lida
  
      char *parte = strtok(linha, espaco);
  
      if(contadorLinhas != 0){
        sprintf(texto, "\n");
      }else{
        sprintf(texto, "");
      }
  
      while(parte != NULL){
        if(parte[0] == 'a'){
          parte = strtok(NULL, espaco);
          int valor = atoi(parte);
          inserirNode(&raiz, valor);
        }else if(parte[0] == 'r'){
          parte = strtok(NULL, espaco);
          int valor = atoi(parte);
          raiz = removeNode(raiz, valor);
        }
        parte = strtok(NULL, espaco);
      }
      
      if(raiz){
        Node *pilha[100];
        int topo = -1;
        Node *atual = raiz;
        int primeiro = 1;
        while (topo >= 0 || atual){
          while (atual){
            pilha[++topo] = atual;
            atual = atual->left;
          }
          atual = pilha[topo--];
          if (primeiro){
            sprintf(texto, "%s %d (%d)", texto, atual->value, atual->height);
            primeiro = 0;
          }else{
            sprintf(texto, "%s %d (%d)", texto, atual->value, atual->height);
          }
          atual = atual->right;
        }
      }
      
      fputs(texto, arquivoSaida);
      contadorLinhas++;
    }
  
    fclose(arquivoEntrada);
    fclose(arquivoSaida);
    return 0;
}
  
  



/*
Node * criarNode(int value){
    Node * new = malloc(sizeof(Node));
    new->value = value;
    new->left = NULL;
    new->right = NULL;
    new->parent = NULL;
    return new;
}

int inserir(Tree *tree, int value){
    Node *new = criarNode(value);
    int altura = 0;
    new->height = altura;
    if(tree == NULL){
        tree = new;
    } else{
        Node *temp = tree;
        Node *parent = NULL;
        while(1){
            parent = temp;
            if(value < temp->value){
                temp = temp->left;
                altura++;
                if(temp == NULL){
                    parent->left = new;
                    new->parent = parent;
                    new->height = altura;
                    return new->height;
                }
            } else{
                temp = temp->right;
                altura++;
                if(temp == NULL){
                    parent->right = new;
                    new->parent = parent;
                    new->height = altura;
                    return new->height;
                }
            }
        }
    }
    return 0;
}

*/