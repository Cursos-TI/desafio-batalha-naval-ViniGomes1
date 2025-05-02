#include <stdio.h>
#include <stdbool.h>

#include <stdlib.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.
/*

mudanças importantes em relação ao commit anterior:

1 - as variáveis essênciais como a matriz da batalha naval e os números correspondentes a objetos, agora são globais
o objetivo disto é permitir que funções possam as manipular, facilitando a compreensão do código

2 - agora há funções que exercem tarefas específicas

*/
int barco = 3;
int habilidades = 5;

int quadro[10][10];

//função relacionada as diagonais
void diagonal(int barcoPosicao3[2], int barcoPosicao4[2]){
    for(int i = 0; i < 10; i++){
        for(int j = 10; j >= 0; j--){

            if(i == barcoPosicao3[0] && j == barcoPosicao3[1]){
                quadro[i][j] = barco;
                quadro[i+1][j+1] = barco;
                quadro[i+2][j+2] = barco;
            }else if(i == barcoPosicao4[0] && j == barcoPosicao4[1]){
                quadro[i][j] = barco;
                quadro[i+1][j-1] = barco;
                quadro[i+2][j-2] = barco;
            }else if(quadro[i][j] == barco){
                quadro[i][j] = barco;
            }else{
                quadro[i][j] = 0;
            }
        }
    }
}

//função relacionada as posições horizontais e verticais
void horizontal(int barcoPosicao[2], int barcoPosicao2[2]){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(barcoPosicao[0] == i && barcoPosicao[1] == j){
                quadro[i][j] = barco;
                quadro[i][j+1] = barco;
                quadro[i][j+2] = barco;
                j+= 3;
            }else if(barcoPosicao2[0] == i && barcoPosicao2[1] == j){
                quadro[i][j] = barco;
                quadro[i+1][j] = barco;
                quadro[i+2][j] = barco;
            }else if(quadro[i][j] == barco){
                quadro[i][j] = barco;
            }
            else{
                quadro[i][j] = 0;
            }

        }
    }
}
//função da habilidade do cone
void cone(int conePosicao[2]){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(i == conePosicao[0] && j == conePosicao[1]){
                quadro[i-1][j] = habilidades;
                quadro[i][j] = habilidades;
                quadro[i][j-1] = habilidades;
                quadro[i][j+1] = habilidades;
                quadro[i+1][j] = habilidades;
                quadro[i+1][j+1] = habilidades;
                quadro[i+1][j+2] = habilidades;
                quadro[i+1][j-1] = habilidades;
                quadro[i+1][j-2] = habilidades;
            }else if(quadro[i][j] == habilidades){
                quadro[i][j] = habilidades;
            }else if(quadro[i][j] == barco){
                quadro[i][j] == barco;
            }
            else{
                quadro[i][j] = 0;
            }
        }
    }
}

//função da habilidade de cruz
void cruz(int cruzPosicao[2]){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(i == cruzPosicao[0] && j == cruzPosicao[1]){
                quadro[i-1][j] = habilidades;
                quadro[i][j] = habilidades;
                quadro[i][j-1] = habilidades;
                quadro[i][j-2] = habilidades;
                quadro[i][j+1] = habilidades;
                quadro[i][j+2] = habilidades;
                quadro[i+1][j] = habilidades;
            }else if(quadro[i][j] == habilidades){
                quadro[i][j] = habilidades;
            }else if(quadro[i][j] == barco){
                quadro[i][j] == barco;
            }
            else{
                quadro[i][j] = 0;
            }
        }
    }
}

//função da habilidade do octaedro
void octaedro(int octaedroPosicao[2]){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(i == octaedroPosicao[0] && j == octaedroPosicao[1]){
                quadro[i-1][j] = habilidades;
                quadro[i][j] = habilidades;
                quadro[i][j-1] = habilidades;
                quadro[i][j+1] = habilidades;
                quadro[i+1][j] = habilidades;
            }else if(quadro[i][j] == habilidades){
                quadro[i][j] = habilidades;
            }else if(quadro[i][j] == barco){
                quadro[i][j] == barco;
            }
            else{
                quadro[i][j] = 0;
            }
        }
    }
}


int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    //posições horizontais e verticais que o barco terá na matriz
    int barcoPosicao[2] = {0,2};
    int barcoPosicao2[2] = {2,2};

    //posições diagonais que o barco terá
    int barcoPosicao3[2] = {3,5};
    int barcoPosicao4[2] = {7,5};

    int conePosicao[2] = {6,2};
    int cruzPosicao[2] = {8,7};
    int octaedroPosicao[2] = {1,8};

    diagonal(barcoPosicao3, barcoPosicao4);
    horizontal(barcoPosicao, barcoPosicao2);
    
    cone(conePosicao);
    cruz(cruzPosicao);
    octaedro(octaedroPosicao);
    
    //por fim, tudo é imprimido
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            printf("%d ", quadro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
