#include <stdio.h>

// Tamanho fixo do tabuleiro
#define TAMANHO 10

int main() {
    // Declaração da matriz do tabuleiro e inicialização com 0 (água)
    int tabuleiro[TAMANHO][TAMANHO] = {0};

    // Tamanho fixo dos navios
    int tamanho_navio = 3;

    // Vetores representando os navios (valores arbitrários só pra representar)
    int navio_horizontal[3] = {3, 3, 3};
    int navio_vertical[3] = {3, 3, 3};

    // Coordenadas iniciais dos navios
    int linha_horizontal = 2;
    int coluna_horizontal = 4;

    int linha_vertical = 5;
    int coluna_vertical = 7;

    // Validação: verifica se o navio horizontal cabe no tabuleiro
    if (coluna_horizontal + tamanho_navio > TAMANHO) {
        printf("Erro: navio horizontal fora dos limites!\n");
        return 1;
    }

    // Validação: verifica se o navio vertical cabe no tabuleiro
    if (linha_vertical + tamanho_navio > TAMANHO) {
        printf("Erro: navio vertical fora dos limites!\n");
        return 1;
    }

    // Validação: verifica se há sobreposição antes de posicionar
    int sobreposicao = 0;

    for (int i = 0; i < tamanho_navio; i++) {
        if (tabuleiro[linha_horizontal][coluna_horizontal + i] != 0 ||
            tabuleiro[linha_vertical + i][coluna_vertical] != 0) {
            sobreposicao = 1;
        }
    }

    if (sobreposicao) {
        printf("Erro: sobreposição de navios detectada!\n");
        return 1;
    }

    // Posicionamento do navio horizontal no tabuleiro
    for (int i = 0; i < tamanho_navio; i++) {
        tabuleiro[linha_horizontal][coluna_horizontal + i] = navio_horizontal[i];
    }

    // Posicionamento do navio vertical no tabuleiro
    for (int i = 0; i < tamanho_navio; i++) {
        tabuleiro[linha_vertical + i][coluna_vertical] = navio_vertical[i];
    }

    // Impressão do tabuleiro no console
    printf("Tabuleiro de Batalha Naval:\n\n");

    for (int linha = 0; linha < TAMANHO; linha++) {
        for (int coluna = 0; coluna < TAMANHO; coluna++) {
            printf("%d ", tabuleiro[linha][coluna]);
        }
        printf("\n");
    }

    return 0;
}
