#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Vetores {
    double *lista;
    int quantidade;
};

void Adicionar(struct Vetores *v, double valor) {
    (*v).quantidade++;
    (*v).lista = realloc((*v).lista, sizeof(double) *(*v).quantidade);
    (*v).lista[(*v).quantidade-1] = valor;
}

void Remover(struct Vetores *v, int indice) {
    if (indice >= (*v).quantidade || indice < 0) {
        printf("Indice inexistente\n");
    } else {
        for (int i = indice; i < (*v).quantidade-1; i++) {
            (*v).lista[i] = (*v).lista[i+1];
        }

        (*v).quantidade--;
        (*v).lista = realloc((*v).lista, sizeof(double)*(double)((*v).quantidade));
    }
}

void Expor_vetores(struct Vetores v) {
    for (int x = 0; x < 50; x++) {
        printf("-");
    }
    printf("\n");
    for (int i = 0; i < v.quantidade; i++) {
        printf("indice: %d | valor: %.2f\n", i, v.lista[i]);
    }
    printf("\n");
}

void Destruir(struct Vetores *v) {
    free((*v).lista);
    (*v).lista = NULL;
    (*v).quantidade = 0;
}

int Escolhas() {
    int escolha = 0;

    printf("\nDigite 1 para: adicionar um valor a lista.\n");
    printf("Digite 2 para: remover um valor da lista.\n");
    printf("Digite 3 para: ver os valores na lista e quantidade de vetores\n");
    printf("Digite 0 para: SAIR\n");

    printf("você: ");
    scanf("%d", &escolha);
    printf("\n");

    return escolha;
}

void Pause() {
    int numb = 0;
    while(numb != 1) {
        printf("\nDigite 1 para voltar: ");
        scanf("%d", &numb);
        printf("\n");
    }
}

int main() {
    struct Vetores v = {
        .lista = NULL,
        .quantidade = 0
    };

    bool loop = true;
    double valor = 0;
    int indice = 0;
    while(loop) {
        int escolha = Escolhas();
        switch (escolha) {
            case 1:
                printf("Digite o valor que deseja adicionar na lista.\nVocê: ");
                scanf("%lf", &valor);
                printf("\n");
                Adicionar(&v, valor);
                Pause();
                break;

            case 2:
                printf("Digite o indice que deseja remover da lista.\nVocê: ");
                scanf("%d", &indice);
                printf("\n");
                Remover(&v, indice);
                Pause();
                break;
            case 3:
                Expor_vetores(v);
                printf("Total de vetores em sua lista: %d\n", v.quantidade);
                Pause();
                break;
            case 0:
                loop = false;

        }
    }
    Destruir(&v);

    return 0;
}
