/*Crie um programa em C que apresente o menu de opções abaixo,
possibilitando ao usuário realizar as seguintes operações sobre uma pilha
linear estática formada por 26 letras do alfabeto:
i. Inserir um elemento no topo da pilha
ii. Remover um elemento do topo da pilha
iii. Retornar o elemento que está no topo da pilha sem removê-lo
iv. Exibir todos os elementos da pilha usando a representação
clássica**/
#include <stdio.h>
#include <stdlib.h>

#define TAM 26

typedef struct{
    char letras[TAM];
    int topo;
}Pilha;

void inicializar(Pilha *p){
    p->topo = -1;
}

int cheia(Pilha *p){
    if(p->topo == TAM-1){
        return 1;
    }else{
        return 0;
    }
}

int vazia(Pilha *p){
    if(p->topo == -1){
        return 1;
    }else{
        return 0;
    }
}

void inserir(Pilha *p, char letra){
    if(cheia(p)){
        printf("Pilha cheia!\n");
    }else{
        p->topo++;
        p->letras[p->topo] = letra;
    }
}

char remover(Pilha *p){
    char letra;
    if(vazia(p)){
        printf("Pilha vazia!\n");
    }else{
        letra = p->letras[p->topo];
        p->topo--;
    }
    return letra;
}

char retornar(Pilha *p){
    char letra;
    if(vazia(p)){
        printf("Pilha vazia!\n");
    }else{
        letra = p->letras[p->topo];
    }
    return letra;
}

void exibir(Pilha *p){
    int i;
    if(vazia(p)){
        printf("Pilha vazia!\n");
    }else{
        for(i=p->topo; i>=0; i--){
            printf("%c\n", p->letras[i]);
        }
    }
}

int main(){
    Pilha p;
    char letra;
    int opcao;
    inicializar(&p);
    do{
        printf("1 - Inserir\n");
        printf("2 - Remover\n");
        printf("3 - Retornar\n");
        printf("4 - Exibir\n");
        printf("5 - Sair\n");
        printf("Digite a opcao: ");
        scanf("%d", &opcao);
        switch(opcao){
            case 1:
                printf("Digite a letra: ");
                scanf(" %c", &letra);
                inserir(&p, letra);
                break;
            case 2:
                letra = remover(&p);
                printf("Letra removida: %c\n", letra);
                break;
            case 3:
                letra = retornar(&p);
                printf("Letra retornada: %c\n", letra);
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
    }while(opcao != 5);
    return 0;
}






