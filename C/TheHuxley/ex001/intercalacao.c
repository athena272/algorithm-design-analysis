#include <stdio.h>
#include <stdlib.h>

int main() {
    int n1, n2, i, j, k;
    scanf("%d", &n1);
    scanf("%d", &n2);
    
    // Aloca memória para as listas L1 e L2
    int *L1 = (int *) malloc(n1 * sizeof(int));
    int *L2 = (int *) malloc(n2 * sizeof(int));
    
    // Leitura dos elementos de L1
    for (i = 0; i < n1; i++) {
        scanf("%d", &L1[i]);
    }
    
    // Leitura dos elementos de L2
    for (i = 0; i < n2; i++) {
        scanf("%d", &L2[i]);
    }
    
    // Aloca memória para a lista L
    int *L = (int *) malloc((n1 + n2) * sizeof(int));
    
    // Merge de L1 e L2 em L
    i = j = k = 0;
    while (i < n1 && j < n2) {
        if (L1[i] < L2[j]) {
            L[k++] = L1[i++];
        } else {
            L[k++] = L2[j++];
        }
    }
    
    // Completa L com os elementos restantes de L1 ou L2
    while (i < n1) {
        L[k++] = L1[i++];
    }
    while (j < n2) {
        L[k++] = L2[j++];
    }
    
    // Imprime os elementos de L
    for (i = 0; i < n1 + n2; i++) {
        printf("%d\n", L[i]);
    }
    
    // Libera a memória alocada
    free(L1);
    free(L2);
    free(L);
    
    return 0;
}
