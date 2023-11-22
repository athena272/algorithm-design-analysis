#include <stdio.h>

#define MAX_N 100
#define MAX_M 100

int n, m;                         // dimensões do labirinto
char labirinto[MAX_N][MAX_M + 1]; // matriz que representa o labirinto
int visitado[MAX_N][MAX_M];       // matriz que marca os locais já visitados

int resolver(int linha, int coluna)
{
    // Se a posição estiver fora do labirinto ou for uma parede, retorna 0
    if (linha < 0 || linha >= n || coluna < 0 || coluna >= m || labirinto[linha][coluna] == '#')
    {
        return 0;
    }
    // Se já visitou a posição, retorna 0
    if (visitado[linha][coluna])
    {
        return 0;
    }
    // Se chegou no canto inferior direito, retorna 1
    if (linha == n - 1 && coluna == m - 1)
    {
        return 1;
    }
    // Marca a posição como visitada
    visitado[linha][coluna] = 1;
    // Chama a função recursivamente para todas as posições adjacentes
    if (resolver(linha - 1, coluna) || resolver(linha + 1, coluna) || resolver(linha, coluna - 1) || resolver(linha, coluna + 1))
    {
        return 1; // se pelo menos uma das chamadas retornar 1, retorna 1
    }
    return 0; // se não encontrou a saída, retorna 0
}

int main()
{
    // Lê as dimensões do labirinto
    scanf("%d%d", &n, &m);
    // Lê o labirinto
    for (int i = 0; i < n; i++)
    {
        scanf("%s", labirinto[i]);
    }
    // Chama a função resolver a partir da posição inicial (0, 0)
    if (resolver(0, 0))
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
    return 0;
}

