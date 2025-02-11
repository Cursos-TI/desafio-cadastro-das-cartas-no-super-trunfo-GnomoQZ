#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int escolharjogador, escolharcomputador;
    srand(time(0));

    do {
        printf("\n+++++ Jogo de Jokenpô +++++\n\n");
        printf("Escolha uma opção:\n");
        printf("1. Pedra\n");
        printf("2. Papel\n");
        printf("3. Tesoura\n");
        printf("4. Para sair do jogo!!\n");
        printf("Escolha: ");
        scanf("%d", &escolharjogador);

        // Verifica se o jogador quer sair
        if (escolharjogador == 4) {
            printf("Tchauu!!!\n");
            break;
        }

        // Gera escolha aleatória do computador
        escolharcomputador = rand() % 3 + 1;

        // Exibe a escolha do jogador
        printf("Jogador: ");
        switch (escolharjogador) {
            case 1: printf("Pedra - "); break;
            case 2: printf("Papel - "); break;
            case 3: printf("Tesoura - "); break;
            default:
                printf("Opção inválida!\n");
                continue; // Pula para a próxima iteração do loop
        }

        // Exibe a escolha do computador
        printf("Computador: ");
        switch (escolharcomputador) {
            case 1: printf("Pedra\n"); break;
            case 2: printf("Papel\n"); break;
            case 3: printf("Tesoura\n"); break;
        }

        // Determina o vencedor
        if (escolharcomputador == escolharjogador) {
            printf("### JOGO EMPATOU! ###\n");
        } else if ((escolharjogador == 1 && escolharcomputador == 3) ||
                   (escolharjogador == 2 && escolharcomputador == 1) ||
                   (escolharjogador == 3 && escolharcomputador == 2)) {
            printf("### Parabéns! Você ganhou!! ###\n");
        } else {
            printf("### Você perdeu!! ###\n");
        }

    } while (escolharjogador != 4);

    return 0;
}
