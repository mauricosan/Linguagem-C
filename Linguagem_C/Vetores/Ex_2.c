//2- Faça um programa que preencha dois vetores A e B com dez 
//elementos numéricos cada um calcule e apresente umvetor C 
//resultante da intercalação deles. Por exemplo:

#include <stdlib.h>
#include <stdio.h>

int main() {

    int A[10], B[10], C[20];
    int i, k = 0;

    for (i = 0; i < 10; i++) {
        printf("A[%d]: ", i);
        scanf("%d", &A[i]);
    }

    for (i = 0; i < 10; i++) {
        printf("B[%d]: ", i);
        scanf("%d", &B[i]);
    }

    for (i = 0; i < 10; i++) {
        C[k++] = A[i];
        C[k++] = B[i];
    }

    printf("\nVetor C:\n");
    for (i = 0; i < 20; i++) {
        printf("%d ", C[i]);
    }

    return 0;
}