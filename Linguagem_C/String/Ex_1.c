/*) Faça um programa que leia 10 nomes, ordene-os de
forma crescente e mostre-os na tela.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>


int main() {
    setlocale(LC_ALL,"Portuguese");

    char nomes[10][40];
    int i = 0, j = 0;

    while (i < 10)
    {
        printf("Digite o %d nome:", i + 1);
        fgets(nomes[i],40,stdin);
        nomes[i][strcspn(nomes[i], "\n")] = '\0';
        i++;
    }  

    for (i = 0; i < 9; i++)
{
    for (j = i + 1; j < 10; j++)
    {
        if (strcmp(nomes[i], nomes[j]) > 0)
        {
            char temporario[40];

            strcpy(temporario, nomes[i]);
            strcpy(nomes[i], nomes[j]);
            strcpy(nomes[j], temporario);
        }
    }
}

    for (i = 0; i < 10; i++)
{
    printf("\n%s", nomes[i]);
}

    return 0;
}
