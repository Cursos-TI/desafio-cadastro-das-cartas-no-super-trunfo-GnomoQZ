#include <stdio.h>
#include <string.h>  // Biblioteca para comparação de strings

// Função para dividir dois números, evitando divisão por zero
float dividir(float a, float b) {
    if (b == 0) {
        printf("Erro: divisão por zero!\n");
        return 0;
    }
    return a / b;
}

int main() {
    int opcao; // Armazena a escolha do usuário
    int cartas_cadastradas = 0; // Flag para verificar se cartas foram cadastradas

    // Definição da struct
    typedef struct {
        int populacao;
        int ponto_turistico;
        int pib;
        char nome_cidade[30];
        char codigo_cidade[6]; // Ajustado para 5 caracteres + '\0'
        float area;
        float densidade;
    } carta_A;

    // Criando um array para 4 cartas fora do switch para uso global no menu
    carta_A ficha[4];

    do {
        // Exibe o menu principal
        printf("\n+++++++ Bem-vindo ao jogo Super Trunfo +++++++\n");
        printf("1 - Cadastrar cartas\n");
        printf("2 - Início do jogo Super Trunfo, onde os jogadores escolhem suas cartas.\n");
        printf("3 - Mostrar as cartas cadastradas\n");
        printf("4 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: { 
                // Cadastro de cartas
                printf("\n==== Cadastro das Cartas ====\n");
                
                for (int i = 0; i < 4; i++) {
                    printf("\nDigite o código da cidade A%02d:\n", i + 1);
                    printf("Digite o código da cidade: ");
                    scanf("%s", ficha[i].codigo_cidade);

                    printf("Digite o nome da cidade: ");
                    scanf("%s", ficha[i].nome_cidade);

                    printf("Digite o número da população da cidade: ");
                    scanf("%d", &ficha[i].populacao);

                    printf("Digite o número de pontos turísticos: ");
                    scanf("%d", &ficha[i].ponto_turistico);

                    printf("Digite o PIB da cidade: ");
                    scanf("%d", &ficha[i].pib);

                    printf("Digite a área da cidade: ");
                    scanf("%f", &ficha[i].area);

                    // Calculando densidade demográfica
                    ficha[i].densidade = dividir(ficha[i].populacao, ficha[i].area);
                }

                // Atualiza a flag para indicar que cartas foram cadastradas
                cartas_cadastradas = 1;
                printf("\nCartas cadastradas com sucesso!\n");
                break;
            }

            case 2:
                if (cartas_cadastradas == 0) {
                    printf("\nNenhuma carta cadastrada ainda! Cadastre primeiro.\n");
                    break;
                }

                printf("\n------ SUPER TRUNFO ------\n");
                printf("Primeiro jogador - Escolha uma carta digitando o código (Ex: A01, A02, etc): ");
                char carta_1[6], carta_2[6];
                scanf("%s", carta_1);

                printf("Segundo jogador - Escolha uma carta digitando o código: ");
                scanf("%s", carta_2);

                printf("Comparando as cartas...\n\n");

                // Encontrando as cartas escolhidas
                carta_A *carta_jogador1 = NULL;
                carta_A *carta_jogador2 = NULL;

                for (int i = 0; i < 4; i++) {
                    if (strcmp(ficha[i].codigo_cidade, carta_1) == 0) {
                        carta_jogador1 = &ficha[i];
                    }
                    if (strcmp(ficha[i].codigo_cidade, carta_2) == 0) {
                        carta_jogador2 = &ficha[i];
                    }
                }

                // Verificando se as cartas existem
                if (carta_jogador1 == NULL || carta_jogador2 == NULL) {
                    printf("Uma das cartas escolhidas não existe! Tente novamente.\n");
                    break;
                }

                // Comparação das cartas
                if (carta_jogador1->pib > carta_jogador2->pib) {
                    printf("Vencedor: %s com PIB maior (%d vs %d)!\n", carta_jogador1->nome_cidade, carta_jogador1->pib, carta_jogador2->pib);
                } else if (carta_jogador2->pib > carta_jogador1->pib) {
                    printf("Vencedor: %s com PIB maior (%d vs %d)!\n", carta_jogador2->nome_cidade, carta_jogador2->pib, carta_jogador1->pib);
                } else {
                    printf("Empate! Ambas as cidades têm o mesmo PIB (%d).\n", carta_jogador1->pib);
                }
                break;

            case 3:
                if (cartas_cadastradas == 0) {
                    printf("\nNenhuma carta cadastrada ainda! Cadastre primeiro.\n");
                } else {
                    printf("\n\n==== Informações das Cartas Cadastradas ====\n\n");
                    for (int i = 0; i < 4; i++) {
                        printf("Carta A%02d\n", i + 1);
                        printf("Código da cidade: %s\n", ficha[i].codigo_cidade);
                        printf("Nome da cidade: %s\n", ficha[i].nome_cidade);
                        printf("Número da população: %d\n", ficha[i].populacao);
                        printf("Número de pontos turísticos: %d\n", ficha[i].ponto_turistico);
                        printf("PIB da cidade: %d\n", ficha[i].pib);
                        printf("Área da cidade: %.2f km²\n", ficha[i].area);
                        printf("Densidade demográfica da cidade: %.2f hab/km²\n\n", ficha[i].densidade);
                    }
                }
                break;

            case 4:
                printf("\nSaindo do jogo... Até logo!\n");
                break;

            default:
                printf("\nOpção inválida! Tente novamente.\n");
        }
        
    } while (opcao != 4); // Continua até o usuário escolher "Sair"

    return 0;
}
