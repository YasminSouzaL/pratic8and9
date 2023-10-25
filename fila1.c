#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct sfila {
    int inicio;
    int fim;
    int elem[MAX];
} Fila;

void inic(Fila *ptrF) {
    ptrF->inicio = 0;
    ptrF->fim = -1;
}

int vazia(Fila *ptrF) {
    if (ptrF->inicio == (ptrF->fim + 1) % MAX)
        return 1;
    else
        return 0;
}

int cheia(Fila *ptrF) {
    if ((ptrF->fim + 1) % MAX == ptrF->inicio)
        return 1;
    else
        return 0;
}

void enfileira(Fila *ptrF, int elem) {
    if (cheia(ptrF)) {
        printf("Fila cheia!\n");
    } else {
        ptrF->fim = (ptrF->fim + 1) % MAX;
        ptrF->elem[ptrF->fim] = elem;
    }
}

void desenfileira(Fila *ptrF) {
    if (vazia(ptrF)) {
        printf("Fila vazia!\n");
    } else {
        ptrF->inicio = (ptrF->inicio + 1) % MAX;
    }
}

int primeiro(Fila *ptrF) {
    if (vazia(ptrF)) {
        printf("Fila vazia!\n");
        return -1;
    } else {
        return ptrF->elem[ptrF->inicio];
    }
}

int ultimo(Fila *ptrF) {
    if (vazia(ptrF)) {
        printf("Fila vazia!\n");
        return -1;
    } else {
        return ptrF->elem[ptrF->fim];
    }
}

void imprimeElemSemRemocao(Fila *ptrF) {
    int inicio = ptrF->inicio;
    int fim = ptrF->fim;
    
    int pos = inicio;

    while (1) {
        printf("%d ", ptrF->elem[pos]);
        if (pos == fim)
            break;
        pos = (pos + 1) % MAX;
    }
    printf("\n");
}

void imprimeElemComRemocao(Fila *ptrF) {
    while (!vazia(ptrF)) {
        int resp = primeiro(ptrF);
        printf("%d ", resp);
        desenfileira(ptrF);
    }
    printf("\n");
}

int main() {
    Fila f;
    inic(&f);
    enfileira(&f, 10);
    enfileira(&f, 20);
    enfileira(&f, 30);
    enfileira(&f, 40);
    enfileira(&f, 50);
    imprimeElemSemRemocao(&f);
    desenfileira(&f);
    desenfileira(&f);
    desenfileira(&f);
    imprimeElemSemRemocao(&f);
    enfileira(&f, 60);
    enfileira(&f, 70);
    enfileira(&f, 80);
    imprimeElemSemRemocao(&f);
    return 0;
}
