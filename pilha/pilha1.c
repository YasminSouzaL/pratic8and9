/*Pilha implementação estática (array)*/
#include <stdio.h>
#define TAMP 10

typedef struct sPilha{
    int itens[TAMP];
    int topo;
}Pilha;

void inic(Pilha *ptrP){
    ptrP -> topo = -1;
}

int vazia(Pilha *ptrP){
    if(ptrP -> topo == -1)
        return 1;
    else
        return 0;
}

int cheia(Pilha *ptrP){
    if(ptrP -> topo == TAMP - 1)
        return 1;
    else
        return 0;
}

void push(Pilha *ptrP, int elem){
    if(cheia(ptrP))
        printf("Pilha cheia!\n");
    else{
        ptrP -> topo++;
        ptrP -> itens[ptrP -> topo] = elem;
    }
}

int pop(Pilha *ptrP){
    int aux;
    if(vazia(ptrP)){
        printf("Pilha vazia!\n");
        return -1;
    }
    else{
        aux = ptrP -> itens[ptrP -> topo];
        ptrP -> topo--;
        return aux;
    }
}

int retornaTopo(Pilha *ptrP){
    if(vazia(ptrP)){
        printf("Pilha vazia!\n");
        return -1;
    }
    else
        return ptrP -> itens[ptrP -> topo];
}

void imprime(Pilha *ptrP){
    int i;
    if(vazia(ptrP))
        printf("Pilha vazia!\n");
    else{
        for(i = ptrP -> topo; i >= 0; i--)
            printf("%d\n", ptrP -> itens[i]);
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
    push(&p, 60);
    push(&p, 70);
    push(&p, 80);
    push(&p, 90);
    push(&p, 100);
    push(&p, 110);
    imprime(&p);
    printf("Topo: %d\n", retornaTopo(&p));
    printf("Pop: %d\n", pop(&p));
    printf("Pop: %d\n", pop(&p));
    printf("Pop: %d\n", pop(&p));
    printf("Pop: %d\n", pop(&p));
    printf("Pop: %d\n", pop(&p));
    printf("Pop: %d\n", pop(&p));
    printf("Pop: %d\n", pop(&p));
    printf("Pop: %d\n", pop(&p));
    printf("Pop: %d\n", pop(&p));
    printf("Pop: %d\n", pop(&p));
    imprime(&p);
    return 0;
}
