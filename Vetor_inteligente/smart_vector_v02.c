#include "smart_vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void Iniciar(Vetores *v) {
    (*v).lista = NULL;
    (*v).quantidade = 0;
}

void Adicionar(Vetores *v, double valor) {
    (*v).quantidade++;
    (*v).lista = realloc((*v).lista, sizeof(double) *(*v).quantidade);
    (*v).lista[(*v).quantidade-1] = valor;
}

void Remover(Vetores *v, int indice) {
    if (indice >= (*v).quantidade || indice < 0) {
        printf("Indice inexistente\n");
    } else {
        for (int i = indice; i < (*v).quantidade-1; i++) {
            (*v).lista[i] = (*v).lista[i+1];
        }

        (*v).quantidade--;
        (*v).lista = realloc((*v).lista, sizeof(double)*(*v).quantidade);
    }
}

void Expor_vetores(Vetores v) {
    for (int x = 0; x < 50; x++) {
        printf("-");
    }
    printf("\n");
    for (int i = 0; i < v.quantidade; i++) {
        printf("indice: %d | valor: %.2f\n", i, v.lista[i]);
    }
    printf("\n");
}

void Destruir(Vetores *v) {
    free((*v).lista);
    (*v).lista = NULL;
    (*v).quantidade = 0;
}

