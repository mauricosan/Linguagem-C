//3- Crie um programa que preencha uma matriz 3x3 de 
//números inteiros e verifique se a matriz é simétrica.
//A matriz será simétrica se e somente se todoelemento 
//A[i,j] = A[j,i]. Segue um exemplo de matriz simétrica:

#include <stdio.h>
#include <stdlib.h>

int main() {
    int A[3][3];
    int i = 0, j;
    int simetrik = 1;

  
    while (i < 3) {
        j = 0;
        while (j < 3) {
            printf("Digite A[%d][%d]: ", i, j);
            scanf("%d", &A[i][j]);
            j++;
        }
        i++;
    }
  
    i = 0;
    while (i < 3) {
        j = 0;
        while (j < 3) {
            if (A[i][j] != A[j][i]) {
                simetrik = 0;
            }
            j++;
        }
        i++;
    }

    if (simetrik == 1)
        printf("A matriz eh simetrica.\n");
    else
        printf("A matriz NAO eh simetrica.\n");

    return 0;
}