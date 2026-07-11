#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// decidindo quantidade de vetores
void Quant_vetor(double *vetores) {
    printf("Quantos vetores deseja ter na sua lista? ");
    scanf("%lf", vetores);
    printf("\n\n");
}

// Inicializando Vetores...
void Iniciar_vetores(int atual, int vetores, double *lista, double *menor) {
    for(int all = 0; all < vetores; all++) {
        lista[all] = atual;
        *menor = atual;
    }
}

//  PODEROSA PUSH_BACK()
// PODER DE EMPURRAR TODOS OS VETORES PARA TRAS PARA COLOCAR O NOVO VALOR EM SUA DEVIDA POSIÇÃO
void Push_Back(int decres, double *lista, double atual) {
    for(int puxando = 1; puxando <= decres; puxando++) {
        if (puxando == decres) {
            lista[decres-1] = atual;
            break;
        }
        lista[puxando-1] = lista[puxando];
    }

}

bool Menor_valor(double atual, double *menor, double *pro_vetor, double *pre_vetor) {
    // Se atual < "menor valor digitado". ent atual fica um indice atras dele
    if (atual < *menor && *pro_vetor == *menor) {
        *pre_vetor = atual;
        *menor = atual;
        return true;
        }
    return false;
}

int main() {
    
    // 'vetores' representa a quantidade de vetores
    double vetores = 0;

    Quant_vetor(&vetores);

    double *lista, atual, primeiro;

    lista = malloc(vetores * sizeof(double));

    for (int cres = 0; cres < (int)vetores; cres++) {

        printf("Digite o valor nº %d: ", cres+1);
        scanf("%lf", &atual);
        printf("\n");
        
        if (cres == 0) {

            // vamos ocupar todos os vetores, pra evitar lixo, lek
            Iniciar_vetores(atual, (int)vetores, lista, &primeiro);

        } else {

            for(int decres = (int)vetores; decres > 0; decres--) {

                //  Se valor atual > for maior que um vetor da lista
                //  Invocamos a poderosa função Push_Back() e encerramos o loop
                if (atual > lista[decres-1]) {
                    Push_Back(decres, lista, atual);
                    break;
                } else {

                    // Se valor atual < for o menor vetor na lista
                    // INVOCAMOS "Menor_valor()", para atualizar nossa lista corretamente e encerrar o loop
                    if (Menor_valor(atual, &primeiro, &lista[decres-cres], &lista[decres-cres-1])) {
                        break;
                    }
                }
            }
        }

        for (int i = 0; i < (int)vetores; i++) {
            printf("%.2f, ", lista[i]);
        }
        printf("\n");
    }
    free(lista);
    return 0;
}
