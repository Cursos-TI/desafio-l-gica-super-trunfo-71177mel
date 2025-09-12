#include <stdio.h>
#include <string.h>

int main() {
    // ====== Declaração de variáveis da Carta 1 ======
    char pais_c1[30], codigo_c1[10], cidade_c1[30];
    unsigned long int populacao_c1;
    float area_c1, pib_c1, densidade_c1, pib_per_capita_c1;
    int pontos_turisticos_c1;

    // ====== Declaração de variáveis da Carta 2 ======
    char pais_c2[30], codigo_c2[10], cidade_c2[30];
    unsigned long int populacao_c2;
    float area_c2, pib_c2, densidade_c2, pib_per_capita_c2;
    int pontos_turisticos_c2;

    // ===== Entrada de dados para Carta 1 =====
    printf("=== Cadastro da CARTA 1 ===\n");
    printf("Digite o nome do pais: ");
    scanf("%s", pais_c1);

    printf("Digite o codigo: ");
    scanf("%s", codigo_c1);

    printf("Digite a cidade: ");
    scanf("%s", cidade_c1);

    printf("Digite a populacao: ");
    scanf("%lu", &populacao_c1);

    printf("Digite a area em km²: ");
    scanf("%f", &area_c1);

    printf("Digite o PIB (em bilhões): ");
    scanf("%f", &pib_c1);

    printf("Digite o numero de pontos turisticos: ");
    scanf("%d", &pontos_turisticos_c1);

    // ===== Cálculos para Carta 1 =====
    densidade_c1 = populacao_c1 / area_c1;
    pib_per_capita_c1 = pib_c1 / populacao_c1;

    // ===== Entrada de dados para Carta 2 =====
    printf("\n=== Cadastro da CARTA 2 ===\n");
    printf("Digite o nome do pais: ");
    scanf("%s", pais_c2);

    printf("Digite o codigo: ");
    scanf("%s", codigo_c2);

    printf("Digite a cidade: ");
    scanf("%s", cidade_c2);

    printf("Digite a populacao: ");
    scanf("%lu", &populacao_c2);

    printf("Digite a area em km²: ");
    scanf("%f", &area_c2);

    printf("Digite o PIB (em bilhões): ");
    scanf("%f", &pib_c2);

    printf("Digite o numero de pontos turisticos: ");
    scanf("%d", &pontos_turisticos_c2);

    // ===== Cálculos para Carta 2 =====
    densidade_c2 = populacao_c2 / area_c2;
    pib_per_capita_c2 = pib_c2 / populacao_c2;

    // ===== Menu Interativo =====
    int opcao;
    printf("\n=== MENU DE COMPARACAO ===\n");
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - PIB\n");
    printf("4 - Numero de pontos turisticos\n");
    printf("5 - Densidade demografica\n");
    printf("Escolha o atributo para comparacao: ");
    scanf("%d", &opcao);

    // ===== Lógica de comparação =====
    printf("\nComparando %s e %s\n", pais_c1, pais_c2);

    switch (opcao) {
        case 1: // População
            printf("Populacao: %lu x %lu\n", populacao_c1, populacao_c2);
            if (populacao_c1 > populacao_c2) printf("Vencedor: %s\n", pais_c1);
            else if (populacao_c2 > populacao_c1) printf("Vencedor: %s\n", pais_c2);
            else printf("Empate!\n");
            break;

        case 2: // Área
            printf("Area: %.2f km² x %.2f km²\n", area_c1, area_c2);
            if (area_c1 > area_c2) printf("Vencedor: %s\n", pais_c1);
            else if (area_c2 > area_c1) printf("Vencedor: %s\n", pais_c2);
            else printf("Empate!\n");
            break;

        case 3: // PIB
            printf("PIB: %.2f x %.2f\n", pib_c1, pib_c2);
            if (pib_c1 > pib_c2) printf("Vencedor: %s\n", pais_c1);
            else if (pib_c2 > pib_c1) printf("Vencedor: %s\n", pais_c2);
            else printf("Empate!\n");
            break;

        case 4: // Pontos turísticos
            printf("Pontos turisticos: %d x %d\n", pontos_turisticos_c1, pontos_turisticos_c2);
            if (pontos_turisticos_c1 > pontos_turisticos_c2) printf("Vencedor: %s\n", pais_c1);
            else if (pontos_turisticos_c2 > pontos_turisticos_c1) printf("Vencedor: %s\n", pais_c2);
            else printf("Empate!\n");
            break;

        case 5: // Densidade demográfica (menor vence)
            printf("Densidade demografica: %.2f hab/km² x %.2f hab/km²\n", densidade_c1, densidade_c2);
            if (densidade_c1 < densidade_c2) printf("Vencedor: %s (menor densidade)\n", pais_c1);
            else if (densidade_c2 < densidade_c1) printf("Vencedor: %s (menor densidade)\n", pais_c2);
            else printf("Empate!\n");
            break;

        default:
            printf("Opcao invalida! Tente novamente.\n");
    }

    return 0;
}
