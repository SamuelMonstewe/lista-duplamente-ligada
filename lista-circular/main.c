#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node *proximo;
    struct Node *anterior;
    int value;
};

struct Cabeca {
    struct Node *ultimoNode;
    struct Node *sentinela;
};

struct Node* novoNode(struct Node *current, struct Cabeca *cabeca, int value);
struct Cabeca* inicializarCabeca(struct Cabeca *cabeca, struct Node *sentinela);
void imprimirElementos(struct Cabeca *cabeca);
void liberarMemoria(struct Cabeca *cabeca);
void procurarElemento(struct Cabeca *cabeca, int key);

int main(int argc, char argv[]){
    struct Node *current = (struct Node*) malloc(sizeof(struct Node));
    struct Cabeca *cabeca = inicializarCabeca(cabeca, current);
    int value = 0;
    inicializarCabeca(cabeca, current);
    
    while(1){
        printf("Digite um número (0 para sair):");
        scanf("%d", &value);
        if(value == 0) break;
        current->proximo = novoNode(current, cabeca, value);
        current = current->proximo;
    }
   
    imprimirElementos(cabeca);
    procurarElemento(cabeca, 10);
    liberarMemoria(cabeca);
}

struct Node* novoNode(struct Node *current, struct Cabeca *cabeca, int value){
    struct Node *node = (struct Node*) malloc(sizeof(struct Node));
    cabeca->ultimoNode = node;
    node->value = value;
    node->anterior = current;
    node->proximo = cabeca->sentinela;
    current = node;

    return current;
}

struct Cabeca* inicializarCabeca(struct Cabeca *cabeca, struct Node *sentinela){
    cabeca = (struct Cabeca*) malloc(sizeof(cabeca));
    cabeca->sentinela = sentinela;
    return cabeca;
}

void imprimirElementos(struct Cabeca *cabeca){
    if(cabeca->sentinela == NULL){
        printf("A lista já está vazia!");
        return;
    }

    struct Node* current = cabeca->sentinela->proximo;

    while(1){
        printf("| %d |", current->value);
        current = current->proximo;
        if(current->proximo == cabeca->sentinela){
            printf("| %d |", current->value);
            break;
        }
    }
}

void liberarMemoria(struct Cabeca *cabeca){
    if(cabeca == NULL) return;

    struct Node *sentinela = cabeca->sentinela;
    struct Node *temp = sentinela->proximo;
    struct Node *current;

    free(cabeca->sentinela);
    free(cabeca);
   
    while(temp->proximo != NULL){
        current = temp->proximo;
        free(temp);
        temp = current;
    }
    
}
void procurarElemento(struct Cabeca *cabeca, int key){
    struct Node *current = cabeca->sentinela;

    while(current->proximo != cabeca->sentinela){
        if(current->value == key) {
            printf("Elemento encontrado!\n");
            return;
        }
        current = current->proximo;
    }
        

    printf("\nEsse chave não está contida na lista!\n");
    
}
