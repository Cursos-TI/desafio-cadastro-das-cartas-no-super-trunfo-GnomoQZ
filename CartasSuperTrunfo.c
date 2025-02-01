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
    // Definição da struct
    typedef struct{
    int populacao;
    int ponto_turistuco;
    int pib;
    char nome_cidade[30];
    char codigo_cidade[5];
    float area;
    } carta_A;
    // Criando um array de 3 alunos
    carta_A ficha[4];
    // Loop para preencher os dados das cartas
    for (int i = 0; i < 4; i++){
    printf("\nDigite o codigo da cidade A%02d:\n", i + 1); // Exibe A01, A02, A03, A04.
    printf("Digite codigo da cidade: ");
    scanf("%s", &ficha[i].codigo_cidade);

    printf("Digite o nome da cidade: ");
    scanf(" %s", &ficha[i].nome_cidade);

    printf("Digite o numero da populacao da cidade: ");
    scanf(" %d", &ficha[i].populacao);

    printf("Digite o numero de pontos turisticos: ");
    scanf(" %d", &ficha[i].ponto_turistuco);

    printf("Digite o PIB da cidade: ");
    scanf(" %d", &ficha[i].pib);

    printf("Digite a Area da cidade: ");
    scanf("%F", &ficha[i].area);
    }
    printf("\n");
    // Sugestão: Utilize a função scanf para capturar as entradas do usuário para cada atributo.
    // Solicite ao usuário que insira as informações de cada cidade, como o código, nome, população, área, etc.
    
    // Exibição dos Dados das Cartas:
    // Sugestão: Utilize a função printf para exibir as informações das cartas cadastradas de forma clara e organizada.
    // Exiba os valores inseridos para cada atributo da cidade, um por linha.
    //Exibir os dados dos alunos.
    printf("\n\n==== Informçôes das cartas e atributos cadrastados =======\n\n");
    for (int i = 0; i < 4; i++) {
    printf("Carta A%02d\n", i + 1);  // Exibe A01, A02, A03
    printf("Codigo da cicade: %s\n", ficha[i].codigo_cidade);
    printf("Nome da cidade: %s\n", ficha[i].nome_cidade);
    printf("Numero da população: %d\n", ficha[i].populacao);
    printf("Numero de pontos turisticos: %d\n", ficha[i].ponto_turistuco);
    printf("PIB da cidade: %d\n", ficha[i].pib);
    printf("Area demografica da cidade: %f km²\n\n",ficha[i].area);
    }
    return 0;
}
