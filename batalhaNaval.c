#include <stdio.h>
#include <stdbool.h>

#include <stdlib.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

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

    int quadro[10][10];

    int i;
    int j;

    //numero de atribuição do barco
    int barco = 3;
    
    //booleanos de posições
    bool diagonal = false;
    bool horizontal = true;

    //posições horizontais e verticais que o barco terá na matriz
    int barcoPosicao[2] = {0,2};
    int barcoPosicao2[2] = {2,2};

    //posições diagonais que o barco terá
    int barcoPosicao3[2] = {3,5};
    int barcoPosicao4[2] = {7,5};

    //Atribuição das posições das matrizes
    /*
    EXPLICAÇÃO:

    A matriz quadro será percorrida com [i] representando a linha e [j] as colunas
    
    segundo a matriz barcoPosicao com o valor da posição inicial, será comparada aonde i e j estão, e assim associa 
    o numero 3 da variável barco nessa posição 

    */
    for(i = 0; i < 10; i++){
        for(j = 0; j < 10; j++){
            if(barcoPosicao[0] == i && barcoPosicao[1] == j && horizontal == true){
                quadro[i][j] = barco;
                quadro[i][j+1] = barco;
                quadro[i][j+2] = barco;
                j+= 3; // j pulará 3 colunas para que não haja sobreposição dos algarismos subsequentes 
                horizontal = false;
            }else if(barcoPosicao2[0] == i && barcoPosicao2[1] == j && horizontal == false){
                quadro[i][j] = barco;
                quadro[i+1][j] = barco;
                quadro[i+2][j] = barco;
            }else if(quadro[i][j] == barco){
                quadro[i][j] = barco; // o objetivo deste código é mais uma vez manter a integridade dos algarismos em que barco se encontra
            }
            else{
                quadro[i][j] = 0;
            }

    }
}
    /*
    este laço for percorrerá a matriz de forma diferente do anterior, com o objetivo de representar as diagonais
    */
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
    //por fim, tudo é imprimido
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            printf("%d ", quadro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
