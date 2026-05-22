/*Faça uma função que receba um valor n e crie dinamicamente um vetor de n elementos inteiros e retorne um ponteiro. Em seguida, crie uma função que receba um ponteiro para um vetor e um valor n e imprima os n elementos desse vetor. Construa também uma função que receba um ponteiro para um vetor e libere esta área de memória. Por fim, crie uma função principal que leia um valor n e chame a função de alocação de memória. Depois, a função principal deve ler os n elementos desse vetor. Então, a função principal deve chamar a função de impressão dos n elementos do vetor criado e, finalmente, liberar a memória alocada através dafunção criada para liberação.*/

#include <stdio.h>
#include <stdlib.h>

int *dinamic(int n)
{
    int *vetor;

    vetor = (int*) malloc(n * sizeof(int));

    if (vetor == NULL)
    {
        printf("Memoria insuficiente");
        exit(1);
    }

    return vetor;
}

void impressao(int *vetor, int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        printf("[%d] ", vetor[i]);
    }
}

void liberar(int *vetor)
{
    free(vetor);
}

int main()
{
    int n, i;
    int *vetor;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    vetor = dinamic(n);

    for (i = 0; i < n; i++)
    {
        printf("Digite o %d numero: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    impressao(vetor, n);

    liberar(vetor);

    return 0;
}


