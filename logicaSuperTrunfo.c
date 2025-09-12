#include <stdio.h>

int main() {
    // ===== Declaração das variáveis =====
    // Carta 1
    char estado_c1[20], codigo_c1[10], cidade_c1[20];
    unsigned long int populacao_c1;
    float area_c1, pib_c1, densidade_c1, pib_per_capita_c1;
    int pontos_turisticos_c1;

    // Carta 2
    char estado_c2[20], codigo_c2[10], cidade_c2[20];
    unsigned long int populacao_c2;
    float area_c2, pib_c2, densidade_c2, pib_per_capita_c2;
    int pontos_turisticos_c2;

    // ===== Entrada de dados =====
    printf("=== Cadastro da Carta 1 ===\n");
    printf("Estado: ");
    scanf("%s", estado_c1);
    printf("Codigo da carta: ");
    scanf("%s", codigo_c1);
    printf("Cidade: ");
    scanf("%s", cidade_c1);
    printf("Populacao: ");
    scanf("%lu", &populacao_c1);
    printf("Area (em km2): ");
    scanf("%f", &area_c1);
    printf("PIB: ");
    scanf("%f", &pib_c1);
    printf("Numero de pontos turisticos: ");
    scanf("%d", &pontos_turisticos_c1);

    printf("\n=== Cadastro da Carta 2 ===\n");
    printf("Estado: ");
    scanf("%s", estado_c2);
    printf("Codigo da carta: ");
    scanf("%s", codigo_c2);
    printf("Cidade: ");
    scanf("%s", cidade_c2);
    printf("Populacao: ");
    scanf("%lu", &populacao_c2);
    printf("Area (em km2): ");
    scanf("%f", &area_c2);
    printf("PIB: ");
    scanf("%f", &pib_c2);
    printf("Numero de pontos turisticos: ");
    scanf("%d", &pontos_turisticos_c2);

    // ===== Cálculos =====
    densidade_c1 = (float)populacao_c1 / area_c1;
    densidade_c2 = (float)populacao_c2 / area_c2;

    pib_per_capita_c1 = pib_c1 / (float)populacao_c1;
    pib_per_capita_c2 = pib_c2 / (float)populacao_c2;

    // ===== Exibição dos cálculos =====
    printf("\n--- Informacoes calculadas ---\n");
    printf("Carta 1 (%s): Densidade Populacional = %.2f | PIB per capita = %.2f\n", cidade_c1, densidade_c1, pib_per_capita_c1);
    printf("Carta 2 (%s): Densidade Populacional = %.2f | PIB per capita = %.2f\n", cidade_c2, densidade_c2, pib_per_capita_c2);

    // ===== Comparação usando atributo pré-definido =====
    // Aqui foi escolhido o PIB per capita como atributo de comparação.
    printf("\n=== Comparacao ===\n");
    printf("Atributo utilizado: PIB per capita\n");
    printf("%s: %.2f\n", cidade_c1, pib_per_capita_c1);
    printf("%s: %.2f\n", cidade_c2, pib_per_capita_c2);

    if (pib_per_capita_c1 > pib_per_capita_c2) {
        printf("Resultado: Carta 1 (%s) venceu!\n", cidade_c1);
    } else if (pib_per_capita_c2 > pib_per_capita_c1) {
        printf("Resultado: Carta 2 (%s) venceu!\n", cidade_c2);
    } else {
        printf("Resultado: Empate entre as duas cartas!\n");
    }

    return 0;
}

