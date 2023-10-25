/*Crie um programa em C que apresente o menu de opções abaixo,
possibilitando ao usuário realizar as seguintes operações sobre uma pilha
linear dinâmica formada por elementos do tipo prato com os seguintes
dados: cor, tamanho e tipo (porcelana, plástico ou vidro):
i. Inserir um elemento no topo da pilha
ii. Remover um elemento do topo da pilha
iii. Retornar o elemento que está no topo da pilha sem removê-lo
iv. Exibir todos os elementos da pilha usando a representação
clássica*.
 Obs1: todas as funções devem usar a notação de ponteiro para ponteiro,
exceto a função para retornar o elemento que está no topo da pilha*/
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char cor[20];
    float tamanho;
    char tipo[20];
}Prato;

typedef struct no{
    Prato info;
    struct no *prox;
}No;

typedef struct{
    No *topo;
}Pilha;

void inicializar(Pilha *p){
    p->topo = NULL;
}

int vazia(Pilha *p){
    if(p->topo == NULL){
        return 1;
    }else{
        return 0;
    }
}

void inserir(Pilha *p, Prato prato){
    No *novo = (No*)malloc(sizeof(No));
    novo->info = prato;
    novo->prox = p->topo;
    p->topo = novo;
}

Prato remover(Pilha *p){
    Prato prato;
    No *aux;
    if(vazia(p)){
        printf("Pilha vazia!\n");
    }else{
        prato = p->topo->info;
        aux = p->topo;
        p->topo = p->topo->prox;
        free(aux);
    }
    return prato;
}

Prato retornar(Pilha *p){
    Prato prato;
    if(vazia(p)){
        printf("Pilha vazia!\n");
    }else{
        prato = p->topo->info;
    }
    return prato;
}

void exibir(Pilha *p){
    No *aux;
    if(vazia(p)){
        printf("Pilha vazia!\n");
    }else{
        aux = p->topo;
        while(aux != NULL){
            printf("Cor: %s\n", aux->info.cor);
            printf("Tamanho: %.2f\n", aux->info.tamanho);
            printf("Tipo: %s\n", aux->info.tipo);
            aux = aux->prox;
        }
    }
}

int main(){
    Pilha p;
    Prato prato;
    int op;
    inicializar(&p);
    do{
        printf("1 - Inserir\n");
        printf("2 - Remover\n");
        printf("3 - Retornar\n");
        printf("4 - Exibir\n");
        printf("5 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &op);
        switch(op){
            case 1:
                printf("Cor: ");
                scanf("%s", prato.cor);
                printf("Tamanho: ");
                scanf("%f", &prato.tamanho);
                printf("Tipo: ");
                scanf("%s", prato.tipo);
                inserir(&p, prato);
                break;
            case 2:
                prato = remover(&p);
                printf("Cor: %s\n", prato.cor);
                printf("Tamanho: %.2f\n", prato.tamanho);
                printf("Tipo: %s\n", prato.tipo);
                break;
            case 3:
                prato = retornar(&p);
                printf("Cor: %s\n", prato.cor);
                printf("Tamanho: %.2f\n", prato.tamanho);
                printf("Tipo: %s\n", prato.tipo);
                break;
            case 4:
                exibir(&p);
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    }while(op != 5);
    return 0;
}
