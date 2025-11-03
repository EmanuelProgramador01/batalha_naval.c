#include <stdio.h>

int main() {
    // Declaração da matriz 10x10 representando o tabuleiro
    char tabuleiro[10][10];

    // Inicializa o tabuleiro com '~' (água)
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = '~';
        }
    }

    // ------------------------------
    // Colocando navios fixos no tabuleiro
    // Cada navio tem tamanho 3
    // ------------------------------

    // Navio 1 (linha 1, colunas 1-3)
    tabuleiro[1][1] = 'N';
    tabuleiro[1][2] = 'N';
    tabuleiro[1][3] = 'N';

    // Navio 2 (linha 4, colunas 4-6)
    tabuleiro[4][4] = 'N';
    tabuleiro[4][5] = 'N';
    tabuleiro[4][6] = 'N';

    // Navio 3 (linha 7, colunas 2-4)
    tabuleiro[7][2] = 'N';
    tabuleiro[7][3] = 'N';
    tabuleiro[7][4] = 'N';

    // ------------------------------
    // Exibição do tabuleiro
    // ------------------------------
    printf("=== BATALHA NAVAL ===\n\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
