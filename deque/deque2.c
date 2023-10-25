#include <stdio.h>
#include <stdlib.h>

typedef struct sNo {
    int info;
    struct sNo *esq;
    struct sNo *dir;
} No;

typedef struct sDeque {
    No *inicio;
    No *fim;
} Deque;

void inic(Deque *ptrD) {
    ptrD->inicio = NULL;
    ptrD->fim = NULL;
}

int vazia(Deque *ptrD) {
    return (ptrD->inicio == NULL) ? 1 : 0;
}

void alocaNo(No **ptrNo) {
    *ptrNo = (No *)malloc(sizeof(No));
}

void desalocaNo(No **ptrNo) {
    free(*ptrNo);
}

void insereFim(Deque *ptrD, int elem) {
    No *novo;
    alocaNo(&novo);
    if (novo != NULL) {
        novo->info = elem;
        novo->dir = NULL;
        if (vazia(ptrD) == 1) {
            ptrD->inicio = novo;
            ptrD->fim = novo;
        } else {
            (ptrD->fim)->dir = novo;
            novo->esq = ptrD->fim;
            ptrD->fim = novo;
        }
    } else {
        printf("Erro na alocação do novo nó");
    }
}

void inserirInicio(Deque *ptrD, int elem) {
    No *novo;
    alocaNo(&novo);
    if (novo != NULL) {
        novo->info = elem;
        novo->esq = NULL;
        if (vazia(ptrD) == 1) {
            ptrD->inicio = novo;
            ptrD->fim = novo;
        } else {
            (ptrD->inicio)->esq = novo;
            novo->dir = ptrD->inicio;
            ptrD->inicio = novo;
        }
    } else {
        printf("Erro na alocação do novo nó");
    }
}

int removerInicio(Deque *ptrD) {
    No *aux;
    int x;
    if (vazia(ptrD) == 1) {
        printf("Deque Vazia!");
        return -1; // Return a sentinel value or handle the error as per your requirements
    } else {
        aux = (ptrD->inicio)->dir;
        x = (ptrD->inicio)->info;
        desalocaNo(&ptrD->inicio);
        ptrD->inicio = aux;
        if (ptrD->inicio != NULL)
            (ptrD->inicio)->esq = NULL;
        else
            ptrD->fim = NULL;
    }
    return x;
}

int removerFim(Deque *ptrD) {
    No *aux;
    int x;
    if (vazia(ptrD) == 1) {
        printf("Deque Vazia!");
        return -1; // Return a sentinel value or handle the error as per your requirements
    } else {
        aux = (ptrD->fim)->esq;
        x = (ptrD->fim)->info;
        desalocaNo(&ptrD->fim);
        ptrD->fim = aux;
        if (ptrD->fim != NULL)
            (ptrD->fim)->dir = NULL;
        else
            ptrD->inicio = NULL;
    }
    return x;
}

void imprimeComRemocaodeElem(Deque *ptrD) {
    while (!vazia(ptrD)) {
        printf("%d ", removerInicio(ptrD));
    }
    printf("\n");
}

void imprimesemRemocaodeElem(Deque *ptrD) {
    No *ptr = ptrD->inicio;
    while (ptr != NULL) {
        printf("%d ", ptr->info);
        ptr = ptr->dir;
    }
    printf("\n");
}

int main() {
    Deque deque;
    inic(&deque);
    
    insereFim(&deque, 1);
    insereFim(&deque, 2);
    insereFim(&deque, 3);
    inserirInicio(&deque, 0);
    
    printf("Deque com remoção de elementos: ");
    imprimeComRemocaodeElem(&deque);
    
    printf("Deque sem remoção de elementos: ");
    imprimesemRemocaodeElem(&deque);
    
    return 0;
}
