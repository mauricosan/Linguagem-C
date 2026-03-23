/*Em geometria analítica, dois vetores podem ser definidos como a=<a1,a2,a3> e
b=<b1,b2,b3>. Escreva um programa que leia dois vetores (a e b) de três posições
cada e efetue o produto escalar entre eles. O produto escalar é obtido por ab =
a1b1+a2b2+a3b3. De acordo com o exemplo dado abaixo, o calculo a ser efetuado
será: 1x5+4x2+7x3*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vetor_a[3], vetor_b[3], vetor_c[3];
    int i = 0;
    int soma = 0;

    while (i < 3)
    {
        printf("Preencha o %d° valor do vetor A:  ", i+1);
        scanf("%d", &vetor_a[i]);
        i++;
    }

    for (i = 0; i < 3; i++)
    {
        printf("Preencha o %d° valor do vetor B:  ", i+1);
        scanf("%d", &vetor_b[i]);
        
    }

    i = 0;

    while (i < 3)
    {
        vetor_c[i] = vetor_a[i] * vetor_b[i];
        soma = soma + vetor_c[i];
        i++;
    }

    printf("\n[%d]", soma);

    return 0;
}

