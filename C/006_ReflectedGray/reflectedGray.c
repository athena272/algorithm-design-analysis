/*
A função binary_reflected_gray recebe um inteiro bits, que representa o número de bits que cada código de Gray terá.

A variável n é calculada como 1 deslocado para bits posições, o que corresponde ao número de códigos possíveis.

O loop for é executado n vezes para gerar cada código de Gray.

Dentro do loop, a variável gray é calculada usando o operador ^ (ou exclusivo) para gerar o código de Gray a partir do índice atual do loop.

Em seguida, a variável reflected_gray é inicializada como 0.

Um segundo loop for é executado bits vezes para inverter os bits do código de Gray na posição j e armazená-los na variável reflected_gray.

*/

#include <stdio.h>

/* Gera uma sequência de código de Gray binário refletido */
void binary_reflected_gray(int bits)
{
    int i, j;
    int n = 1 << bits; // Calcula o número de códigos possíveis
    for (i = 0; i < n; i++)
    {
        int gray = i ^ (i >> 1); // Gera o código de Gray
        int reflected_gray = 0;  // Inicializa o valor do código binário refletido
        for (j = 0; j < bits; j++)
        {
            reflected_gray |= ((gray >> j) & 1) << (bits - j - 1); // Inverte os bits na posição j
        }
        printf("%d\n", reflected_gray);
    }
}

int main()
{
    binary_reflected_gray(3);
    return 0;
}
