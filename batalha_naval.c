#include <stdio.h>

#define SIZE 10
#define NAVIO 3
#define AGUA 0
#define HABILIDADE 5

void imprimirTabuleiro(int tabuleiro[SIZE][SIZE]) {
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void aplicarHabilidade(int tabuleiro[SIZE][SIZE], int habilidade[][5], int linOrigem, int colOrigem, int tamanho) {
    int meio = tamanho / 2;
    for(int i = 0; i < tamanho; i++){
        for(int j = 0; j < tamanho; j++){
            int linTab = linOrigem - meio + i;
            int colTab = colOrigem - meio + j;
            if(linTab >= 0 && linTab < SIZE && colTab >= 0 && colTab < SIZE) {
                if(habilidade[i][j] == 1 && tabuleiro[linTab][colTab] == AGUA){
                    tabuleiro[linTab][colTab] = HABILIDADE;
                }
            }
        }
    }
}

int main() {
    int tabuleiro[SIZE][SIZE] = {0};

    tabuleiro[2][3] = NAVIO;
    tabuleiro[4][4] = NAVIO;
    tabuleiro[6][6] = NAVIO;
    tabuleiro[1][7] = NAVIO;

    int cone[5][5] = {0};
    int cruz[5][5] = {0};
    int octaedro[5][5] = {0};

    for(int i = 0; i < 5; i++){
        for(int j = 2 - i; j <= 2 + i; j++){
            if(j >= 0 && j < 5){
                cone[i][j] = 1;
            }
        }
    }

    for(int i = 0; i < 5; i++){
        cruz[2][i] = 1; // linha central
        cruz[i][2] = 1; // coluna central
    }

    for(int i = 0; i < 5; i++){
        int lim = 2 - abs(2 - i);
        for(int j = 2 - lim; j <= 2 + lim; j++){
            octaedro[i][j] = 1;
        }
    }

    printf("Tabuleiro inicial:\n");
    imprimirTabuleiro(tabuleiro);

    aplicarHabilidade(tabuleiro, cone, 1, 3, 5);
    aplicarHabilidade(tabuleiro, cruz, 5, 5, 5);
    aplicarHabilidade(tabuleiro, octaedro, 7, 2, 5);

    printf("Tabuleiro com habilidades aplicadas:\n");
    imprimirTabuleiro(tabuleiro);

    return 0;
}
