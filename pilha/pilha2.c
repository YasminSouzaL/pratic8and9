/*pilha implementação dinamica */

#include <stdio.h>
#include <stdlib.h>

typedef struct sNo{
    int info;
    struct sNo *prox;
}No;

typedef struct sPilha{
    No *topo;
}Pilha;

void inic(Pilha *ptrP){
    ptrP -> topo = NULL;
}

void alocaNo(No **ptrNo){
    *ptrNo = (No *) malloc(sizeof(No));
}

void desalocaNo(No **ptrNo){
    free(*ptrNo);
}

int vazia(Pilha *ptrP){
    if(ptrP -> topo == NULL)
        return 1;
    else
        return 0;
}

void push(Pilha *ptrP, int elem){
    No *novo;
    alocaNo(&novo);
    if(novo != NULL){
        novo -> info = elem;
        novo -> prox = ptrP -> topo;
        ptrP -> topo = novo;
    }
    else
        printf("Pilha cheia!\n");
}

void pop(No **ptrNo){
    No *aux;
    if(*ptrNo == NULL)
        printf("Pilha vazia!\n");
    else{
        aux = *ptrNo;
        *ptrNo = (*ptrNo) -> prox;
        desalocaNo(&aux);
    }
}

int retornaTopo(Pilha *ptrP){
    if(vazia(ptrP)){
        printf("Pilha vazia!\n");
        return -1;
    }
    else
        return ptrP -> topo -> info;
}

void imprime(Pilha *ptrP){
    No *aux;
    if(vazia(ptrP))
        printf("Pilha vazia!\n");
    else{
        aux = ptrP -> topo;
        while(aux != NULL){
            printf("%d\n", aux -> info);
            aux = aux -> prox;
        }
    }
}

int main(){
    Pilha p;
    inic(&p);
    push(&p, 10);
    push(&p, 20);
    push(&p, 30);
    push(&p, 40);
    push(&p, 50);
    imprime(&p);
    printf("Topo: %d\n", retornaTopo(&p));
    pop(&p.topo);
    pop(&p.topo);
    pop(&p.topo);
    imprime(&p);
    printf("Topo: %d\n", retornaTopo(&p));
    return 0;
}
