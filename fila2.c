/*Fila implemetação dinamica com suap onde o inicio=0 com a proxima 
interação inicio = tamanho da fila */

#include <stdio.h>
#include <stdlib.h>

typedef struct sNo{
    int info;
    struct sNo *prox;
}No;

typedef struct sFila{
    No *inicio;
    No *fim;
    int tamanho;
}Fila;

void inic(Fila *ptrF){
    ptrF -> inicio = NULL;
    ptrF -> fim = NULL;
    ptrF -> tamanho = 0;
}

void alocaNo(No **ptrNo){
    *ptrNo = (No *) malloc(sizeof(No));
}

void desalocaNo(No **ptrNo){
    free(*ptrNo);
}

int vazia(Fila *ptrF){
    if(ptrF -> inicio == NULL)
        return 1;
    else
        return 0;
}

void enfileira(Fila *ptrF, int elem){
    No *novo;
    alocaNo(&novo);
    if(novo != NULL){
        novo -> info = elem;
        novo -> prox = NULL;
        if(vazia(ptrF))
            ptrF -> inicio = novo;
        else
            (ptrF -> fim) -> prox = novo;
        ptrF -> fim = novo;
        ptrF -> tamanho++;
    }
    else
        printf("Fila cheia!\n");
}

void desenfileira(Fila *ptrF){
    No *aux;
    if(vazia(ptrF))
        printf("Fila vazia!\n");
    else{
        aux = ptrF -> inicio;
        ptrF -> inicio = (ptrF -> inicio) -> prox;
        desalocaNo(&aux);
        ptrF -> tamanho--;
    }
}


int primeiro(Fila *ptrF){
    if(vazia(ptrF)){
        printf("Fila vazia!\n");
        return -1;
    }
    else
        return (ptrF -> inicio) -> info;
}


int ultimo(Fila *ptrF){
    if(vazia(ptrF)){
        printf("Fila vazia!\n");
        return -1;
    }
    else
        return (ptrF -> fim) -> info;
}


void ImprimeComRemocao(Fila *ptrF){
    int i;
    No *aux;
    if(vazia(ptrF))
        printf("Fila vazia!\n");
    else{
        aux = ptrF -> inicio;
        for(i = 0; i < ptrF -> tamanho; i++){
            printf("%d ", aux -> info);
            aux = aux -> prox;
        }
        printf("\n");
    }
}

void ImprimeSemRemocao(Fila *ptrF){
    int i;
    No *aux;
    if(vazia(ptrF))
        printf("Fila vazia!\n");
    else{
        aux = ptrF -> inicio;
        for(i = 0; i < ptrF -> tamanho; i++){
            printf("%d ", aux -> info);
            aux = aux -> prox;
        }
        printf("\n");
    }
}

int main(){
    Fila f;
    inic(&f);
    enfileira(&f, 1);
    enfileira(&f, 2);
    enfileira(&f, 3);
    enfileira(&f, 4);
    enfileira(&f, 5);
    ImprimeComRemocao(&f);
    desenfileira(&f);
    desenfileira(&f);
    ImprimeComRemocao(&f);
    enfileira(&f, 6);
    enfileira(&f, 7);
    ImprimeComRemocao(&f);
    return 0;
}