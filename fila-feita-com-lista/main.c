#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node *proximo;
    int value;
};
struct Fila {
    struct Node *fim;
    struct Node *inicio;
};

struct Fila* inicializarFila();
void enqueue(struct Fila *fila, int value);
void dequeue(struct Fila *fila);
void printFila(struct Fila *fila);
void liberarMemoria(struct Fila *fila);

int main(int argv, char argc[]){
    struct Fila *fila; 
    fila = inicializarFila();

    enqueue(fila, 1); 
    enqueue(fila, 2);
    enqueue(fila, 3);
    enqueue(fila, 4);
    printFila(fila);
    dequeue(fila);
    printFila(fila);
    liberarMemoria(fila);
}

struct Fila* inicializarFila(){
    struct Fila *fila = (struct Fila*) malloc(sizeof(struct Fila));
    fila->fim = NULL;
    fila->inicio = NULL;
    
    return fila;
}

void enqueue(struct Fila *fila, int value){
    struct Node *node = (struct Node*) malloc(sizeof(struct Node));
    node->value = value;
    node->proximo = NULL;

    if (fila->fim == NULL) fila->inicio = node; 
    else fila->fim->proximo = node; 
    
    fila->fim = node;

}

void dequeue(struct Fila *fila){
    struct Node *elementoParaSair = fila->inicio;
    fila->inicio = elementoParaSair->proximo;
    free(elementoParaSair);
}

void printFila(struct Fila *fila){
    struct Node *current = fila->inicio;

    while(current != NULL){
        printf("| %d | ", current->value);
        current = current->proximo;
    }
    printf("\n");
}
void liberarMemoria(struct Fila *fila){
    struct Node *current = fila->inicio;
    struct Node *temp;

    while(current != NULL){
        temp = current->proximo;
        free(current);
        current = temp;
    }
}
