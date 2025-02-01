#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de cadastro de cartas de cidades.
// Siga os comentários para implementar cada parte do desafio.
//Teste larissa

int main() {
    // Sugestão: Defina variáveis separadas para cada atributo da cidade.
    // Exemplos de atributos: código da cidade, nome, população, área, PIB, número de pontos turísticos.
    printf("====== Desafio super trunfo ========= \n\n");
    printf("Cadrato das cartas:\n");
    int populacao,ponto_turistuco,pib;
    char nome_cidade[30],codigo_cidade[5];
    float area;
    printf("Digite codigo da cidade: ");
    scanf("%s", &codigo_cidade);

    printf("Digite o nome da cidade: ");
    scanf(" %s", &nome_cidade);

    printf("Digite o numero da populacao da cidade: ");
    scanf(" %d", &populacao);

    printf("Digite o numero de pontos turisticos: ");
    scanf(" %d", &ponto_turistuco);

    printf("Digite o PIB da cidade: ");
    scanf(" %d", &pib);

    printf("Digite a Area da cidade: ");
    scanf("%F", &area);
    printf("\n");
    // Sugestão: Utilize a função scanf para capturar as entradas do usuário para cada atributo.
    // Solicite ao usuário que insira as informações de cada cidade, como o código, nome, população, área, etc.
    
    // Exibição dos Dados das Cartas:
    // Sugestão: Utilize a função printf para exibir as informações das cartas cadastradas de forma clara e organizada.
    // Exiba os valores inseridos para cada atributo da cidade, um por linha.
    printf("==== Informçôes das cartas e atributos cadrastados ======= \n");
    printf("Codigo da cicade: %s\n", codigo_cidade);
    printf("Nome da cidade: %s\n", nome_cidade);
    printf("Numero da população: %d\n", populacao);
    printf("Numero de pontos turisticos: %d\n", ponto_turistuco);
    printf("PIB da cidade: %d\n", pib);
    printf("Area demografica da cidade: %f km²", area);
    return 0;
}
