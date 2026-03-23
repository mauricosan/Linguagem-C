/*3) Faça um programa que receba uma palavra e
verifique se ela é um palíndromo, ou seja, se escrita
do fim para o começo é igual à palavra escrita do
começo para o fim. Exemplo: RENNER, ANA,
MIRIM, OVO, etc.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

int main (){
    setlocale(LC_ALL,"Portuguese");

    char palavra[25], palavra_invertida[25];
    int j = 0, i;

    printf("Digite uma palavra: ");
    fgets(palavra, 25, stdin);

    char letra [2], novos_nomes[10][40];

    palavra[strcspn(palavra, "\n")] = '\0';

    int tamanho = strlen(palavra);
    i = tamanho -1;

    while (i >= 0)
    {
        palavra_invertida[j] = palavra[i];
        j++;
        i--;
    }
    palavra_invertida[j] = '\0';

    printf("\n%s", palavra);
    printf("\n%s", palavra_invertida);

    if (strcmp(palavra,palavra_invertida) == 0)
    {
        printf("\neh Palindromo");
    }
    else{
        printf("\neh Palindromo");
    }
    

    return 0;
}
