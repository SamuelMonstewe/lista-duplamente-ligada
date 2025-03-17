#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct List *novoNode(struct List* current, int value);
void liberarMemoria(struct List* HEAD);
void imprimirElementos(struct List* HEAD);
void imprimirNaOrdemInversa(struct List* ultimoNode);
void desligarElemento(struct List* HEAD, int key);

struct List{
    int value;
    struct List* proximo;
    struct List* anterior;
};

int main(int argc, char *argv[]){

    
    int value = 0;
    struct List *HEAD = NULL;
    struct List *current = (struct List*) malloc(sizeof(struct List));
    current->value = value;
    HEAD = current;

    while(1){
        printf("Digite um número (0 para sair):");
        scanf("%d", &value);

        if(!(value)) break;
        current->proximo = novoNode(current, value);
        current = current->proximo;
    }
    struct List* ultimoNode = current;
    
    imprimirElementos(HEAD);
    imprimirNaOrdemInversa(ultimoNode);
    desligarElemento(HEAD, 3);
    liberarMemoria(HEAD);
    return 0;
}

struct List *novoNode(struct List* current, int value){
    current->proximo = (struct List*) malloc(sizeof(struct List));
    struct List* novoNode = current->proximo;
    novoNode->proximo = NULL;
    novoNode->anterior = current;
    novoNode->value = value;

    return novoNode;
}

void liberarMemoria(struct List* HEAD){
    struct List* proximo;
    struct List* current;

    if(HEAD->proximo == NULL) printf("A lista já está vazia!\n");
    else{
        current = HEAD->proximo;
        free(HEAD);
        while(current->proximo != NULL){
            proximo = current->proximo;
            free(current);
            current = proximo;
        }
        free(current);
    }

}

void imprimirElementos(struct List* HEAD){
    if(HEAD->proximo == NULL){
        printf("Lista vazia!");
        return;  
    } 

    struct List* current = HEAD->proximo;
    
    while(current != NULL){
        printf("| %d | ", current->value);
        current = current->proximo;
    }
    printf("\n");
}

void imprimirNaOrdemInversa(struct List* ultimoNode){
    struct List* current = ultimoNode;

    while(current->anterior != NULL){
        printf("| %d | ", current->value);
        current = current->anterior;
    }
    printf("\n");
}

void desligarElemento(struct List* HEAD, int key){
    if(HEAD->proximo == NULL){
        printf("Lista vazia!");
        return;  
    } 

    struct List* current = HEAD->proximo;
    
    while(current->proximo != NULL){
        if(current->value == key){
            struct List* elementoParaRemover = current;
            elementoParaRemover->proximo->anterior = elementoParaRemover->anterior;
            elementoParaRemover->anterior->proximo = elementoParaRemover->proximo;
            free(elementoParaRemover);
            printf("Elemento removido!");
            imprimirElementos(HEAD);
            return;     
        }
        else current = current->proximo;
        
    }
    printf("Esse elemento não existe na lista!\n");

    
}



