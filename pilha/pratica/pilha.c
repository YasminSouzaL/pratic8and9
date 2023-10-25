#include <stdio.h>
#include <stdlib.h>
#define TAMP 10

typedef struct sPilha{
    int topo;
    int dados[TAMP];
}Pilha;

void inicializa(Pilha *p){
    p->topo = -1;
}

int vazia(Pilha *p){
    if(p->topo == -1)
        return 1;
    else
        return 0;
}

int cheia(Pilha *p){
    if(p->topo == TAMP-1)
        return 1;
    else
        return 0;
}
// Função para empilhar
void push(Pilha *p, int x){
    if(cheia(p)){
        printf("Pilha cheia!\n");
        exit(1);
    }
    p->topo++;
    p->dados[p->topo] = x;
}
// Função para desempilhar
int pop(Pilha *p){
    int aux;
    if(vazia(p)){
        printf("Pilha vazia!\n");
        exit(1);
    }
    aux = p->dados[p->topo];
    p->topo--;
    return aux;
}

int main(){
    Pilha p;
    inicializa(&p);
    push(&p, 10);
    push(&p, 20);
    push(&p, 30);
    printf("%d\n", pop(&p));
    printf("%d\n", pop(&p));
    printf("%d\n", pop(&p));
    return 0;
}