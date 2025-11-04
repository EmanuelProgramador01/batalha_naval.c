#include <stdio.h>

int main() {
    // -----------------------------
    // Declaração da matriz 10x10
    // 0 = água, 3 = parte do navio
    // -----------------------------
    int tabuleiro[10][10];

    // Inicializa o tabuleiro com 0 (água)
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // -----------------------------
    // Colocando os navios
    // Tamanho fixo = 3
    // -----------------------------

    // Navio 1 (horizontal) - linha 1, colunas 1 a 3
    for (int j = 1; j <= 3; j++) {
        tabuleiro[1][j] = 3;
    }

    // Navio 2 (vertical) - coluna 6, linhas 4 a 6
    for (int i = 4; i <= 6; i++) {
        tabuleiro[i][6] = 3;
    }

    // Navio 3 (diagonal principal) - posições (2,2), (3,3), (4,4)
    for (int i = 2; i <= 4; i++) {
        tabuleiro[i][i] = 3;
    }

    // Navio 4 (diagonal secundária) - posições (5,4), (6,3), (7,2)
    for (int k = 0; k < 3; k++) {
        tabuleiro[5 + k][4 - k] = 3;
    }

    // -----------------------------
    // Exibição do tabuleiro
    // -----------------------------
    printf("=== BATALHA NAVAL: NIVEL AVENTUREIRO ===\n\n");

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
