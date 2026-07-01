#include <stdio.h>
#include <stdbool.h>

void Tabuada() {
    for (int i = 1; i < 11; i++) {
        printf("\n Tabuada do %d\n", i);
        for (int j = 1; j < 11; j++) {
            printf("%d * %d = %d\n", i,j,i*j);
        }
        printf("\n");

    }
}

void Lista_Crescente() {
    double test, lista[11],var;

    for (int i = 0; i < 10; i++) {
        if (i+1 == -1074790398) {
            break;
        }

        printf("\n %d) Digite um numero: ", i+1);
        scanf("%lf", &test);

        if (i == 0) {
            for (int j = 0; j <10; j++) {
                lista[j] = test;
            }
        } else {
            for (int j = 9; j >= 0; j--) {
                // Esse if é pra poder armazernar valores pequenos
                if (test > lista[j]) {
                    for (int ind = 1; ind <= j; ind++) {
                            lista[ind-1] = lista[ind];
                        }
                        lista[j] = test;
                        break;

                } else {
                    if (lista[j-i] > test) {
                        var = lista[j-i];
                        lista[j-i] = test;
                        lista[j-i-1] = var;
                        break;
                    }
                }
            }
        }
        for(int abc = 0; abc <= 9; abc++) {
            printf("%.2f, ", lista[abc]);
        }
        printf("\n"); 
    }
}


int main() {
    Lista_Crescente();
    return 0;
}