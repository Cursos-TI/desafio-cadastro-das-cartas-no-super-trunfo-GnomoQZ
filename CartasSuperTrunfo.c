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
    int populacao,ponto_turistuco;
    char nome_cidade[30],codigo_cidade[5];
    float area,pib;
    printf("Digite codigo da cidade: ");
    scanf("%s", &codigo_cidade);

    printf("Digite o nome da cidade: ");
    scanf(" %s", &nome_cidade);

    printf("Digite o numero da populacao da cidade: ");
    scanf(" %d", &populacao);

    printf("Digite a Area da cidade: ");
    scanf("%.2F", &area);
        


    // Sugestão: Utilize a função scanf para capturar as entradas do usuário para cada atributo.
    // Solicite ao usuário que insira as informações de cada cidade, como o código, nome, população, área, etc.
    
    // Exibição dos Dados das Cartas:
    // Sugestão: Utilize a função printf para exibir as informações das cartas cadastradas de forma clara e organizada.
    // Exiba os valores inseridos para cada atributo da cidade, um por linha.

    return 0;
}
