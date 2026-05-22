/*Pratique a declaração e a utilização de
ponteiros para referenciar os elementos de
um vetor. – defina um vetor de 10 elementos inteiros – defina um ponteiro para inteiro
– preencha o vetor usando o ponteiro definido para
referenciar cada posição do vetor – imprima os elementos do vetor usando o ponteiro*/

#include <stdio.h>

int main()
{
    int vetor[10], i, *pvet;

    for (i = 0; i <= 9; i++)
    {
        printf("Digite o %dº número: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    pvet = vetor;

    for (i = 0; i <= 9; i++)
    {
        printf("%d ", *pvet);

        pvet++;
    }
    
    return 0;
}
