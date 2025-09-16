#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função para obter o valor de um atributo
float getValor(int atributo, int carta,
               unsigned long int pop1, unsigned long int pop2,
               float area1, float area2,
               float pib1, float pib2,
               int pt1, int pt2,
               float dens1, float dens2) {
    switch (atributo) {
        case 1: return (carta == 1) ? (float)pop1 : (float)pop2;
        case 2: return (carta == 1) ? area1 : area2;
        case 3: return (carta == 1) ? pib1 : pib2;
        case 4: return (carta == 1) ? (float)pt1 : (float)pt2;
        case 5: return (carta == 1) ? dens1 : dens2;
        default: return 0.0f;
    }
}

int main() {
    // ====== Declaração de variáveis ======
    char estado_c1[30], codigo_c1[10], cidade_c1[30];
    unsigned long int populacao_c1;
    float area_c1, pib_c1, densidade_c1;
    int pontos_turisticos_c1;

    char estado_c2[30], codigo_c2[10], cidade_c2[30];
    unsigned long int populacao_c2;
    float area_c2, pib_c2, densidade_c2;
    int pontos_turisticos_c2;

    // ===== Entrada de dados da Carta 1 =====
    printf("=== CADASTRO DA CARTA 1 ===\n");
    printf("Estado: "); scanf("%s", estado_c1);
    printf("Codigo: "); scanf("%s", codigo_c1);
    printf("Cidade: "); scanf("%s", cidade_c1);
    printf("Populacao: "); scanf("%lu", &populacao_c1);
    printf("Area (km²): "); scanf("%f", &area_c1);
    printf("PIB (em bilhoes): "); scanf("%f", &pib_c1);
    printf("Pontos turisticos: "); scanf("%d", &pontos_turisticos_c1);

    densidade_c1 = populacao_c1 / area_c1;

    // ===== Entrada de dados da Carta 2 =====
    printf("\n=== CADASTRO DA CARTA 2 ===\n");
    printf("Estado: "); scanf("%s", estado_c2);
    printf("Codigo: "); scanf("%s", codigo_c2);
    printf("Cidade: "); scanf("%s", cidade_c2);
    printf("Populacao: "); scanf("%lu", &populacao_c2);
    printf("Area (km²): "); scanf("%f", &area_c2);
    printf("PIB (em bilhoes): "); scanf("%f", &pib_c2);
    printf("Pontos turisticos: "); scanf("%d", &pontos_turisticos_c2);

    densidade_c2 = populacao_c2 / area_c2;

    // ===== Menu Dinâmico: Escolha de dois atributos =====
    int atributo1 = 0, atributo2 = 0;
    int escolhaValida = 0;

    // Escolha do primeiro atributo
    do {
        printf("\n=== MENU DE ATRIBUTOS ===\n");
        printf("1 - Populacao\n");
        printf("2 - Area\n");
        printf("3 - PIB\n");
        printf("4 - Pontos Turisticos\n");
        printf("5 - Densidade Demografica\n");
        printf("Escolha o PRIMEIRO atributo: ");
        scanf("%d", &atributo1);
        escolhaValida = (atributo1 >= 1 && atributo1 <= 5);
        if (!escolhaValida) printf("Opcao invalida. Tente novamente.\n");
    } while (!escolhaValida);

    // Escolha do segundo atributo (diferente do primeiro)
    do {
        printf("\n=== MENU DE ATRIBUTOS (Escolha diferente do primeiro) ===\n");
        for (int i = 1; i <= 5; i++) {
            if (i == atributo1) continue;
            switch (i) {
                case 1: printf("1 - Populacao\n"); break;
                case 2: printf("2 - Area\n"); break;
                case 3: printf("3 - PIB\n"); break;
                case 4: printf("4 - Pontos Turisticos\n"); break;
                case 5: printf("5 - Densidade Demografica\n"); break;
            }
        }
        printf("Escolha o SEGUNDO atributo: ");
        scanf("%d", &atributo2);
        escolhaValida = (atributo2 >= 1 && atributo2 <= 5 && atributo2 != atributo1);
        if (!escolhaValida) printf("Opcao invalida ou repetida. Tente novamente.\n");
    } while (!escolhaValida);

    // ===== Comparação =====
    float valor1_c1 = getValor(atributo1, 1, populacao_c1, populacao_c2, area_c1, area_c2,
                               pib_c1, pib_c2, pontos_turisticos_c1, pontos_turisticos_c2,
                               densidade_c1, densidade_c2);
    float valor1_c2 = getValor(atributo1, 2, populacao_c1, populacao_c2, area_c1, area_c2,
                               pib_c1, pib_c2, pontos_turisticos_c1, pontos_turisticos_c2,
                               densidade_c1, densidade_c2);

    float valor2_c1 = getValor(atributo2, 1, populacao_c1, populacao_c2, area_c1, area_c2,
                               pib_c1, pib_c2, pontos_turisticos_c1, pontos_turisticos_c2,
                               densidade_c1, densidade_c2);
    float valor2_c2 = getValor(atributo2, 2, populacao_c1, populacao_c2, area_c1, area_c2,
                               pib_c1, pib_c2, pontos_turisticos_c1, pontos_turisticos_c2,
                               densidade_c1, densidade_c2);

    // ===== Exibição clara dos resultados =====
    printf("\n=== COMPARACAO ENTRE %s E %s ===\n", estado_c1, estado_c2);

    // Função auxiliar para exibir nome do atributo
    char *nomeAtributo;
    // --- Atributo 1 ---
    switch (atributo1) {
        case 1: nomeAtributo = "Populacao"; break;
        case 2: nomeAtributo = "Area"; break;
        case 3: nomeAtributo = "PIB"; break;
        case 4: nomeAtributo = "Pontos Turisticos"; break;
        case 5: nomeAtributo = "Densidade Demografica"; break;
    }
    printf("\nAtributo 1: %s\n", nomeAtributo);
    printf("%s: %.2f  x  %s: %.2f\n", estado_c1, valor1_c1, estado_c2, valor1_c2);
    if (atributo1 == 5)
        printf("Vencedor: %s\n", (valor1_c1 < valor1_c2) ? estado_c1 :
                                  (valor1_c2 < valor1_c1) ? estado_c2 : "Empate");
    else
        printf("Vencedor: %s\n", (valor1_c1 > valor1_c2) ? estado_c1 :
                                 (valor1_c2 > valor1_c1) ? estado_c2 : "Empate");

    // --- Atributo 2 ---
    switch (atributo2) {
        case 1: nomeAtributo = "Populacao"; break;
        case 2: nomeAtributo = "Area"; break;
        case 3: nomeAtributo = "PIB"; break;
        case 4: nomeAtributo = "Pontos Turisticos"; break;
        case 5: nomeAtributo = "Densidade Demografica"; break;
    }
    printf("\nAtributo 2: %s\n", nomeAtributo);
    printf("%s: %.2f  x  %s: %.2f\n", estado_c1, valor2_c1, estado_c2, valor2_c2);
    if (atributo2 == 5)
        printf("Vencedor: %s\n", (valor2_c1 < valor2_c2) ? estado_c1 :
                                  (valor2_c2 < valor2_c1) ? estado_c2 : "Empate");
    else
        printf("Vencedor: %s\n", (valor2_c1 > valor2_c2) ? estado_c1 :
                                 (valor2_c2 > valor2_c1) ? estado_c2 : "Empate");

    // ===== Soma de atributos =====
    // Para densidade, como menor vence, usamos valor invertido para soma
    float soma_c1 = ((atributo1 == 5) ? -valor1_c1 : valor1_c1) +
                    ((atributo2 == 5) ? -valor2_c1 : valor2_c1);
    float soma_c2 = ((atributo1 == 5) ? -valor1_c2 : valor1_c2) +
                    ((atributo2 == 5) ? -valor2_c2 : valor2_c2);

    printf("\nSoma dos atributos:\n");
    printf("%s: %.2f  x  %s: %.2f\n", estado_c1, soma_c1, estado_c2, soma_c2);

    if (soma_c1 > soma_c2)
        printf("\n>>> VENCEDOR FINAL: %s <<<\n", estado_c1);
    else if (soma_c2 > soma_c1)
        printf("\n>>> VENCEDOR FINAL: %s <<<\n", estado_c2);
    else
        printf("\n>>> EMPATE! <<<\n");

    return 0;
}
