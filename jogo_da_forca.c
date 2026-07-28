#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char chave[75], chute, descobrimos[75];
    int vidas;

} Palavra_chave;

void Atribuindo_valor(char chave[], char descobrimos[]) {
    printf("Digite qual sera a palavra chave: ");
    scanf("%74s", chave);

    // todas as palavras vamos substituir por '*', para representa quantidade, excepto as '_', isso vamos deixar assim...
    // para que possa representar o espaço
    for (int i = 0; i < strlen(chave); i++) {
        if (chave[i] == '_') {
            descobrimos[i] = '_';
        } else {
            descobrimos[i] = '*';
        }
    }
    descobrimos[strlen(chave)] = '\0';

    // obviamente vamos limpar a tela, para que o cara que tentara acerta não saiba a palavra chave.
    system("clear");
}


// vamos expor aqui a vida do usuario
// o que ele já acertou
// e pergunta o próximo chute
void Advinhacao(char chave[], char *chute, char descobrimos[], int vidas) {
    printf("Vidas: %d\n", vidas);
    *chute = 's';
    printf("%s", descobrimos);
    
    printf("\nDigite uma palavra chave: ");
    scanf(" %c", chute);
    system("clear");
}


// executamos um loop, para verificar se alguma palavra do chute está dentro da palavra chave
// se sim colocamos dentro do que descobrimos, e colocamos acertou como verdadeiro pra essa função
bool Validando_resposta(char chave[], char chute, char *descobrimos) {
    bool acertou = false;

    for (int i = 0; i < strlen(chave); i++) {
        if (chave[i] == chute) {
            descobrimos[i] = chute;
            acertou = true;
        }
    }

    return acertou;
}

int main() {

    Palavra_chave n1 = {
        .vidas = 3,
    };

    Atribuindo_valor(n1.chave, n1.descobrimos);

    while (n1.vidas > 0) {
        Advinhacao(n1.chave, &n1.chute, n1.descobrimos, n1.vidas);

        if (!Validando_resposta(n1.chave, n1.chute, n1.descobrimos)) {
            n1.vidas--;
        }

        if (strcmp(n1.chave, n1.descobrimos) == 0) {
            printf("Parabéns, você venceu!\n");
            break;
        }

    }
    if (n1.vidas == 0) {
        printf("Ops... voce perdeu\n");
    }
    printf("Palavra chave: %s\n", n1.chave);
    return 0;

}