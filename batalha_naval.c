#include <stdio.h>

#define TAM 10     // Tamanho do tabuleiro 10x10
#define HAB 5      // Tamanho fixo das matrizes de habilidade 5x5

int main() {
    int tabuleiro[TAM][TAM];

    // ---------------------------------------------
    // 1. Inicialização do tabuleiro com água (0)
    // ---------------------------------------------
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // ---------------------------------------------
    // 2. Posicionando navios (valor = 3)
    // ---------------------------------------------
    // Navio horizontal
    for (int j = 1; j <= 3; j++) tabuleiro[1][j] = 3;

    // Navio vertical
    for (int i = 4; i <= 6; i++) tabuleiro[i][6] = 3;

    // Navio diagonal principal
    for (int i = 2; i <= 4; i++) tabuleiro[i][i] = 3;

    // Navio diagonal secundária
    for (int k = 0; k < 3; k++) tabuleiro[5 + k][4 - k] = 3;

    // ---------------------------------------------
    // 3. Matrizes de habilidades (0 = fora, 1 = área de efeito)
    // ---------------------------------------------
    int cone[HAB][HAB];
    int cruz[HAB][HAB];
    int octaedro[HAB][HAB];

    // 3.1. Habilidade em forma de CONE
    // O cone expande para baixo: 1 célula no topo, depois 3, depois 5
    for (int i = 0; i < HAB; i++) {
        for (int j = 0; j < HAB; j++) {
            if (j >= 2 - i && j <= 2 + i)  // condição de expansão
                cone[i][j] = 1;
            else
                cone[i][j] = 0;
        }
    }

    // 3.2. Habilidade em forma de CRUZ
    for (int i = 0; i < HAB; i++) {
        for (int j = 0; j < HAB; j++) {
            if (i == 2 || j == 2)
                cruz[i][j] = 1;
            else
                cruz[i][j] = 0;
        }
    }

    // 3.3. Habilidade em forma de OCTAEDRO (losango)
    for (int i = 0; i < HAB; i++) {
        for (int j = 0; j < HAB; j++) {
            if (abs(i - 2) + abs(j - 2) <= 2)
                octaedro[i][j] = 1;
            else
                octaedro[i][j] = 0;
        }
    }

    // ---------------------------------------------
    // 4. Aplicando habilidades no tabuleiro
    // ---------------------------------------------
    // Definindo coordenadas de origem (centro da habilidade)
    int origemConeLinha = 2, origemConeColuna = 2;
    int origemCruzLinha = 6, origemCruzColuna = 6;
    int origemOctaLinha = 7, origemOctaColuna = 3;

    // Função genérica de sobreposição (feito diretamente com loops)
    for (int i = 0; i < HAB; i++) {
        for (int j = 0; j < HAB; j++) {
            // CONE
            int linhaCone = origemConeLinha - 2 + i;
            int colunaCone = origemConeColuna - 2 + j;
            if (linhaCone >= 0 && linhaCone < TAM && colunaCone >= 0 && colunaCone < TAM) {
                if (cone[i][j] == 1 && tabuleiro[linhaCone][colunaCone] == 0)
                    tabuleiro[linhaCone][colunaCone] = 5;
            }

            // CRUZ
            int linhaCruz = origemCruzLinha - 2 + i;
            int colunaCruz = origemCruzColuna - 2 + j;
            if (linhaCruz >= 0 && linhaCruz < TAM && colunaCruz >= 0 && colunaCruz < TAM) {
                if (cruz[i][j] == 1 && tabuleiro[linhaCruz][colunaCruz] == 0)
                    tabuleiro[linhaCruz][colunaCruz] = 5;
            }

            // OCTAEDRO
            int linhaOcta = origemOctaLinha - 2 + i;
            int colunaOcta = origemOctaColuna - 2 + j;
            if (linhaOcta >= 0 && linhaOcta < TAM && colunaOcta >= 0 && colunaOcta < TAM) {
                if (octaedro[i][j] == 1 && tabuleiro[linhaOcta][colunaOcta] == 0)
                    tabuleiro[linhaOcta][colunaOcta] = 5;
            }
        }
    }

    // ---------------------------------------------
    // 5. Exibindo o tabuleiro completo
    // ---------------------------------------------
    printf("=== BATALHA NAVAL: NIVEL MESTRE ===\n\n");
    printf("Legenda: 0=Agua | 3=Navio | 5=Area de Habilidade\n\n");

    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
