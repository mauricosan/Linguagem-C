/*1- Faça um programa que preencha vetor com oito números inteiros, calcule e mostre dois vetores resultantes. Oprimeiro vetor deve conter os números positivos e osegundo deve conter os números negativos. Atenção:
cada vetor terá no máximo oito posições, que podemnão ser completamente usadas. Não deve haverposições vazias entre dois valores. Por exemplo:*/

#include <stdio.h>

int main()
{

    int vetorprinci[8], vetorpos[8], vetorneg[8];
    int i = 0;
    int j, k;

    for (i = 0; i < 8; i++)
    {
        printf("Digite um número: ");
        scanf("%d", &vetorprinci[i]);
    }

    for (i = 0; i < 8; i++)
    {
        if (vetorprinci[i] < 0)
        {
            vetorneg[j] = vetorprinci[i];
            j++;
        }

        else {
            vetorpos [k] = vetorprinci[i];
            k++;
        }
        
    }

    printf("\nVetor Principal: \n");
    for ( i = 0; i < 8; i++)
    {
        printf("[%d] ", vetorprinci[i]);
    }

    printf("\nVetor Positivo: \n");
    for (i = 0; i < k; i++)
    {
        printf("[%d] ", vetorpos[i]);
    }

    printf("\nVetor Negativo: \n");
    for (i = 0; i < j; i++)
    {
        printf("[%d] ", vetorneg[i]);
    }
    
    
    return 0;
}
