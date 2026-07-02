#include <stdio.h>


// funcao para criar uma lista de forma crescente, voce pode decidir a quant de vetores
void lista_crescente(int *x) {

    // variaveis que vamos usar
    // 'lista[*x]' sera a nossa lista que vamos organizar
    // 'atual', sera os valores que o usuario decidirar colocar na lista
    // 'primeiro' ira comparar se o valor é menor que o menor numero digitado;
    double lista[*x], atual, primeiro;

    // loop principal do programa, ele ira ocorrer de acordo de vezes que o usuario decidiu executa-lo
    for (int cres = 0; cres < *x; cres++) {

        printf("Digite o valor nº %d: ", cres+1);
        scanf("%lf", &atual);
        printf("\n");

        // esse if é para comparar se é o primeiro loop
        // se esse for o primeiro loop vamos colocar em todos os vetores o primeiro valor digitado
        // e vamos armazenar o primeiro valor digitado na variavel 'primeiro' agindo como se fosse tbm o menor valor inserido
        if (cres == 0) {
            for(int all = 0; all < *x; all++) {
                lista[all] = atual;
                primeiro = atual;
            }
        // criarmos esse else pra economizar processamento desnecessario
        // because não há o que comparar nem verificar, se caso essa for a primeira vez que o loop foi inicializado
        } else {

            // esse for ira comparar todos os valores em ordem decrescente
            for(int decres = *x; decres >= 0; decres--) {

                // esse if serve pra medir se o valor inserido é maior que algum valor da lista
                // como você pode verificar a variavel 'decres' é subtraido 1, pq ela corresponde a quantidade de vetores e não ao indice deles e...
                // para que a variavel 'decres' corresponda ao indice dos vetores precisa subtrair 1 valor dela
                if (atual > lista[decres-1]) {

                    // esse loop vai puxar todos os valores menor que o valor 'digitalizado atualmente (que vou me referir como DA)' pelo usuario ao lado esquerdo da lista
                    for(int puxando = 1; puxando <= decres; puxando++) {
                        // depois de puxar todos os valores menores que o valor DA pelo usuario nós colocamos a DA no espaço que ela dever estar e encerramos o loop
                        // o loop é encerrado porque não precisa continuar deslocando numeros
                        if (puxando == decres) {
                            lista[decres-1] = atual;
                            break;
                        }
                        lista[puxando-1] = lista[puxando];
                    }
                    break;
                // esse else é se caso DA for menor que todos os outros valores
                } else {
                    // Esse if é se caso DA for menor que o primeiro numero digitalizado
                    // nesse caso colocamos DA num vetor á esquerda que o menor vetor (em valor)
                    // armazenamos DA como o menor vetor em 'primeiro', e encerramos o loop de verificação
                    if (atual < primeiro && lista[decres-cres] == primeiro) {
                        lista[decres-cres-1] = atual;
                        primeiro = atual;
                        break;
                    }
                }

            }
        }
        // Esse for tem o objetivo de você pode ver como os vetores se comportam comforme você insere os valores nele
        // os numeros serão organizados da direita á esquerda
        for (int i = 0; i < *x; i++) {
            printf("%.2f, ", lista[i]);
        }
        printf("\n");
    }
}

int main() {
    int test = 0;
    printf("Quantos vetores deseja ter na sua lista? ");
    scanf("%d", &test);
    printf("\n\n");
    lista_crescente(&test);
    return 0;
}