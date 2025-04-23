#include <stdio.h>
#include <string.h>

typedef struct {
    char estado[30];
    int codigo;
    char nome[30];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
} Carta;

void mostrarCarta(Carta c) {
    printf("Estado: %s\n", c.estado);
    printf("Código: %d\n", c.codigo);
    printf("Cidade: %s\n", c.nome);
    printf("População: %d\n", c.populacao);
    printf("Área: %.2f\n", c.area);
    printf("PIB: %.2f\n", c.pib);
    printf("Pontos Turísticos: %d\n", c.pontosTuristicos);
}

void compararSimples(Carta c1, Carta c2) {
    // Comparação por população (exemplo do Nível Novato)
    printf("\nComparando por população...\n");

    if (c1.populacao > c2.populacao) {
        printf("Vencedora: %s\n", c1.nome);
    } else if (c2.populacao > c1.populacao) {
        printf("Vencedora: %s\n", c2.nome);
    } else {
        printf("Empate!\n");
    }
}

void menuComparacao(Carta c1, Carta c2) {
    int opcao;

    printf("\nEscolha um atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Populacional (menor vence)\n");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            if (c1.populacao > c2.populacao)
                printf("Vencedora: %s\n", c1.nome);
            else if (c2.populacao > c1.populacao)
                printf("Vencedora: %s\n", c2.nome);
            else
                printf("Empate!\n");
            break;
        case 2:
            if (c1.area > c2.area)
                printf("Vencedora: %s\n", c1.nome);
            else if (c2.area > c1.area)
                printf("Vencedora: %s\n", c2.nome);
            else
                printf("Empate!\n");
            break;
        case 3:
            if (c1.pib > c2.pib)
                printf("Vencedora: %s\n", c1.nome);
            else if (c2.pib > c1.pib)
                printf("Vencedora: %s\n", c2.nome);
            else
                printf("Empate!\n");
            break;
        case 4:
            if (c1.pontosTuristicos > c2.pontosTuristicos)
                printf("Vencedora: %s\n", c1.nome);
            else if (c2.pontosTuristicos > c1.pontosTuristicos)
                printf("Vencedora: %s\n", c2.nome);
            else
                printf("Empate!\n");
            break;
        case 5: {
            float dens1 = c1.populacao / c1.area;
            float dens2 = c2.populacao / c2.area;
            if (dens1 < dens2)
                printf("Vencedora: %s (menor densidade)\n", c1.nome);
            else if (dens2 < dens1)
                printf("Vencedora: %s (menor densidade)\n", c2.nome);
            else
                printf("Empate de densidade!\n");
            break;
        }
        default:
            printf("Opção inválida.\n");
    }
}

void compararDoisAtributos(Carta c1, Carta c2) {
    int a1, a2;

    printf("\nEscolha dois atributos para comparar:\n");
    printf("1 - População\n2 - Área\n3 - PIB\n4 - Pontos Turísticos\n");
    scanf("%d %d", &a1, &a2);

    int pontos1 = 0, pontos2 = 0;

    float val1a = (a1 == 1) ? c1.populacao : (a1 == 2) ? c1.area : (a1 == 3) ? c1.pib : c1.pontosTuristicos;
    float val2a = (a1 == 1) ? c2.populacao : (a1 == 2) ? c2.area : (a1 == 3) ? c2.pib : c2.pontosTuristicos;

    float val1b = (a2 == 1) ? c1.populacao : (a2 == 2) ? c1.area : (a2 == 3) ? c1.pib : c1.pontosTuristicos;
    float val2b = (a2 == 1) ? c2.populacao : (a2 == 2) ? c2.area : (a2 == 3) ? c2.pib : c2.pontosTuristicos;

    pontos1 += (val1a > val2a) ? 1 : (val2a > val1a) ? 0 : 0;
    pontos2 += (val2a > val1a) ? 1 : 0;

    pontos1 += (val1b > val2b) ? 1 : (val2b > val1b) ? 0 : 0;
    pontos2 += (val2b > val1b) ? 1 : 0;

    if (pontos1 > pontos2)
        printf("Vencedora: %s\n", c1.nome);
    else if (pontos2 > pontos1)
        printf("Vencedora: %s\n", c2.nome);
    else
        printf("Empate!\n");
}

int main() {
    Carta c1, c2;

    printf("Cadastro da Carta 1:\n");
    printf("Estado: "); scanf(" %[^\n]", c1.estado);
    printf("Código: "); scanf("%d", &c1.codigo);
    printf("Cidade: "); scanf(" %[^\n]", c1.nome);
    printf("População: "); scanf("%d", &c1.populacao);
    printf("Área: "); scanf("%f", &c1.area);
    printf("PIB: "); scanf("%f", &c1.pib);
    printf("Pontos turísticos: "); scanf("%d", &c1.pontosTuristicos);

    printf("\nCadastro da Carta 2:\n");
    printf("Estado: "); scanf(" %[^\n]", c2.estado);
    printf("Código: "); scanf("%d", &c2.codigo);
    printf("Cidade: "); scanf(" %[^\n]", c2.nome);
    printf("População: "); scanf("%d", &c2.populacao);
    printf("Área: "); scanf("%f", &c2.area);
    printf("PIB: "); scanf("%f", &c2.pib);
    printf("Pontos turísticos: "); scanf("%d", &c2.pontosTuristicos);

    printf("\nCarta 1:\n"); mostrarCarta(c1);
    printf("\nCarta 2:\n"); mostrarCarta(c2);

    // Nível Novato
    compararSimples(c1, c2);

    // Nível Aventureiro
    menuComparacao(c1, c2);

    // Nível Mestre
    compararDoisAtributos(c1, c2);

    return 0;
}
