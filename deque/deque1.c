#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct sdeque {
    int inicio;
    int fim;
    char elem[MAX];
} Deque;

void inic(Deque *ptrD) {
    ptrD->inicio = MAX - 1;
    ptrD->fim = MAX - 1;
}

int vazia(Deque *ptrD) {
    if (ptrD->inicio == ptrD->fim)
        return 1;
    return 0;
}

int cheia(Deque *ptrD) {
    if ((ptrD->fim + 1) % MAX == ptrD->inicio)
        return 1;
    return 0;
}

void inserirInicio(Deque *ptrD, char elem) {
    if (ptrD->inicio == 0) {
        ptrD->inicio = MAX - 1;
    } else {
        (ptrD->inicio)--;
    }
    if (cheia(ptrD) == 1) {
        printf("Deque cheia\n");
        ptrD->inicio = (ptrD->inicio + 1) % MAX;
        return;
    }
    ptrD->elem[ptrD->inicio] = elem;
}

void inserirFim(Deque *ptrD, char elem) {
    if ((ptrD->fim + 1) % MAX == ptrD->inicio) {
        printf("Deque cheia\n");
        return;
    }
    ptrD->fim = (ptrD->fim + 1) % MAX;
    ptrD->elem[ptrD->fim] = elem;
}

char removerFim(Deque *ptrD) {
    char aux = '\0';
    if (vazia(ptrD) != 1) {
        aux = ptrD->elem[ptrD->fim];
        if (ptrD->fim == 0) {
            ptrD->fim = MAX - 1;
        } else {
            (ptrD->fim)--;
        }
    } else {
        printf("Deque vazia\n");
    }
    return aux;
}

char removerInicio(Deque *ptrD) {
    char aux = '\0';
    if (vazia(ptrD) != 1) {
        aux = ptrD->elem[ptrD->inicio];
        ptrD->inicio = (ptrD->inicio + 1) % MAX;
    } else {
        printf("Deque vazia\n");
    }
    return aux;
}

void implementarComRemocao(Deque *ptrD) {
    while (!vazia(ptrD)) {
        printf("%c ", removerInicio(ptrD));
    }
    printf("\n");
}

void implentarSemRemocao(Deque *ptrD) {
    int i = ptrD->inicio;
    while (i != ptrD->fim) {
        printf("%c ", ptrD->elem[i]);
        i = (i + 1) % MAX;
    }
    printf("%c\n", ptrD->elem[i]);
}

int main() {
    Deque deque;
    inic(&deque);

    inserirInicio(&deque, 'A');
    inserirInicio(&deque, 'B');
    inserirFim(&deque, 'C');
    inserirFim(&deque, 'D');

    printf("Deque com remoção de elementos: ");
    implementarComRemocao(&deque);

    printf("Deque sem remoção de elementos: ");
    implentarSemRemocao(&deque);

    return 0;
}
