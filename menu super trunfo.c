#include <stdio.h>
#include <string.h>

// Função para evitar divisão por zero
float dividir(float a, float b) {
    if (b == 0) {
        printf("Aviso: Tentativa de divisão por zero! Retornando 0.\n");
        return 0;
    }
    return a / b;
}

// Definição da estrutura da carta
typedef struct {
    int populacao;
    int ponto_turistico;
    int pib;
    char nome_cidade[30];
    char codigo_carta[6];
    char estado[30];
    float area;
    float densidade;
    float pib_per_capita;
    float super_poder; // Soma das propriedades (ajustada para considerar a densidade invertida)
} Carta;

void cadastrar_cartas(Carta ficha[], int *total_cartas) {
    printf("\n==== Cadastro das Cartas ====\n");
    printf("Quantas cartas deseja cadastrar (máx 8)? ");
    scanf("%d", total_cartas);
    if (*total_cartas > 8) *total_cartas = 8;

    for (int i = 0; i < *total_cartas; i++) {
        printf("\nDigite o código da carta: ");
        scanf("%s", ficha[i].codigo_carta);
        printf("Digite o nome do estado: ");
        scanf("%s", ficha[i].estado);
        printf("Digite o nome da cidade: ");
        scanf("%s", ficha[i].nome_cidade);
        printf("Digite a população: ");
        scanf("%d", &ficha[i].populacao);
        printf("Digite o número de pontos turísticos: ");
        scanf("%d", &ficha[i].ponto_turistico);
        printf("Digite o PIB: ");
        scanf("%d", &ficha[i].pib);
        printf("Digite a área da cidade: ");
        scanf("%f", &ficha[i].area);

        ficha[i].densidade = dividir(ficha[i].populacao, ficha[i].area);
        ficha[i].pib_per_capita = dividir(ficha[i].pib, ficha[i].populacao);
        ficha[i].super_poder = ficha[i].populacao + ficha[i].area + ficha[i].pib + ficha[i].pib_per_capita + dividir(1, ficha[i].densidade) + ficha[i].ponto_turistico;
    }
    printf("\nCartas cadastradas com sucesso!\n");
}

int main() {
    int opcao;
    int cartas_cadastradas = 0;
    int total_cartas = 0;
    Carta ficha[8]; // Até 8 cartas

    do {
        printf("\n+++++++ Bem-vindo ao Super Trunfo +++++++\n");
        printf("1 - Início do jogo\n");
        printf("2 - Cadastrar cartas\n");
        printf("3 - Mostrar cartas cadastradas\n");
        printf("4 - Regras do jogo\n");
        printf("5 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (!cartas_cadastradas) {
                    printf("\nNenhuma carta cadastrada! Deseja cadastrar antes de jogar? (1-Sim, 2-Não): ");
                    int escolha;
                    scanf("%d", &escolha);
                    if (escolha == 1) {
                        cadastrar_cartas(ficha, &total_cartas);
                        cartas_cadastradas = 1;
                    } else {
                        break;
                    }
                }

                char carta_1[6], carta_2[6];
                printf("Jogador 1 - Escolha uma carta pelo código: ");
                scanf("%s", carta_1);
                printf("Jogador 2 - Escolha uma carta pelo código: ");
                scanf("%s", carta_2);

                Carta *carta_jogador1 = NULL;
                Carta *carta_jogador2 = NULL;
                for (int i = 0; i < total_cartas; i++) {
                    if (strcmp(ficha[i].codigo_carta, carta_1) == 0) {
                        carta_jogador1 = &ficha[i];
                    }
                    if (strcmp(ficha[i].codigo_carta, carta_2) == 0) {
                        carta_jogador2 = &ficha[i];
                    }
                }
                
                if (!carta_jogador1 || !carta_jogador2) {
                    printf("\nUma das cartas escolhidas não existe! Verifique os códigos cadastrados.\n");
                    break;
                }

                printf("\nComparando super poderes...\n");
                if (carta_jogador1->super_poder > carta_jogador2->super_poder) {
                    printf("Vencedor: %s com super poder %.2f!\n", carta_jogador1->nome_cidade, carta_jogador1->super_poder);
                } else if (carta_jogador2->super_poder > carta_jogador1->super_poder) {
                    printf("Vencedor: %s com super poder %.2f!\n", carta_jogador2->nome_cidade, carta_jogador2->super_poder);
                } else {
                    printf("Empate! Ambas as cidades têm super poder %.2f.\n", carta_jogador1->super_poder);
                }
                break;

            case 2:
                cadastrar_cartas(ficha, &total_cartas);
                cartas_cadastradas = 1;
                break;

            case 3:
                if (!cartas_cadastradas) {
                    printf("\nNenhuma carta cadastrada!\n");
                } else {
                    printf("\n==== Cartas Cadastradas ====\n");
                    for (int i = 0; i < total_cartas; i++) {
                        printf("\nCarta: %s\n", ficha[i].codigo_carta);
                        printf("Cidade: %s (%s)\n", ficha[i].nome_cidade, ficha[i].estado);
                        printf("População: %d\n", ficha[i].populacao);
                        printf("Área: %.2f km²\n", ficha[i].area);
                        printf("PIB: %d\n", ficha[i].pib);
                        printf("PIB per capita: %.2f\n", ficha[i].pib_per_capita);
                        printf("Densidade populacional: %.2f hab/km²\n", ficha[i].densidade);
                        printf("Super poder: %.2f\n", ficha[i].super_poder);
                    }
                }
                break;

            case 4:
                printf("\nRegras: O jogador com maior super poder vence! No caso da densidade populacional, a menor vence.\n");
                break;

            case 5:
                printf("\nSaindo do jogo... Até logo!\n");
                break;

            default:
                printf("\nOpção inválida!\n");
        }
    } while (opcao != 5);

    return 0;
}
