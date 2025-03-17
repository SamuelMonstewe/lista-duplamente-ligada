#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Node {
    int value;
    struct Node* proximo;
};

struct Pilha {
    struct Node *top;
};

struct Pilha* inicializarStack(){
    struct Pilha *stack = (struct Pilha*) malloc(sizeof(struct Pilha));
    stack->top = NULL;

    return stack;
}

void push(struct Pilha *stack, int value){
    struct Node *node = (struct Node*) malloc(sizeof(struct Node)); 
    struct Node *antigoTop = stack->top;

    node->proximo = antigoTop; 
    node->value = value; 
    stack->top = node; 
}

void pop(struct Pilha *stack){
    struct Node* nodeParaRemover = stack->top;
    stack->top = nodeParaRemover->proximo;
    free(nodeParaRemover);     
}

void printStack(struct Pilha *stack) {
    struct Node *atual = stack->top;
    printf("Pilha: ");
    while (atual != NULL) {
        printf("%d ", atual->value);
        atual = atual->proximo;
    }
    printf("\n");
}

int main(int argc, char *argv[]){
    struct Pilha *stack = inicializarStack();

    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    push(stack, 4);
    printStack(stack);
    pop(stack);
    printStack(stack);
    
    return 0;
}

