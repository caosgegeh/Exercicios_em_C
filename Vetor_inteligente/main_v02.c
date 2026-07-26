#include <stdio.h>
#include "smart_vector_v02.h"
#include <stdbool.h>


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

    Vetores v;
    Iniciar(&v);

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
