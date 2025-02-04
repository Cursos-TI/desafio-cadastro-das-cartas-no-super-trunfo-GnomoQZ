#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de cadastro de cartas de cidades.
// Siga os comentários para implementar cada parte do desafio.
//Teste larissa
// Função para dividir dois números
float dividir(float a, float b) {
    if (b == 0) {
        printf("Erro: divisão por zero!\n");
        return 0;
    }
    return a / b;

}
int main() {
    // Sugestão: Defina variáveis separadas para cada atributo da cidade.
    // Exemplos de atributos: código da cidade, nome, população, área, PIB, número de pontos turísticos.
    printf("====== Desafio super trunfo ========= \n\n");
       printf("Cadastro das cartas:\n");

        // Definição da struct
        typedef struct {
            int populacao;
            int ponto_turistico;
            int pib;
            char nome_cidade[30];
            char codigo_cidade[5];
            float area;
            float densidade;
        } carta_A;

        // Criando um array para 4 cartas
        carta_A ficha[4];

        // Loop para preencher os dados das cartas
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

        // Exibição dos dados das cartas cadastradas
        printf("\n\n==== Informações das cartas cadastradas =======\n\n");
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
    return 0;
}
