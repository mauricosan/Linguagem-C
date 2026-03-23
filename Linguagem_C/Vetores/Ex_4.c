//4- Faça um programa que crie uma matriz A detamanho n x n de 
//valores inteiros informados pelousuário. O programa deverá verificar se A é uma matrizidentidade e 
//imprimir uma  mensagem informando ousuário. Considere que a matriz identidade possui
//todos os elementos da diagonal principal iguais a 1 eos demais elementos iguais a 0, como no exemplo:

#include <stdio.h>

int main() {
    int n;
    int identi = 1;

    printf("Digite o tamanho da matriz: ");
    scanf("%d", &n);

    int A[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Digite A[%d][%d]: ", i, j);
            scanf("%d", &A[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            if (i == j && A[i][j] != 1) {
                identi = 0;
            }

            if (i != j && A[i][j] != 0) {
                identi = 0;
            }
        }
    }

    if (identi == 1)
        printf("A matriz é identidade.\n");
    else
        printf("A matriz não é identidade.\n");

    return 0;
}