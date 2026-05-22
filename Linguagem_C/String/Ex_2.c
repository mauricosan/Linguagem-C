/*2) Altere o programa 1) para imprimir todos os nomes
que contenham uma letra qualquer fornecida pelo
usuário.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>


int main() {
    setlocale(LC_ALL,"Portuguese");

    char nomes[10][40];
    char letra [2], novos_nomes[10][40];

    int i = 0, j = 0, k = 0;

    while (i < 10)
    {
        printf("\nDigite o %d nome:", i + 1);
        fgets(nomes[i],40,stdin);
        nomes[i][strcspn(nomes[i], "\n")] = '\0';
        i++;
    }

    printf("\nDigite uma letra: ");
    fgets(letra,2,stdin);
    letra[strcspn(letra, "\n")] = '\0';

    for (i = 0; i < 10; i++)
    {
        int achou = 0;
        for (j = 0; nomes[i][j] != '\0'; j++)
        {
            if (nomes[i][j] == letra[0])
            {
            achou = 1;
            }
        }
        if (achou)
        {
            strcpy(novos_nomes[k], nomes[i]);
            k++;
        }

    }
    
    for (i = 0; i < k ; i++)
    {
        printf("%s\n" , novos_nomes[i]);
        
    }
}
